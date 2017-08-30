#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__
#include  <string>
#include "core/network/socket/SocketManager.h"
#include "core/fsm/game_machine.h"

NS_GAME_BEGIN

class GameManager
{
	SINGLETON(GameManager)
public:
	void init(proto3_proto::S2C_MatchSnapshot* shot);
	void dispose();
	void createMatch();
private:
	MSG_FUNCTION_DEFINE(S2C_MatchSnapshot)
private:
	
};

NS_GAME_END
#endif