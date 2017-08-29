#include "MatchSnapshot.h"

NS_GAME_BEGIN

MatchSnaptShot::MatchSnaptShot()
{

}

MatchSnaptShot::~MatchSnaptShot()
{

}

void MatchSnaptShot::initByMatch(const proto3_proto::Match & match)
{
	room_id = match.room_id();
	type = match.type();
	create_time = match.createtime();
	begin_time = match.begintime();
	number = match.number();
	cost = match.cost();
	state = match.state();
	round = match.round();
}

NS_GAME_END