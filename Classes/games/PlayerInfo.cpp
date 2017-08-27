#include "PlayerInfo.h"
#include "core/network/socket/protocol.h"

NS_GAME_BEGIN


PlayerInfo::PlayerInfo()
{

}

PlayerInfo::~PlayerInfo()
{

}

void PlayerInfo::initByPlayerInfo(const proto3_proto::PlayerInfo& info)
{
	m_seat_id = info.seat_id();
	m_uid = info.user_id();
	m_name = info.name();
	m_head = info.head();
	m_ip = info.ip();
}

NS_GAME_END