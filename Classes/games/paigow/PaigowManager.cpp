#include "PaigowManager.h"
#include "core/scene/scene.h"

NS_PAIGOW_BEGIN

PaigowManager::PaigowManager() :m_view(nullptr)
{

}

PaigowManager::~PaigowManager()
{

}

void PaigowManager::init()
{
	if (!m_view) {
		m_view = PaigowTableView::create();
		m_view->fullScreen();
		m_view->setPosition(g_center);
		core::SceneManager::getInstance()->add(core::LayerMainUI, m_view);

		m_wait_operate_view = PaiGowWaitOperateView::create();
		m_wait_operate_view->setPosition(cocos2d::Vec2(g_win_size.width/2,120));
		core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_wait_operate_view);
	
		m_seat_view = PaiGowSeatView::create();
		m_seat_view->setPosition(cocos2d::Vec2(170, 125));
		core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_seat_view);

		m_bet_operate_view = PaigowBetOperateView::create();
		m_bet_operate_view->setPosition(cocos2d::Vec2(g_win_size.width / 2, 80));
		core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_bet_operate_view);
	}
}

void PaigowManager::dispose()
{
	if (m_view)
	{
		core::SceneManager::getInstance()->remove(core::LayerMainUI, m_view);
	}
	m_view = nullptr;
}

NS_PAIGOW_END
