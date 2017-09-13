#include "PaiGowPlayer.h"

NS_PAIGOW_BEGIN

uint32_t status;
std::vector<Card> hand_cards;
std::vector<uint32_t> chips;
int score;
int cur_score;
bool is_grab;
bool has_people;
PaiGowPlayer::PaiGowPlayer() :
	status(0),
	score(0),
	cur_score(0),
	is_grab(false),
	has_people(false),
	PlayerInfo::PlayerInfo()
{

}


PaiGowPlayer::~PaiGowPlayer()
{
	
}

void PaiGowPlayer::initByPaiGowPlayer(const proto3_proto::PaiGowPlayer & player)
{
	initByPlayerInfo(player.player());

	//≥ı ºªØ ÷≈∆
	hand_cards.clear();
	size_t length = player.hand_cards_size();
	for (size_t i = 0; i < length; i++)
	{
		hand_cards.push_back(player.hand_cards(i));
	}

	status = player.status();

	length = player.chips_size();
	for (size_t i = 0; i < length; i++)
	{
		chips.push_back(player.chips(i));
	}

	score = player.score();
	is_grab = player.is_grab();
	has_people = true;
}

void PaiGowPlayer::reset()
{
	status = PLAYER_STATUS_READY;
}

NS_PAIGOW_END