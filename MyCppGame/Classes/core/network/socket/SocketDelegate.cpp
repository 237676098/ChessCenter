#include "SocketDelegate.h"
NS_CORE_BEGIN

SocketDelegate::SocketDelegate()
{
}

SocketDelegate::~SocketDelegate()
{
	
}

void SocketDelegate::onConnect(SIOClient* client)
{
	SocketIO::SIODelegate::onConnect(client);
}

void SocketDelegate::onMessage(SIOClient * client, const std::string & data)
{
	SocketIO::SIODelegate::onMessage(client,data);
}

void SocketDelegate::onError(SIOClient * client, const std::string & data)
{
	CCLOG("socket error:%s",data.c_str());
}

void SocketDelegate::onClose(SIOClient * client)
{
	CCLOG("socket closed!");
}

NS_CORE_END