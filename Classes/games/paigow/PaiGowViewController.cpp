#include "PaiGowViewController.h"
#include "PaigowManager.h"
#include "core/scene/scene.h"
#include "games/paigow/events/paigow_events.h"
#include "games/paigow/views/PaiGowResultWindow.h"

USING_NS_CC;

NS_PAIGOW_BEGIN

PaiGowViewController::PaiGowViewController(PaiGowSnaptShot* data)
	:m_data(data),
	m_view(nullptr),
	m_wait_operate_view(nullptr),
	m_grab_operate_view(nullptr),
	m_bet_operate_view(nullptr),
	m_collocation_operate_view(nullptr)
{
	for (size_t i = 0; i < 4; i++)
	{
		m_seat_views.insert(std::make_pair(i+1,nullptr));
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
	//std::
	std::map<uint32_t, PaiGowPlayer*>::const_iterator iter;

	for (iter = m_data->players.begin() ; iter != m_data->players.end(); iter++)
	{
		if (iter->second->has_people)
		{
			PaiGowSeatView* view = addSeat(iter->second);
			//在线状态
			view->showOffline(!(iter->second->is_online));
			//当前积分
			view->setScore(iter->second->score);
			//当前下注状态
			if (iter->second->chips.size() == 0)
			{
				view->hideBet();
			}
			else
			{
				view->showBet(iter->second->chips[0], iter->second->chips[1], betPos(iter->first));
			}

		}
	}

	if (m_data->table_state == TableState::Wait)
	{
		m_wait_operate_view = PaiGowWaitOperateView::create();
		m_wait_operate_view->setPosition(Vec2(g_win_size.width / 2,110));
		core::SceneManager::getInstance()->add(core::LayerMainUIUp,m_wait_operate_view);
		m_wait_operate_view->initView(m_data);
	}
	else if (m_data->table_state == TableState::GrabBanker)
	{
		//std::
		for (iter = m_data->players.begin(); iter != m_data->players.end(); iter++)
		{
			if (iter->second->has_people)
			{
				if (iter->second->status == PLAYER_STATUS_AFTBANKER)
				{
					if (iter->second->is_grab)
					{
						m_seat_views[iter->first]->setStatus("status_qiang");
					}
					else
					{
						m_seat_views[iter->first]->setStatus("status_qiang");
					}
				}
				else
				{
					m_seat_views[iter->first]->setStatus("", true);
					if (iter->second->isMainChar())
					{
						m_grab_operate_view = PaigowGrabOperateView::create();
						m_grab_operate_view->setPosition(Vec2(g_win_size.width / 2, 100));
						core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_grab_operate_view);
					}
				}
			}
		}
	}
	else if (m_data->table_state == TableState::Bet)
	{
		m_bet_operate_view = PaigowBetOperateView::create();
		m_bet_operate_view->setPosition(Vec2(g_win_size.width / 2, 100));
		core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_bet_operate_view);
		for (iter = m_data->players.begin(); iter != m_data->players.end(); iter++)
		{

			if (iter->second->has_people)
			{
				//显示座位上的banker图标
				if (m_data->isBanker(iter->first))
				{
					m_seat_views[iter->first]->showBanker();
					//我是庄
					if (iter->second->isMainChar())
					{
						m_bet_operate_view->show(1);
					}
					else
					{
						m_bet_operate_view->show(2);
					}
				}
				else
				{
					if (iter->second->isMainChar())
					{
						if (iter->second->status == PLAYER_STATUS_PREBET)
						{
							m_bet_operate_view->show(2);
						}
						else
						{
							m_bet_operate_view->show(3);
						}

					}
					m_seat_views[iter->first]->hideBanker();
				}
	
			}



		}
	}
	else if (m_data->table_state == TableState::Collocation)
	{

		//给每个玩家发牌
		std::map<uint32_t, PaiGowPlayer*>::const_iterator iter;
		for (iter = m_data->players.begin(); iter != m_data->players.end(); iter++)
		{
			CCLOG("EVT_PG_DealCard seatid:%d", iter->first);
			m_handcards_views[iter->first] = PaiGowHandCardsPanel::create();
			
			if (iter->second->hand_cards.size() > 0)
			{
				m_handcards_views[iter->first]->setCards(iter->second->hand_cards, iter->second->status == PLAYER_STATUS_AFTCOMPARE);
			}
			else 
			{
				std::vector<Card> cards;
				for (size_t i = 0; i < 4; i++)
				{
					cards.push_back(0x0000);
				}
				m_handcards_views[iter->first]->setCards(cards, iter->second->status == PLAYER_STATUS_AFTCOMPARE);
			}

			
			Vec2 pos = handCardsPos(iter->first);
			m_handcards_views[iter->first]->setPosition(pos);
			core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_handcards_views[iter->first]);
			if (m_data->isMainPlayer(iter->first))
			{
				if (iter->second->status == PLAYER_STATUS_AFTCOMPARE)
				{
					m_handcards_views[iter->first]->setInteractive(false);
				}
				else
				{
					m_handcards_views[iter->first]->setInteractive(true);
					m_collocation_operate_view = PaigowCollocationOperateView::create(this);
					m_collocation_operate_view->setPosition(Vec2(g_win_size.width - 300, 100));
					core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_collocation_operate_view);
				}
				
			}
			else
			{
				m_handcards_views[iter->first]->setInteractive(false);
			}

		}
	}
	else if (m_data->table_state == TableState::Result)
	{
		std::map<uint32_t, PaiGowPlayer*>::const_iterator iter;
		for (iter = m_data->players.begin(); iter != m_data->players.end(); iter++)
		{
			if (iter->second->has_people)
			{
				//还没点击确定
				if (iter->second->status == PLAYER_STATUS_PRESURE)
				{
					m_seat_views[iter->first]->setStatus("", true);
					m_handcards_views[iter->first] = PaiGowHandCardsPanel::create();
					m_handcards_views[iter->first]->setCards(iter->second->hand_cards, true);
					Vec2 pos = handCardsPos(iter->first);
					m_handcards_views[iter->first]->setPosition(pos);
					m_handcards_views[iter->first]->setInteractive(false);
					core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_handcards_views[iter->first]);
				}
				else if (iter->second->status == PLAYER_STATUS_AFTERSURE)
				{
					m_seat_views[iter->first]->setStatus("status_zhunbei");
				}
			}
		}


		//如果还没点击确定 需要显示窗口
		PaiGowPlayer* player = m_data->getMainPlayer();
		if (player->status == PLAYER_STATUS_PRESURE)
		{
			core::WindowManager::getInstance()->open_2<paigow::PaiGowResultWindow, PaiGowViewController*, const std::vector<PaiGowResult*>&>(this, m_data->results);
		}
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
	core::EventManager::Instance().AddEventHandler(core::EVT_PG_Collocation, this);
	core::EventManager::Instance().AddEventHandler(core::EVT_PG_Result, this);
	core::EventManager::Instance().AddEventHandler(core::EVT_PG_Sure, this);
}

