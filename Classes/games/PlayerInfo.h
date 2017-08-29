#ifndef __PLAYER_INFO_H__
#define __PLAYER_INFO_H__
#include <stdint.h>
#include "core/network/socket/SocketManager.h"

NS_GAME_BEGIN

class PlayerInfo
{
public:
	PlayerInfo();
	virtual  ~PlayerInfo();
public:
	void initByPlayerInfo(const proto3_proto::PlayerInfo& info);

 
public:
	uint64_t uid;
	int seat_id;
	std::string name;
	std::string head;
	std::string ip;
};


NS_GAME_END

#endif