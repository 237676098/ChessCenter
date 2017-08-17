#include "SocketManager.h"
#include "SocketDelegate.h"
NS_CORE_BEGIN
void SocketManager::send(google::protobuf::Message* msg)
{

}
void SocketManager::connect(std::string ip, std::string port)
{
	CCASSERT(m_delegate, "only surpport one tcp connection!");
	m_ip = ip;
	m_port = port;
	m_delegate = new SocketDelegate();
	SocketIO::connect(m_ip + ":" + m_port, *m_delegate);
}
void SocketManager::disconnect()
{

}

//收到数据的时候进行数据的解析
void SocketManager::handleMessage(const std::string & data)
{

}
NS_CORE_END