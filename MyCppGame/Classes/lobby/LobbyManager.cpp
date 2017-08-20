#include "LobbyManager.h"

NS_LOBBY_BEGIN

LobbyManager::LobbyManager() :m_view(nullptr)
{

}

LobbyManager::~LobbyManager()
{

}

void LobbyManager::init()
{
	if (!m_view) {
		m_view = LobbyView::create();
		m_view->fullScreen();
		m_view->setPosition(g_center);
		core::SceneManager::getInstance()->add(core::LayerMainUI, m_view);
	}
}

void LobbyManager::dispose()
{
	if (m_view)
	{
		core::SceneManager::getInstance()->remove(core::LayerMainUI, m_view);
	}
	m_view = nullptr;
}


NS_LOBBY_END
