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



void GameManager::onRevS2C_MatchSnapshot(google::protobuf::Message* msg)
{
	proto3_proto::S2C_MatchSnapshot* snaptshot = dynamic_cast<proto3_proto::S2C_MatchSnapshot*>(msg);
	
	core::GameSnaptshotEvent event;
	event.setSnaptShot(snaptshot);

	core::GameStateMachine::getInstance()->dispatchEvent(&event);

}

NS_GAME_END