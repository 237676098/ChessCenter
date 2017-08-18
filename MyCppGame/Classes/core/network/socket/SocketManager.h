#pragma once
#include <functional>
#include "utils\CommonMacros.h"
#include "google\protobuf\message.h"
#include "Packet.h"
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
	int Send(Packet* packet);
	void Connect(std::string ip, unsigned short port);
	void disconnect();
	inline void setCloseFunc(FuncSocketClose func) { m_func_close = func; };
	inline void setConnectedFunc(FuncSocketConnected func) { m_func_connected = func; };
	inline void setErrorFunc(FuncSocketError func) { m_func_error = func; };
	void registerHandler(uint16 msg_id, FuncMessageHandler handler);
private:
	void dispatch();
	void update(float dt);
private:
	std::string m_ip;
	unsigned short m_port;
	bool m_bConnect;
	char* m_bufTemp;
	PacketBuffer* 	m_packetBuffer;
	FuncSocketClose m_func_close;
	FuncSocketConnected m_func_connected;
	FuncSocketError m_func_error;

	HandlerMap m_handlers;
};

NS_CORE_END