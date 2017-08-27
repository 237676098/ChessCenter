#ifndef __TABLE_STATE_H__
#define __TABLE_STATE_H__
#include "IGameState.h"
NS_CORE_BEGIN
class TableState :public IGameState
{
public:
	TableState() :IGameState(STATE_TABLE) {};
	GAME_STATE handleEvent(const GameEvent* event) override;
	void enter(const GameEvent* event) override;
	void exit(const GameEvent* event) override;
private:

};
NS_CORE_END
#endif