void PaiGowViewController::dispose()
{

	std::map<uint32_t, PaiGowSeatView*>::iterator iter;

	for (iter = m_seat_views.begin(); iter != m_seat_views.end(); iter++)
	{
		if (iter->second)
		{
			core::SceneManager::getInstance()->remove(core::LayerMainUI, iter->second);
			iter->second = nullptr;
		}
	}

	std::map<uint32_t, PaiGowHandCardsPanel*>::iterator iter1;

	for (iter1 = m_handcards_views.begin(); iter1 != m_handcards_views.end(); iter1++)
	{
		if (iter1->second)
		{
			core::SceneManager::getInstance()->remove(core::LayerMainUI, iter1->second);
			iter1->second = nullptr;
		}
	}

	m_handcards_views.clear();


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

	if (m_collocation_operate_view)
	{
		core::SceneManager::getInstance()->remove(core::LayerMainUIUp, m_collocation_operate_view);
		m_collocation_operate_view = nullptr;
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
	else if (evt->id_ == core::EVT_PG_OffLine)
	{
		EventOffline* event = (EventOffline*)(evt);
		m_seat_views[event->seat_id]->showOffline(event->offline);

	}
	else if (evt->id_ == core::EVT_PG_StartGame)
	{
		EventStartGame* event = (EventStartGame*)(evt);
		//清除 
		if (m_wait_operate_view)
		{
			core::SceneManager::getInstance()->remove(core::LayerMainUIUp, m_wait_operate_view);
			m_wait_operate_view = nullptr;
		}

		std::map<uint32_t, PaiGowHandCardsPanel*>::iterator iter;
		for (iter = m_handcards_views.begin(); iter != m_handcards_views.end(); iter++)
		{
			if (iter->second)
			{
				core::SceneManager::getInstance()->remove(core::LayerMainUIUp, iter->second);
			}
		}
		m_handcards_views.clear();


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

		//清除玩家抢/不抢的状态
		std::map<uint32_t, PaiGowSeatView*>::iterator iter;
		for (iter = m_seat_views.begin(); iter != m_seat_views.end(); iter++)
		{
			if (iter->second)
			{
				iter->second->setStatus("", true);
			}
		}


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
			m_bet_operate_view->show(1);
		}
		else
		{
			m_bet_operate_view->show(2);
		}
	}
	else if (evt->id_ == core::EVT_PG_Bet)
	{
		EventBet* event = (EventBet*)(evt);
		m_seat_views[event->seat_id]->showBet(event->bet1, event->bet2, betPos(event->seat_id));


	}
	else if(evt->id_ == core::EVT_PG_DealCard)
	{
		EventDealCard* event = (EventDealCard*)(evt);


		if (m_bet_operate_view)
		{
			core::SceneManager::getInstance()->remove(core::LayerMainUIUp, m_bet_operate_view);
			m_bet_operate_view = nullptr;
		}

		//给每个玩家发牌
		std::map<uint32_t, std::vector<Card>>::const_iterator iter;
		for (iter = event->hand_cards.begin(); iter != event->hand_cards.end(); iter++)
		{
			CCLOG("EVT_PG_DealCard seatid:%d", iter->first);
			m_handcards_views[iter->first] = PaiGowHandCardsPanel::create();
			m_handcards_views[iter->first]->setCards(iter->second);
			Vec2 pos = handCardsPos(iter->first);
			m_handcards_views[iter->first]->setPosition(pos);
			core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_handcards_views[iter->first]);
			if (m_data->isMainPlayer(iter->first))
			{
				m_handcards_views[iter->first]->setInteractive(true);
			}
			else
			{
				m_handcards_views[iter->first]->setInteractive(false);
			}
		}

		
		m_collocation_operate_view = PaigowCollocationOperateView::create(this);
		m_collocation_operate_view->setPosition(Vec2(g_win_size.width - 300, 100));
		core::SceneManager::getInstance()->add(core::LayerMainUIUp, m_collocation_operate_view);
	}
	else if(evt->id_ == core::EVT_PG_Collocation)
	{
		EventCollocation* event = (EventCollocation*)(evt);
		if (event->cards.size()  > 0)
		{
			if (m_data->isMainPlayer(event->seat_id))
			{
				if (m_collocation_operate_view)
				{
					core::SceneManager::getInstance()->remove(core::LayerMainUIUp, m_collocation_operate_view);
					m_collocation_operate_view = nullptr;
				}
			}
			else
			{
				m_handcards_views[event->seat_id]->setCards(event->cards);
			}
			m_handcards_views[event->seat_id]->setInteractive(false);
			m_handcards_views[event->seat_id]->playCollocation(event->cards);
		} 
		else
		{
			m_handcards_views[event->seat_id]->playCollocation();
		}
	}
	else if (evt->id_ == core::EVT_PG_Result)
	{
		EventResult* event = (EventResult*)(evt);
		for (int i = 0; i < event->result->scores_size(); i++)
		{
			uint32_t seatid = event->result->scores(i).seat_id();

			//播放非自己玩家的亮牌动画
			if (!(m_data->isMainPlayer(seatid)))
			{
				std::vector<Card> cards;
				for (int j = 0; j < event->result->scores(i).hand_cards_size(); j++)
				{
					cards.push_back(event->result->scores(i).hand_cards(j));
				}

				m_handcards_views[event->result->scores(i).seat_id()]->setCards(cards);
				m_handcards_views[event->result->scores(i).seat_id()]->playCollocation(cards);
			}

			//更新分数
			m_seat_views[seatid]->setScore(m_data->players[seatid]->score);
		}

		core::WindowManager::getInstance()->open_2<paigow::PaiGowResultWindow, PaiGowViewController*, const std::vector<PaiGowResult*>&>(this, m_data->results);
	}
	else if (evt->id_ == core::EVT_PG_Sure)
	{
		EventSure* event = (EventSure*)(evt); 
		core::SceneManager::getInstance()->remove(core::LayerMainUIUp, m_handcards_views[event->seat_id]);
		m_handcards_views.erase(event->seat_id);
		m_seat_views[event->seat_id]->hideBet();
		m_seat_views[event->seat_id]->setStatus("status_zhunbei");
	}

	return 0;
}

