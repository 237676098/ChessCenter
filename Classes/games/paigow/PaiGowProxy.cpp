#include "PaiGowProxy.h"
#include "core/event/EventManager.h"
#include "games/paigow/events/paigow_events.h"
#include "core/fsm/game_machine.h"

NS_PAIGOW_BEGIN

PaiGowProxy::PaiGowProxy(PaiGowSnaptShot* data)
	:m_data(data)
{
	//注册事件监听
	MSG_FUNCTION_REGISTER(S2C_PG_StartGame, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_GrabBanker, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_GrabBanker_RES, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_Bet, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_Deal, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_Collocation, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_Result, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_AddPlayer, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_LeaveMatch, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_OffLine, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_OnLine, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_Sure, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_MatchResult, PaiGowProxy)
}

PaiGowProxy::~PaiGowProxy()
{

}

void PaiGowProxy::onRevS2C_PG_AddPlayer(google::protobuf::Message* msg)
{
	proto3_proto::S2C_PG_AddPlayer* s2c_msg = dynamic_cast<proto3_proto::S2C_PG_AddPlayer*>(msg);
	m_data->addPlayer(s2c_msg->player());

	EventAddPlayer event(m_data->players[s2c_msg->player().player().seat_id()],core::EVT_PG_AddPlayer);
	core::EventManager::Instance().DispatchEvent(&event);
}

void PaiGowProxy::onRevS2C_PG_StartGame(google::protobuf::Message* msg)
{
	proto3_proto::S2C_PG_StartGame* s2c_msg = dynamic_cast<proto3_proto::S2C_PG_StartGame*>(msg);
	m_data->table_state = TableState::GrabBanker;
	m_data->round++;

	//更新玩家状态
	m_data->updatePlayerState(PLAYER_STATUS_PREBANKER);


	if (m_data->round % 2 == 1)
	{
		m_data->public_cards.clear();
	}

	EventStartGame event;
	core::EventManager::Instance().DispatchEvent(&event);
}

void PaiGowProxy::onRevS2C_PG_GrabBanker(google::protobuf::Message* msg)
{
	proto3_proto::S2C_PG_GrabBanker* s2c_msg = dynamic_cast<proto3_proto::S2C_PG_GrabBanker*>(msg);
	m_data->players[s2c_msg->seat_id()]->is_grab = s2c_msg->is_grab();

	m_data->updatePlayerState(s2c_msg->seat_id(),PLAYER_STATUS_AFTBANKER);
	EventGrabStatus event(s2c_msg->seat_id(), s2c_msg->is_grab());
	core::EventManager::Instance().DispatchEvent(&event);
}

void PaiGowProxy::onRevS2C_PG_GrabBanker_RES(google::protobuf::Message* msg)
{
	proto3_proto::S2C_PG_GrabBanker_RES* s2c_msg = dynamic_cast<proto3_proto::S2C_PG_GrabBanker_RES*>(msg);
	m_data->banker_seat_id = s2c_msg->seat_id();
	m_data->table_state = TableState::Bet;
	m_data->updatePlayerState(PLAYER_STATUS_PREBET);
	EventBankerConfirm event(s2c_msg->seat_id());
	core::EventManager::Instance().DispatchEvent(&event);
}

void PaiGowProxy::onRevS2C_PG_Bet(google::protobuf::Message* msg)
{
	proto3_proto::S2C_PG_Bet* s2c_msg = dynamic_cast<proto3_proto::S2C_PG_Bet*>(msg);
	//s2c_msg->set_user_id
	m_data->players[s2c_msg->seat_id()]->chips.clear();
	m_data->updatePlayerState(s2c_msg->seat_id(), PLAYER_STATUS_AFTBET);
	for (int i = 0; i < s2c_msg->chips_size(); i++)
	{
		m_data->players[s2c_msg->seat_id()]->chips.push_back(s2c_msg->chips(i));
	}
	EventBet event(s2c_msg->seat_id(), m_data->players[s2c_msg->seat_id()]->chips[0], m_data->players[s2c_msg->seat_id()]->chips[1]);
	core::EventManager::Instance().DispatchEvent(&event);
}

void PaiGowProxy::onRevS2C_PG_Deal(google::protobuf::Message* msg)
{
	proto3_proto::S2C_PG_Deal* s2c_msg = dynamic_cast<proto3_proto::S2C_PG_Deal*>(msg);
	m_data->table_state = TableState::Collocation;
	m_data->updatePlayerState(PLAYER_STATUS_PRECOMPARE);
	std::map<uint32_t, PaiGowPlayer*>::iterator iter;
	for (iter = m_data->players.begin(); iter != m_data->players.end(); iter++)
	{
		if (iter->second->isMainChar())
		{
			for (int i = 0; i < s2c_msg->my_card_size(); i++)
			{
				iter->second->hand_cards.push_back(s2c_msg->my_card(i));
			}
			break;
		}
	}
	EventDealCard event;
	//event.hand_cards = handcards;
	core::EventManager::Instance().DispatchEvent(&event);
}

