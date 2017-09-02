#include "LoginManager.h"
#include "core/scene/scene.h"
#include "user/user.h"
#include "core/network/socket/SocketManager.h"
#include "user/UserManager.h"


USING_NS_CHESS;
NS_LOGIN_BEGIN

const int LoginManager::m_s_retry_num = 5;

LoginManager::LoginManager() 
	:m_view(nullptr),
	m_i_retry_num(0)
{

}

LoginManager::~LoginManager()
{

}

void LoginManager::init()
{
	core::SocketManager::getInstance()->setConnectedFunc(std::bind(&LoginManager::onSocketConnected,this));
	core::SocketManager::getInstance()->setErrorFunc(std::bind(&LoginManager::onSocketError, this));
	core::SocketManager::getInstance()->setCloseFunc(std::bind(&LoginManager::onSocketClose, this));
	cocos2d::Director::getInstance()->getScheduler()->schedule(schedule_selector(LoginManager::onUpdate), this, 5, false);
	core::SocketManager::getInstance()->registerHandler(core::ID_Ack, std::bind(&LoginManager::onRevAck, this, std::placeholders::_1));
	core::SocketManager::getInstance()->registerHandler(core::ID_S2C_Error, std::bind(&LoginManager::onRevS2C_Error, this, std::placeholders::_1));
	enter();
}

void LoginManager::enter()
{

	if (!m_view) {
		m_view = LoginView::create();
		m_view->fullScreen();
		m_view->setPosition(g_center);
		core::SceneManager::getInstance()->add(core::LayerMainUI, m_view);
	}
}

void LoginManager::exit()
{
	if (m_view)
	{
		core::SceneManager::getInstance()->remove(core::LayerMainUI, m_view);
	}
	m_view = nullptr;
}

void LoginManager::onSocketConnected()
{
	CCLOG("socket connected!");
	//模块初始化 注册网络监听事件
	user::UserManager::getInstance()->init();


	proto3_proto::C2S_Login c2s_login;
	c2s_login.set_uid(user::UserManager::getInstance()->getId());
	c2s_login.set_sign(user::UserManager::getInstance()->getSign());
	core::SocketManager::getInstance()->sendMessage(core::ID_C2S_Login, c2s_login);
}

void LoginManager::onSocketClose()
{
	CCLOG("socket closed!");
}

void LoginManager::onSocketError()
{
	CCLOG("socket error!");
}

void LoginManager::onUpdate(float dt)
{
	if (!core::SocketManager::getInstance()->isConnected())
	{
		return;
	}
	//发送心跳包
	proto3_proto::Ack ack;
	ack.set_status(1);
	//core::SocketManager::getInstance()->sendMessage(core::ID_Ack,ack);
}

void LoginManager::onRevAck(google::protobuf::Message * messgae)
{
	proto3_proto::Ack* ack = dynamic_cast<proto3_proto::Ack*>(messgae);

	CCLOG("recive ack status is %d", ack->status());
}

void LoginManager::onRevS2C_Error(google::protobuf::Message * messgae)
{
	proto3_proto::S2C_Error* s2c_error = dynamic_cast<proto3_proto::S2C_Error*>(messgae);
	core::SceneManager::getInstance()->showMsg(s2c_error->msg());
}

NS_LOGIN_END