void PaiGowViewController::onClickCollcationTips()
{
}

void PaiGowViewController::onClickCollcationSure()
{
	std::vector<Card> first;
	std::vector<Card> second;
	PaiGowPlayer* mainPlayer = m_data->getMainPlayer();
	m_handcards_views[mainPlayer->seat_id]->getResultCards(first,second);
	if (first.size() == 2)
	{
		proto3_proto::C2S_PG_Collocation msg;
		for (size_t i = 0; i < first.size(); i++)
		{
			msg.add_first(first[i]);
		}

		for (size_t i = 0; i < second.size(); i++)
		{
			msg.add_end(second[i]);
		}
		
		core::SocketManager::getInstance()->sendMessage(core::ID_C2S_PG_Collocation, msg);
	}
	else
	{
		core::SceneManager::getInstance()->showMsg("error number of cards");
	}
}

const PaiGowPlayer * PaiGowViewController::getPlayerBySeatId(uint32_t seat_id)
{
	if (m_data->players.find(seat_id) != m_data->players.end())
	{
		return m_data->players[seat_id];
	}
	else
	{
		return nullptr;
	}
}

bool PaiGowViewController::isMySeat(uint32_t seat_id) const
{
	return m_data->isMainPlayer(seat_id);
}

const PaiGowPlayer * PaiGowViewController::getMyPlayer() const
{
	return m_data->getMainPlayer();
}

PaiGowSeatView* PaiGowViewController::addSeat(PaiGowPlayer * player)
{
	PaiGowSeatView* view = PaiGowSeatView::create();
	view->initView(player);
	Vec2 pos = seatPos(player);
	view->setPosition(pos);

	core::SceneManager::getInstance()->add(core::LayerMainUI, view);
	m_seat_views[player->seat_id] = view;
	return view;
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

cocos2d::Vec2 PaiGowViewController::handCardsPos(int seat_id)
{
	int s_id = m_data->getSeatIndex(seat_id);
	CCLOG("seatid:%d  s_id:%d", seat_id, s_id);
	switch (s_id)
	{
	case 0:
		return Vec2(g_win_size.width / 2, 100);
	case 1:
		return Vec2(g_win_size.width - 280, g_win_size.height / 2);
	case 2:
		return Vec2(g_win_size.width / 2 - 90, g_win_size.height - 140);
	case 3:
		return Vec2(280, g_win_size.height / 2);
	default:
		break;
	}

	return cocos2d::Vec2(0, 0);
}


NS_PAIGOW_END
