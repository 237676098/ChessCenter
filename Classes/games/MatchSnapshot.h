#ifndef __MATCH_SNAPTSHOT_H__
#define __MATCH_SNAPTSHOT_H__
#include <stdint.h>
#include "core/network/socket/SocketManager.h"

NS_GAME_BEGIN

class MatchSnaptShot
{
	
public:
	MatchSnaptShot();
	virtual ~MatchSnaptShot();
	void initByMatch(const proto3_proto::Match& match);

public:
	int room_id;
	int type;
	int64_t create_time;
	int64_t begin_time;
	int number;
	int cost;
	int state;
	int round;


};


NS_GAME_END
#endif // !__MATCH_SNAPTSHOT_H__

