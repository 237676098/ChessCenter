#ifndef __IGAME_STATE_H__
#define __IGAME_STATE_H__
#include "utils/CommonMacros.h"
#include "core/network/socket/SocketManager.h"
NS_CORE_BEGIN
typedef enum _GAME_EVENT {
	EVENT_USER_INFO_INITED_SUCCESS,
	EVENT_TABLE_SNAPTSHOT,
	EVENT_LEAVE_MATCH,
} GAME_EVENT;

typedef enum _GAME_STATE {
	STATE_UNKOWN = -1,
	STATE_LOGIN = 0,
	STATE_LOBBY = 1,
	STATE_TABLE = 2
} GAME_STATE;

class GameEvent
{
public:
	GameEvent(GAME_EVENT event) :m_event(event) {};
	virtual GAME_EVENT getType() const { return m_event; };
private:
	GAME_EVENT m_event;
};

class UserInfoInitedEvent:public GameEvent
{
public:
	UserInfoInitedEvent() :GameEvent(EVENT_USER_INFO_INITED_SUCCESS) {};

private:

};

class GameSnaptshotEvent :public GameEvent
{
public:
	GameSnaptshotEvent() :m_snaptshot(nullptr), GameEvent(EVENT_TABLE_SNAPTSHOT) {};
	~GameSnaptshotEvent();
	void setSnaptShot(proto3_proto::S2C_MatchSnapshot* snaptshot);
	inline proto3_proto::S2C_MatchSnapshot* getSnaptShot() { return m_snaptshot; };
private:
	proto3_proto::S2C_MatchSnapshot* m_snaptshot;
};

class LeaveMatchEvent :public GameEvent
{
public:
	LeaveMatchEvent() :GameEvent(EVENT_LEAVE_MATCH) {};

private:

};


class IGameState
{
public:
	IGameState(GAME_STATE type) :m_type(type) {};
	virtual void init() {};
	virtual void enter(const GameEvent* event) {};
	virtual void exit(const GameEvent* event) {};
	virtual GAME_STATE handleEvent(const GameEvent* event) { return STATE_UNKOWN; };
	GAME_STATE getType() { return m_type; };

private:
	GAME_STATE m_type;
};
NS_CORE_END
#endif