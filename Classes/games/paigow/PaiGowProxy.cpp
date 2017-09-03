#include "PaiGowProxy.h"
#include "core/event/EventManager.h"
#include "games/paigow/events/EventAddPlayer.h"
#include "games/paigow/events/EventDeletePlayer.h"
#include "games/paigow/events/EventStartGame.h"
#include "games/paigow/events/EventBankerConfirm.h"
#include "games/paigow/events/EventBet.h"
#include "games/paigow/events/EventOffLine.h"
#include "core/fsm/game_machine.h"

NS_PAIGOW_BEGIN

PaiGowProxy::PaiGowProxy(PaiGowSnaptShot* data)
	:m_data(data)
{
	//注册事件监听
	MSG_FUNCTION_REGISTER(S2C_PG_StartGame, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_GrabBanker, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_Bet, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_Deal, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_Collocation, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_Result, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_AddPlayer, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_LeaveMatch, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_OffLine, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_OnLine, PaiGowProxy)
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
	EventStartGame event;
	core::EventManager::Instance().DispatchEvent(&event);
}

void PaiGowProxy::onRevS2C_PG_GrabBanker(google::protobuf::Message* msg)
{
	proto3_proto::S2C_PG_GrabBanker* s2c_msg = dynamic_cast<proto3_proto::S2C_PG_GrabBanker*>(msg);
	m_data->banker_seat_id = s2c_msg->seat_id();
	m_data->table_state = TableState::Bet;
	EventBankerConfirm event(s2c_msg->seat_id());
	core::EventManager::Instance().DispatchEvent(&event);
}

void PaiGowProxy::onRevS2C_PG_Bet(google::protobuf::Message* msg)
{
	proto3_proto::S2C_PG_Bet* s2c_msg = dynamic_cast<proto3_proto::S2C_PG_Bet*>(msg);
	//s2c_msg->set_user_id
	m_data->players[s2c_msg->seat_id()]->chips.clear();
	for (int i = 0; i < s2c_msg->chips_size(); i++)
	{
		m_data->players[s2c_msg->seat_id()]->chips.push_back(s2c_msg->chips(i));
	}
	EventBet event(s2c_msg->seat_id(), m_data->players[s2c_msg->seat_id()]->chips[0], m_data->players[s2c_msg->seat_id()]->chips[1]);
	core::EventManager::Instance().DispatchEvent(&event);
}

void PaiGowProxy::onRevS2C_PG_Deal(google::protobuf::Message* msg)
{
	m_data->table_state = TableState::Collocation;

}

void PaiGowProxy::onRevS2C_PG_Collocation(google::protobuf::Message* msg)
{

}

void PaiGowProxy::onRevS2C_PG_Result(google::protobuf::Message* msg)
{

}

void PaiGowProxy::onRevS2C_LeaveMatch(google::protobuf::Message* msg)
{
	proto3_proto::S2C_LeaveMatch* leavematch = dynamic_cast<proto3_proto::S2C_LeaveMatch*> (msg);
	CCASSERT(m_data->players[leavematch->seat_id()] != nullptr,"seat id bu cun zai");

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

NS_PAIGOW_END