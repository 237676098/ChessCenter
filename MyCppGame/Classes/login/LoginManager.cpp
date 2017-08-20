#include "LoginManager.h"
#include "core\scene\scene.h"
#include "core\network\socket\SocketManager.h"

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
	//·¢ËÍÐÄÌø°ü
	proto3_proto::Ack ack;
	ack.set_status(1);
	core::SocketManager::getInstance()->sendMessage(core::ID_Ack,ack);
}

void LoginManager::onRevAck(google::protobuf::Message * messgae)
{
	proto3_proto::Ack* ack = dynamic_cast<proto3_proto::Ack*>(messgae);

	CCLOG("recive ack status is %d", ack->status());
}

NS_LOGIN_END