void PaiGowProxy::onRevS2C_PG_Collocation(google::protobuf::Message* msg)
{
	proto3_proto::S2C_PG_Collocation* s2c_msg = dynamic_cast<proto3_proto::S2C_PG_Collocation*>(msg);
	m_data->updatePlayerState(s2c_msg->seat_id(), PLAYER_STATUS_AFTCOMPARE);
	EventCollocation event;
	event.seat_id = s2c_msg->seat_id();
	for (int i = 0; i < s2c_msg->first_cards_size(); i++)
	{
		event.first_cards.push_back(s2c_msg->first_cards(i));
	}

	for (int i = 0; i < s2c_msg->end_cards_size(); i++)
	{
		event.end_cards.push_back(s2c_msg->end_cards(i));
	}
	uint32_t test1 = s2c_msg->test();
	proto3_proto::S2C_PG_Collocation test;
	test.set_seat_id(1);
	test.add_first_cards(0);
	test.add_first_cards(1);
	test.add_end_cards(2);
	test.add_end_cards(3);
	test.set_test(100);
	std::string tmpStr;
	test.SerializeToString(&tmpStr);
	const char* s1 = tmpStr.c_str();
	for (size_t i = 0; i < 12; i++)
	{
		//CCLOG("%02x", (unsigned char)s1[i]);
	}

	

	uint32_t length = tmpStr.length();
	//CCLOG("length:%u",length);

	core::EventManager::Instance().DispatchEvent(&event);
}

void PaiGowProxy::onRevS2C_PG_Result(google::protobuf::Message* msg)
{
	proto3_proto::S2C_PG_Result* s2c_msg = dynamic_cast<proto3_proto::S2C_PG_Result*>(msg);
	m_data->updatePlayerState(PLAYER_STATUS_PRESURE);
	m_data->clearResult();
	

	for (int i = 0; i < s2c_msg->scores_size(); i++)
	{
		m_data->players[s2c_msg->scores(i).seat_id()]->score = s2c_msg->scores(i).total_result();
	
		m_data->addResult(s2c_msg->scores(i));
	}

	m_data->public_cards.clear();
	if (m_data->round % 2 == 1)
	{
		for (int i = 0; i < s2c_msg->public_cards_size(); i++)
		{
			m_data->public_cards.push_back(s2c_msg->public_cards(i));
		}
	}

	EventResult event;
	event.result = s2c_msg;
	core::EventManager::Instance().DispatchEvent(&event);

	m_data->is_match_end = s2c_msg->is_end();
}

void PaiGowProxy::onRevS2C_LeaveMatch(google::protobuf::Message* msg)
{
	proto3_proto::S2C_LeaveMatch* leavematch = dynamic_cast<proto3_proto::S2C_LeaveMatch*> (msg);

	//如果是主角色离开 清理牌桌 回到大厅
	if (m_data->players[leavematch->seat_id()]->isMainChar())
	{
		m_data->clear();
		core::LeaveMatchEvent event;
		core::GameStateMachine::getInstance()->dispatchEvent(&event);
	}
	else
	{
		m_data->deletePlayer(leavematch->seat_id());
		EventDeletePlayer event(leavematch->seat_id());
		core::EventManager::Instance().DispatchEvent(&event);
	}


}

void PaiGowProxy::onRevS2C_OffLine(google::protobuf::Message* msg)
{
	proto3_proto::S2C_OffLine* s2c_msg = dynamic_cast<proto3_proto::S2C_OffLine*> (msg);
	CCLOG("offline %u", s2c_msg ->seat_id());
	EventOffline event(s2c_msg->seat_id(), true);
	core::EventManager::Instance().DispatchEvent(&event);
}

void  PaiGowProxy::onRevS2C_OnLine(google::protobuf::Message* msg)
{
	proto3_proto::S2C_OnLine* s2c_msg = dynamic_cast<proto3_proto::S2C_OnLine*> (msg);
	CCLOG("online %u", s2c_msg->seat_id());
	EventOffline event(s2c_msg->seat_id(), false);
	core::EventManager::Instance().DispatchEvent(&event);
}

void PaiGowProxy::onRevS2C_PG_Sure(google::protobuf::Message* msg)
{
	proto3_proto::S2C_PG_Sure*  s2c_msg = dynamic_cast<proto3_proto::S2C_PG_Sure*> (msg);
	m_data->players[s2c_msg->seat_id()]->reset();
	m_data->updatePlayerState(s2c_msg->seat_id(), PLAYER_STATUS_AFTERSURE);
	EventSure event;
	event.seat_id = s2c_msg->seat_id();
	core::EventManager::Instance().DispatchEvent(&event);
}

void PaiGowProxy::onRevS2C_PG_MatchResult(google::protobuf::Message* msg)
{
	proto3_proto::S2C_PG_MatchResult*  s2c_msg = dynamic_cast<proto3_proto::S2C_PG_MatchResult*> (msg);
	m_data->finish_time = s2c_msg->finish_time();
	for (int i = 0; i < s2c_msg->players_size(); i++)
	{
		m_data->addMatchResult(s2c_msg->players(i));
	}
}

NS_PAIGOW_END