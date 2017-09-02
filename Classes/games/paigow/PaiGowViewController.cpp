#include "PaiGowViewController.h"
#include "PaigowManager.h"
#include "core/scene/scene.h"

USING_NS_CC;

NS_PAIGOW_BEGIN

PaiGowViewController::PaiGowViewController(PaiGowSnaptShot* data)
	:m_data(data),
	m_view(nullptr),
	m_wait_operate_view(nullptr),
	m_bet_operate_view(nullptr)
{
	for (size_t i = 0; i < 4; i++)
	{
		m_seat_views.push_back(nullptr);
	}
 
}

void PaiGowViewController::init()
{
	if (!m_view)
	{
		m_view = PaigowTableView::create();
		m_view->fullScreen();
		m_view->setPosition(g_center);
		core::SceneManager::getInstance()->add(core::LayerMainUI, m_view);
	}

	m_view->initView();

	//Ìí¼Ó×ùÎ»
	for (size_t i = 0; i < 4; i++)
	{
		if (m_data->players[i])
		{
			addSeat(m_data->players[i]);
		}
	}
	

	if (m_data->table_state == TableState::Wait)
	{
		
	}
	else if (m_data->table_state == TableState::GrabBanker)
	{

	}
	else if (m_data->table_state == TableState::Bet)
	{

	}
	else if (m_data->table_state == TableState::Collocation)
	{

	}
	else if (m_data->table_state == TableState::Result)
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

void PaiGowViewController::addSeat(PaiGowPlayer * player)
{
	PaiGowSeatView* view = PaiGowSeatView::create();
	view->initView(player);
	Vec2 pos = seatPos(player);
	view->setPosition(pos);

	core::SceneManager::getInstance()->add(core::LayerMainUI, view);
	m_seat_views[player->seat_id] = view;
}

void PaiGowViewController::deleteSeat(int seat_id)
{
	if (m_seat_views[seat_id])
	{
		core::SceneManager::getInstance()->remove(core::LayerMainUI, m_seat_views[seat_id]);
		m_seat_views[seat_id] = nullptr;
	}
}



cocos2d::Vec2 PaiGowViewController::seatPos(int seat_id)
{
	return seatPos(m_data->players[seat_id]);
}

cocos2d::Vec2 PaiGowViewController::seatPos(PaiGowPlayer * player)
{

	switch (player->seat_id)
	{
		case 1:
			return Vec2(g_win_size.width/2, 100);
		case 2:
			return Vec2(g_win_size.width - 290, g_win_size.height / 2);
		case 3:
			return Vec2(g_win_size.width/2 - 90, g_win_size.height -  140);
		case 4:
			return Vec2(g_win_size.width + 290, g_win_size.height / 2);
	default:
		break;
	}

	return cocos2d::Vec2(0, 0);
}

NS_PAIGOW_END
