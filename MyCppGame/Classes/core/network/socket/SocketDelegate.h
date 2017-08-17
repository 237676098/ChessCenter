#pragma once
#include "network\SocketIO.h"
#include "utils\CommonMacros.h"

using namespace cocos2d::network;
NS_CORE_BEGIN
class SocketDelegate :public SocketIO::SIODelegate
{
public:
	SocketDelegate();
	~SocketDelegate();

	//socket连接时调用
	void onConnect(SIOClient* client);
	//收到数据时调用
	void onMessage(SIOClient* client, const std::string& data);
	//连接错误或接收到错误信号时调用
	void onError(SIOClient* client, const std::string& data);
	//socket关闭时调用
	void onClose(SIOClient* client);

private:

};
NS_CORE_END