#ifndef __SOCKET_MANAGER_H__
#define __SOCKET_MANAGER_H__
#include <functional>
#include "PacketBuffer.h"
#include "cocos2d.h"

NS_CORE_BEGIN

typedef std::function<void(google::protobuf::Message*)> FuncMessageHandler;
typedef std::function< void(void)> FuncSocketClose;
typedef std::function< void(void)> FuncSocketConnected;
typedef std::function< void(void)> FuncSocketError;

typedef std::map<uint16, std::vector<FuncMessageHandler>*> HandlerMap;

class SocketManager:cocos2d::Ref
{
	SINGLETON(SocketManager)
public:
	int sendMessage(MessageId msg_id,const google::protobuf::Message& message);
	void Connect(std::string ip, uint16 port);
	void disconnect();
	bool isConnected() const;
	inline void setCloseFunc(FuncSocketClose func) { m_func_close = func; };
	inline void setConnectedFunc(FuncSocketConnected func) { m_func_connected = func; };
	inline void setErrorFunc(FuncSocketError func) { m_func_error = func; };
	void registerHandler(MessageId msg_id, FuncMessageHandler handler);
	virtual void onClosed();
	virtual void onConnected();
	virtual void onConnectError();
private:
	uint16 generateId();
	int sendPacket(const Packet& packet);
	void dispatch();
	void update(float dt);
private:
	static uint16 s_serial_number;
	std::string m_ip;
	uint16 m_port;
	bool m_bConnect;
	char* m_bufTemp;
	PacketBuffer* 	m_packetBuffer;
	FuncSocketClose m_func_close;
	FuncSocketConnected m_func_connected;
	FuncSocketError m_func_error;

	HandlerMap m_handlers;
};

NS_CORE_END

#endif