#include "LoginManager.h"
#include "LoginManager.h"
#include "cocos2d.h"
#include "core\scene\scene.h"

USING_NS_CHESS;
NS_LOGIN_BEGIN
SINGLETON_C_D(LoginManager)
void LoginManager::init()
{
	if (!m_view) {
		m_view = LoginView::create();
		m_view->fullScreen();
		m_view->setPosition(g_center);
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