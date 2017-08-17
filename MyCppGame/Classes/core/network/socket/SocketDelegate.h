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

	//socket����ʱ����
	void onConnect(SIOClient* client);
	//�յ�����ʱ����
	void onMessage(SIOClient* client, const std::string& data);
	//���Ӵ������յ������ź�ʱ����
	void onError(SIOClient* client, const std::string& data);
	//socket�ر�ʱ����
	void onClose(SIOClient* client);

private:

};
NS_CORE_END