#include "LoginManager.h"
#include "LoginManager.h"
#include "cocos2d.h"

USING_NS_CHESS;
NS_LOGIN_BEGIN

void LoginManager::init()
{
	if (!m_view) {
		m_view = LoginView::create();
		m_view->setPosition( cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width / 2, cocos2d::Director::getInstance()->getVisibleSize().height / 2));
	}
	core::SceneManager::getInstance()->add(core::LayerMainUI, m_view);
}

void LoginManager::dispose()
{
	if (m_view)
	{
		core::SceneManager::getInstance()->remove(core::LayerMainUI, m_view);
	}
	m_view = nullptr;
}

NS_LOGIN_END