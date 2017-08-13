#pragma once
#include "IGameState.h"
#include "utils/Singleton.h"


class GameStateMachine
{
public:
	//获取当前游戏状态
	IGameState* getState() { return m_state; };
	void init();
	void dispatchEvent(const GameEvent& event);

private:
	IGameState* _createStateByType(GAME_STATE type);

private:
	IGameState* m_state;


	SINGLETON(GameStateMachine)
};