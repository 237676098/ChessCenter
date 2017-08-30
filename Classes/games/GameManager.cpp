#include "GameManager.h"
#include "games/paigow/PaigowManager.h"

NS_GAME_BEGIN

GameManager::GameManager()
{
	MSG_FUNCTION_REGISTER(S2C_MatchSnapshot,GameManager)
}

GameManager::~GameManager()
{

}

void GameManager::init(proto3_proto::S2C_MatchSnapshot* shot)
{
	game::paigow::PaigowManager::getInstance()->init(*shot);
}

void GameManager::dispose()
{
	game::paigow::PaigowManager::getInstance()->dispose();
}


void GameManager::createMatch()
{
	proto3_proto::C2S_CreateMatch  cmc;
	cmc.set_for_other(false);
	cmc.set_type(1);


	proto3_proto::PaiGowConfig* pconfig = cmc.mutable_paigow();
	//proto3_proto::PaiGowConfig pconfig;
	pconfig->set_pot(0);
	pconfig->set_banker_type(1);
	pconfig->set_is_bet_always(true);
	pconfig->set_lock_bet_num(0);
	pconfig->set_type(2);
	pconfig->set_has_ghost(false);
	pconfig->set_has_heaven_nine(false);

	core::SocketManager::getInstance()->sendMessage(core::ID_C2S_CreateMatch, cmc);
}

void GameManager::onRevS2C_MatchSnapshot(google::protobuf::Message* msg)
{
	proto3_proto::S2C_MatchSnapshot* snaptshot = dynamic_cast<proto3_proto::S2C_MatchSnapshot*>(msg);
	
	core::GameSnaptshotEvent event;
	event.setSnaptShot(snaptshot);

	core::GameStateMachine::getInstance()->dispatchEvent(&event);

}

NS_GAME_END