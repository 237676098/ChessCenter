#ifndef __LOGIN_MANAGER_H__
#define __LOGIN_MANAGER_H__
#include "LoginView.h"
#include "cocos2d.h"
#include "core\network\socket\protocol.h"

NS_LOGIN_BEGIN
//��¼������  Ϊ������ģ���������� Ŀǰ����������Ҳд��������
class LoginManager :public cocos2d::Ref
{
	SINGLETON(LoginManager)
public:
		void init();
		void enter();
		void exit();

private:
	LoginView* m_view = nullptr;

private:
		void onSocketConnected();
		void onSocketClose();
		void onSocketError();
		void onUpdate(float dt);
		void onRevAck(google::protobuf::Message* messgae);
private:
	static const int m_s_retry_num;
	int m_i_retry_num;
};

NS_LOGIN_END

#endif