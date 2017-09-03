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
	create_time = match.create_time();
	begin_time = match.begin_time();
	total_round = match.total_round();
	cost = match.cost();
	state = match.state();
	round = match.round();
}

void MatchSnaptShot::clear()
{
	room_id = 0;
	type = 0;
	create_time = 0;
	begin_time = 0;
	total_round = 0;
	cost = 0;
	state = 0;
	round = 0;
}

NS_GAME_END