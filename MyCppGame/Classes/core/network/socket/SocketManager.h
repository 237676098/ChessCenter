#pragma once
#include <functional>
#include "utils\CommonMacros.h"
#include "google\protobuf\message.h"
#include "network\SocketIO.h"


using namespace cocos2d::network;
NS_CORE_BEGIN
class SocketDelegate;
typedef std::function< void(void)> FuncSocketClose;
typedef std::function< void(void)> FuncSocketConnected;
typedef std::function< void(void)> FuncSocketError;


class SocketManager
{
	SINGLETON(SocketManager)
public:
	void send(google::protobuf::Message* msg);
	void connect(std::string ip,std::string port);
	void disconnect();
	inline void setCloseFunc(FuncSocketClose func) { m_func_close = func; };
	inline void setConnectedFunc(FuncSocketConnected func) { m_func_connected = func; };
	inline void setErrorFunc(FuncSocketError func) { m_func_error = func; };

private:
	void handleMessage(const std::string& data);
private:
	std::string m_ip;
	std::string m_port;
	SocketDelegate* m_delegate;
	FuncSocketClose m_func_close;
	FuncSocketConnected m_func_connected;
	FuncSocketError m_func_error;
};

NS_CORE_END