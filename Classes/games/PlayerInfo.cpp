#include "PlayerInfo.h"
#include "core/network/socket/protocol.h"
#include "user/UserManager.h"

NS_GAME_BEGIN

uint64_t uid;
uint32_t seat_id;
std::string name;
std::string head;
std::string ip;
bool is_online;
PlayerInfo::PlayerInfo():
	uid(0),
	seat_id(0),
	name(""),
	head(""),
	ip(""),
	is_online(false)
{

}

PlayerInfo::~PlayerInfo()
{

}

void PlayerInfo::initByPlayerInfo(const proto3_proto::PlayerInfo& info)
{
	seat_id = info.seat_id();
	uid = info.user_id();
	name = info.name();
	head = info.head();
	ip = info.ip();
	is_online = info.is_online();
}

bool PlayerInfo::isMainChar()
{
	return uid == user::UserManager::getInstance()->getId(); 
}

NS_GAME_END