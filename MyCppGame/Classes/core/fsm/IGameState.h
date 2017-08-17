#pragma once
#include "utils\CommonMacros.h"
NS_CORE_BEGIN
typedef enum _GAME_EVENT {
	EVENT_LOGIN_SUCCESS,
} GAME_EVENT;


typedef enum _GAME_STATE {
	STATE_UNKOWN = -1,
	STATE_LOGIN = 0,
} GAME_STATE;

class GameEvent
{
public:
	GameEvent(GAME_EVENT event) :m_event(event) {};
	GAME_EVENT getType() { return m_event; };

private:
	GAME_EVENT m_event;
};


class IGameState
{
public:
	IGameState(GAME_STATE type) :m_type(type) {};
	virtual void init() {};
	virtual void enter() {};
	virtual void exit() {};
	virtual GAME_STATE handleEvent(const GameEvent& event) { return STATE_UNKOWN; };
	GAME_STATE getType() { return m_type; };

private:
	GAME_STATE m_type;
};
NS_CORE_END