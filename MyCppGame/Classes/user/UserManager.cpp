#include "UserManager.h"
#include "core\fsm\game_machine.h"

NS_USER_BEGIN

void UserManager::initUserInfo(proto3_proto::UserInfo* userInfo)
{
	m_s_id = userInfo->id();
	m_s_name = userInfo->name();
	m_s_head = userInfo->head();
	m_i_card = userInfo->card();
	m_b_is_inited = true;
	core::UserInfoInitedEvent event;
	core::GameStateMachine::getInstance()->dispatchEvent(event);
}

NS_USER_END