#include "PaiGowPlayer.h"

NS_PAIGOW_BEGIN


PaiGowPlayer::PaiGowPlayer():
	status(false),
	score(0)
{

}


PaiGowPlayer::~PaiGowPlayer()
{
	
}

void PaiGowPlayer::initByPaiGowPlayer(const proto3_proto::PaiGowPlayer & player)
{
	initByPlayerInfo(player.player());

	//��ʼ������
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
}

NS_PAIGOW_END