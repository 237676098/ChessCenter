#include "PaiGowViewController.h"
#include "PaigowManager.h"
#include "core/scene/scene.h"

NS_PAIGOW_BEGIN


PaiGowViewController::PaiGowViewController(PaiGowSnaptShot* data)
	:m_data(data),
	m_view(nullptr),
	m_wait_operate_view(nullptr),
	m_seat_view(nullptr),
	m_bet_operate_view(nullptr)
{
	

}

void PaiGowViewController::init()
{
	/*
	PGST_Wait = 1,
	PGST_GrabBanker,
	PGST_Bet,
	PGST_Collocation,
	PGST_Result,
	PGST_Unkown

	*/



	//if (!m_view) {
	//m_view = PaigowTableView::create();
	//m_view->fullScreen();
	//m_view->setPosition(g_center);
	//core::SceneManager::getInstance()->add(core::LayerMainUI, m_view);

	/*
	m_wait_operate_view = PaiGowWaitOperateView::create();
	m_wait_operate_view->setPosition(cocos2d::Vec2(g_win_size.width/2,120));
	core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_wait_operate_view);

	m_seat_view = PaiGowSeatView::create();
	m_seat_view->setPosition(cocos2d::Vec2(170, 125));
	core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_seat_view);

	m_bet_operate_view = PaigowBetOperateView::create();
	m_bet_operate_view->setPosition(cocos2d::Vec2(g_win_size.width / 2, 80));
	core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_bet_operate_view);
	*/
	//}

	if (!m_view)
	{
		m_view = PaigowTableView::create();
		m_view->fullScreen();
		m_view->setPosition(g_center);
		core::SceneManager::getInstance()->add(core::LayerMainUI, m_view);
	}

	m_view->init();


	if (m_data->table_state == PGST_Wait)
	{

	}
	else if (m_data->table_state == PGST_GrabBanker)
	{

	}
	else if (m_data->table_state == PGST_Bet)
	{

	}
	else if (m_data->table_state == PGST_Collocation)
	{

	}
	else if (m_data->table_state == PGST_Result)
	{

	}
	else
	{
		assert("wrong snaptshot state£¡");
	}

}

int PaiGowViewController::HandleEvent(core::Event * evt)
{
	return 0;
}

NS_PAIGOW_END
