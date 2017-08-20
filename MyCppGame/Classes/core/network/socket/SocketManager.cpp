#include "SocketManager.h"
#include "core\network\protocol\test.pb.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//For Windows
#include <WinSock2.h>
#include <Ws2tcpip.h>
#pragma comment(lib,"Ws2_32.lib")
#else
//For iOS Android Linux
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#endif

USING_NS_CC;
NS_CORE_BEGIN

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
SOCKET	sClient;
#else
int sClient;
#endif

uint16 SocketManager::s_serial_number = 0;

SocketManager::SocketManager() 
	:m_ip(""),
	m_port(0), 
	m_bConnect(false), 
	m_func_close(nullptr),
	m_func_connected(nullptr),
	m_func_error(nullptr)
{
	m_bufTemp = new char[PACKET_MAX];
	m_packetBuffer = new PacketBuffer();
}

SocketManager::~SocketManager()
{
	if (isConnected())
	{
		disconnect();
	}

	delete m_packetBuffer;
	delete m_bufTemp;

}

void SocketManager::registerHandler(MessageId msg_id, FuncMessageHandler handler)
{
	if (m_handlers.find(msg_id) == m_handlers.end())
	{
		m_handlers[msg_id] = new std::vector<FuncMessageHandler>();
	}

	m_handlers[msg_id]->push_back(handler);
}

void SocketManager::onClosed()
{
	//连接断开之前将接收到的消息清空
	dispatch();
	m_bConnect = false;
	s_serial_number = 0;
	if (m_func_close)
	{
		m_func_close();
	}
}

void SocketManager::onConnected()
{
	m_bConnect = true;
	if (m_func_connected)
	{
		m_func_connected();
	}
}

void SocketManager::onConnectError()
{
	m_bConnect = false;
	s_serial_number = 0;
	if (m_func_error)
	{
		m_func_error();
	}
}

int SocketManager::sendMessage(MessageId msg_id, const google::protobuf::Message& message)
{
	if (!isConnected())
	{
		return -1;
	}

	std::string tmpStr;
	message.SerializeToString(&tmpStr);
	uint32 b_size = tmpStr.size();

	Packet packet;
	packet.writeUint32(b_size);
	packet.writeUint16(generateId());
	packet.writeUint32(msg_id);
	packet.writeBytes(tmpStr.c_str(), b_size);
	int result = sendPacket(packet);
	return result;
}

uint16 SocketManager::generateId()
{
	s_serial_number++;
	return s_serial_number;
}

int SocketManager::sendPacket(const Packet& packet)
{
	if (!isConnected())
	{
		return -1;
	}
	int result = send(sClient, packet.m_body, packet.m_nLen, 0);
	if (-1 == result)
	{
		result = -1;
		onClosed();
	}
	return result;
}
void SocketManager::Connect(std::string ip, unsigned short port)
{
	if (m_bConnect)
	{
		CCLOG("socket has conencted!");
		return;
	}

	m_ip = ip;
	m_port = port;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	WSADATA wsaData;

	WSAStartup(MAKEWORD(2, 2), &wsaData);
	sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
#else
	sClient = socket(AF_INET, SOCK_STREAM, 0);
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	if (INVALID_SOCKET == sClient)
#else
	if (-1 == sClient)
#endif
	{
		return;
	}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

	SOCKADDR_IN	 addrServ;
	addrServ.sin_family = AF_INET;

	HOSTENT *host_entry;
	host_entry = gethostbyname(m_ip.c_str());
	char hostip[20];
	if (host_entry != 0)
	{
		CCLOG("解析IP地址: ");

		sprintf(hostip, "%d.%d.%d.%d",
			(host_entry->h_addr_list[0][0] & 0x00ff),
			(host_entry->h_addr_list[0][1] & 0x00ff),
			(host_entry->h_addr_list[0][2] & 0x00ff),
			(host_entry->h_addr_list[0][3] & 0x00ff));
	}

	addrServ.sin_addr.s_addr = inet_addr((const char*)hostip);
	addrServ.sin_port = htons(m_port);
	int retVal = connect(sClient, (LPSOCKADDR)&addrServ, sizeof(SOCKADDR_IN));
#else
	struct sockaddr_in addrServ;
	addrServ.sin_family = AF_INET;
	addrServ.sin_port = htons(port);

	struct hostent *h;
	if ((h = gethostbyname(host.c_str())) == NULL)
	{
		CCLog("不能得到IP\n");
		return false;
	}
	CCLog("HostName :%s\n", h->h_name);
	CCLog("IP Address :%s\n", inet_ntoa(*((struct in_addr *)h->h_addr)));

	addrServ.sin_addr.s_addr = inet_addr(inet_ntoa(*((struct in_addr *)h->h_addr)));

	int retVal = connect(sClient, (struct sockaddr *)&addrServ, sizeof(addrServ));
#endif
	if (-1 == retVal)
	{
		onConnectError();
		return;
	}
	onConnected();
	Director::getInstance()->getScheduler()->schedule(schedule_selector(SocketManager::update), this, 0, false);
	return;

}
void SocketManager::disconnect()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	closesocket(sClient);
#else
	close(sClient);
#endif
}

bool SocketManager::isConnected() const
{
	return m_bConnect;
}

void SocketManager::update(float dt)
{
	if (!m_bConnect)
	{
		return;
	}

	fd_set rdfds;
	FD_ZERO(&rdfds);
	struct timeval tv;
	tv.tv_sec = 0.0;
	tv.tv_usec = 0;
	FD_SET(sClient, &rdfds);
	int ret = select(sClient + 1, &rdfds, NULL, NULL, &tv);
	if (ret <= 0)
	{
		return;
	}

	int nReadLen = recv(sClient, m_bufTemp, PACKET_MAX, 0);

	if (nReadLen<0)
	{
		return;
	}
	m_packetBuffer->push(m_bufTemp, nReadLen);

	this->dispatch();
}

//收到数据的时候进行数据的解析
void SocketManager::dispatch()
{
	packets ps = m_packetBuffer->getPackets();
	
	for (auto it = ps.begin(); it != ps.end(); it++) {

		
		Packet* p = *it;

		uint32 msg_length = p->readUint32();
		uint16 serial_number = p->readUint16();
		uint32 msg_id = p->readUint32();
		char *tmpBody = new char[1024];

		p->readBytes(msg_length, tmpBody);
		
		if (message_getter_maps.find(msg_id) != message_getter_maps.end())
		{
			proto3_proto::Message* ack = message_getter_maps.at(msg_id)(tmpBody);

			if (m_handlers.find(msg_id) != m_handlers.end())
			{
				std::vector<FuncMessageHandler>* handlers = m_handlers[msg_id];
				for (size_t i = 0; i < handlers->size(); i++)
				{
					(handlers->at(i))(ack);
				}
			}

			//CCLOG("recieve ack---->serial_number:%d msgid:%d status:%d ", serial_number, msg_id, ack->status());
		}

		delete tmpBody;
	}

	ps.clear();

}

NS_CORE_END