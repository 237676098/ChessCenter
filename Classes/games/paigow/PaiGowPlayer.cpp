#include "PaiGowPlayer.h"

NS_PAIGOW_BEGIN


PaiGowPlayer::PaiGowPlayer():
	is_banker(false), 
	status(false)
{
	hand_cards = new Card[4];
	chips = new uint32_t[4];
}

PaiGowPlayer::~PaiGowPlayer()
{
	delete hand_cards;
	delete chips;
}

void PaiGowPlayer::initByPaiGowPlayer(const proto3_proto::PaiGowPlayer & player)
{
	initByPlayerInfo(player.player());

	//≥ı ºªØ ÷≈∆
	size_t length = player.hand_cards_size();
	for (size_t i = 0; i < length; i++)
	{
		hand_cards[i] = player.hand_cards(i);
	}

	is_banker = player.is_banker();
	status = player.status();

	length = player.chips_size();
	for (size_t i = 0; i < length; i++)
	{
		chips[i] = player.chips(i);
	}
}

NS_PAIGOW_END