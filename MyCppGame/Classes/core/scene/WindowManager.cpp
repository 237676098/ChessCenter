#include "WindowManager.h"
#include "SceneManager.h"

NS_CORE_BEGIN
//SINGLETON_C_D(WindowManager)

WindowManager::WindowManager()
{
}

WindowManager::~WindowManager()
{
}



bool WindowManager::isOpen(WindowId windowId)
{
	if (m_windows.find(windowId) == m_windows.end())
	{
		return false;
	}else
	{
		return m_windows[windowId].state == WindowOpen;
	}
}

IBaseWindow * WindowManager::getWindow(WindowId windowId)
{
	return nullptr;
}

void WindowManager::close(WindowId id)
{
	if (m_windows.find(id) == m_windows.end())
	{
		return;
	}

	if (!(m_windows[id].window))
	{
		return;
	}

	core::SceneManager::getInstance()->remove(core::LayerPopWindow,m_windows[id].window);
	m_windows[id].window = nullptr;
	m_windows[id].state = WindowClose;
}

void WindowManager::insertWindow(IBaseWindow * wnd, int id)
{
	if (wnd && wnd->init())
	{
		wnd->autorelease();
		wnd->setPosition(cocos2d::Vec2(cocos2d::Director::getInstance()->getWinSize().width / 2, cocos2d::Director::getInstance()->getWinSize().height / 2));
		core::SceneManager::getInstance()->add(core::LayerPopWindow, wnd);
		m_windows[id].state = WindowOpen;
		m_windows[id].window = wnd;
	}
}

NS_CORE_END
