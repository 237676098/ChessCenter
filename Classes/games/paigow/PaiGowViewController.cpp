#include "PaiGowViewController.h"
#include "PaigowManager.h"
#include "core/scene/scene.h"
#include "games/paigow/events/paigow_events.h"

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
		m_seat_views.insert(std::make_pair(i,nullptr));
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

	m_view->initView(m_data);

	//添加座位
	for (size_t i = 0; i < 4; i++)
	{
		if (m_data->players[i])
		{
			addSeat(m_data->players[i]);
		}
	}
	

	if (m_data->table_state == TableState::Wait)
	{
		if (!m_wait_operate_view)
		{
			m_wait_operate_view = PaiGowWaitOperateView::create();
			m_wait_operate_view->setPosition(Vec2(g_win_size.width / 2,110));
			core::SceneManager::getInstance()->add(core::LayerMainUIUp,m_wait_operate_view);
			m_wait_operate_view->initView(m_data);
		}
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
		assert("wrong snaptshot state！");
	}


	core::EventManager::Instance().AddEventHandler(core::EVT_PG_AddPlayer,this);
	core::EventManager::Instance().AddEventHandler(core::EVT_PG_DeletePlayer, this);
	core::EventManager::Instance().AddEventHandler(core::EVT_PG_StartGame, this);
	core::EventManager::Instance().AddEventHandler(core::EVT_PG_BankerConfirm,this);
	core::EventManager::Instance().AddEventHandler(core::EVT_PG_Bet, this);
	core::EventManager::Instance().AddEventHandler(core::EVT_PG_OffLine, this);
	core::EventManager::Instance().AddEventHandler(core::EVT_PG_DealCard, this);
	core::EventManager::Instance().AddEventHandler(core::EVT_PG_GrabStatus, this);
}

void PaiGowViewController::dispose()
{
	if (m_view)
	{
		core::SceneManager::getInstance()->remove(core::LayerMainUI, m_view);
		m_view = nullptr;
	}

	if (m_wait_operate_view)
	{
		core::SceneManager::getInstance()->remove(core::LayerMainUIUp, m_wait_operate_view);
		m_wait_operate_view = nullptr;
	}

	if (m_grab_operate_view)
	{
		core::SceneManager::getInstance()->remove(core::LayerMainUIUp, m_grab_operate_view);
		m_grab_operate_view = nullptr;
	}

	if (m_bet_operate_view)
	{
		core::SceneManager::getInstance()->remove(core::LayerMainUIUp, m_bet_operate_view);
		m_bet_operate_view = nullptr;
	}

	
	std::map<uint32_t, PaiGowSeatView*>::iterator iter;

	for (iter = m_seat_views.begin(); iter != m_seat_views.end(); iter++)
	{
		if ((*iter).second != nullptr)
		{
			core::SceneManager::getInstance()->remove(core::LayerMainUI, (*iter).second);
			(*iter).second = nullptr;
		}
	}

}

int PaiGowViewController::HandleEvent(core::Event * evt)
{
	if (evt->id_ == core::EVT_PG_AddPlayer)
	{
		EventAddPlayer* event = (EventAddPlayer*)(evt);
		addSeat(event->player);
	}
	else if(evt->id_ == core::EVT_PG_DeletePlayer)
	{
		EventDeletePlayer* event = (EventDeletePlayer*)(evt);
		deleteSeat(event->seat_id);
	}
	else if (evt->id_ == core::EVT_PG_StartGame)
	{
		EventStartGame* event = (EventStartGame*)(evt);
		if (m_wait_operate_view)
		{
			core::SceneManager::getInstance()->remove(core::LayerMainUIUp, m_wait_operate_view);
			m_wait_operate_view = nullptr;
		}


		m_grab_operate_view = PaigowGrabOperateView::create();
		m_grab_operate_view->setPosition(Vec2(g_win_size.width / 2,100));
		core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_grab_operate_view);
	}
	else if (evt->id_ == core::EVT_PG_GrabStatus)
	{
		EventGrabStatus* event = (EventGrabStatus*)(evt);
		if (event->is_grab)
		{
			m_seat_views[event->seat_id]->setStatus("status_qiang");
		}
		else
		{
			m_seat_views[event->seat_id]->setStatus("status_buqiang");
		}
	}
	else if(evt->id_ == core::EVT_PG_BankerConfirm)
	{
		EventBankerConfirm* event = (EventBankerConfirm*)(evt);
		m_seat_views[event->seat_id]->showBanker();
		

		//销毁上一阶段的ui
		if (m_grab_operate_view)
		{
			core::SceneManager::getInstance()->remove(core::LayerMainUIUp, m_grab_operate_view);
			m_grab_operate_view = nullptr;
		}


		m_bet_operate_view = PaigowBetOperateView::create();
		m_bet_operate_view->setPosition(Vec2(g_win_size.width / 2, 100));
		core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_bet_operate_view);
		//我是庄
		if (m_data->isMainPlayer(event->seat_id))
		{
			m_bet_operate_view->show(true);
		}
		else
		{
			m_bet_operate_view->show(false);
		}
	}
	else if (evt->id_ == core::EVT_PG_Bet)
	{
		EventBet* event = (EventBet*)(evt);
		m_seat_views[event->seat_id]->showBet(event->bet1, event->bet2, betPos(event->seat_id));


	}
	else if (evt->id_ == core::EVT_PG_OffLine)
	{
		EventOffline* event = (EventOffline*)(evt);
		m_seat_views[event->seat_id]->showOffline(event->offline);

	}
	else if(evt->id_ == core::EVT_PG_DealCard)
	{
		//给每个玩家发牌
		std::map<uint32_t, PaiGowPlayer*>::const_iterator iter;
		for (iter = m_data->players.begin(); iter != m_data->players.end(); iter++)
		{
			m_handcards_views[iter->first] = PaiGowHandCardsPanel::create();
			m_handcards_views[iter->first]->setCards(iter->second->hand_cards);
		}


	}

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

void PaiGowViewController::deleteSeat(uint32_t seat_id)
{
	if (m_seat_views.find(seat_id) != m_seat_views.end())
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

	int s_id = m_data->getSeatIndex(player->seat_id);
	CCLOG("seatid:%d   s_id:%d", player->seat_id, s_id);

	switch (s_id)
	{
		case 0:
			return Vec2(130, 100);
		case 1:
			return Vec2(g_win_size.width - 70, g_win_size.height / 2);
		case 2:
			return Vec2(g_win_size.width / 2 - 90, g_win_size.height - 140);
		case 3:
			return Vec2(70, g_win_size.height / 2);
		default:
			break;
	}

	return cocos2d::Vec2(0, 0);
}

cocos2d::Vec2 PaiGowViewController::betPos(PaiGowPlayer * player)
{
	int s_id = m_data->getSeatIndex(player->seat_id);
	CCLOG("seatid:%d   s_id:%d", player->seat_id, s_id);

	switch (s_id)
	{
		case 0:
			return Vec2(110, -45);
		case 1:
			return Vec2(0, -90);
		case 2:
			return Vec2(0, -90);
		case 3:
			return Vec2(0, -90);
		default:
			break;
	}

	return cocos2d::Vec2(0, 0);
}

cocos2d::Vec2 PaiGowViewController::betPos(int seat_id)
{
	return betPos(m_data->players[seat_id]);
}


NS_PAIGOW_END
