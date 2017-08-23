#include "GameStateMachine.h"
#include "LoginState.h"
#include "LobbyState.h"

NS_CORE_BEGIN
SINGLETON_C_D(GameStateMachine)
void GameStateMachine::init()
{
	this->m_state = _createStateByType(STATE_LOGIN);
	this->m_state->init();
}

void GameStateMachine::dispatchEvent(const GameEvent& event)
{
	GAME_STATE state_type = this->m_state->handleEvent(event);
	if (state_type != this->m_state->getType())
	{
		this->m_state->exit();
		delete this->m_state;
		this->m_state = _createStateByType(state_type);
		this->m_state->enter();
	}
}

IGameState* GameStateMachine::_createStateByType(GAME_STATE type)
{
	if (type == STATE_LOGIN)
	{
		return new LoginState();
	}else if(type == STATE_LOBBY)
	{
		return new LobbyState();
	}

	return nullptr;
}

NS_CORE_END