#include "UserManager.h"
#include "core/fsm/game_machine.h"
#include "core/network/socket/SocketManager.h"

NS_USER_BEGIN

UserManager::UserManager()
{

}

UserManager::~UserManager()
{

}

void UserManager::init()
{
	core::SocketManager::getInstance()->registerHandler(core::ID_S2C_InitUserInfo, std::bind(&UserManager::onRevS2C_InitUserInfo,this,std::placeholders::_1));
}

void UserManager::onRevS2C_InitUserInfo(google::protobuf::Message * messgae)
{
	proto3_proto::S2C_InitUserInfo* s2c_init_user_info = dynamic_cast<proto3_proto::S2C_InitUserInfo*>(messgae);
	m_id = s2c_init_user_info->user().uid();
	m_name = s2c_init_user_info->user().name();
	m_head = s2c_init_user_info->user().head();
	m_card = s2c_init_user_info->user().card();
	m_is_inited = true;
	core::UserInfoInitedEvent event;
	core::GameStateMachine::getInstance()->dispatchEvent(event);
}

NS_USER_END


