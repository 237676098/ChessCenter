#include "GameStateMachine.h"
#include "LoginState.h"

void GameStateMachine::init()
{

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
	}
}