#include "PaiGowSnapshot.h"
#include "PaigowManager.h"

NS_PAIGOW_BEGIN

PaiGowSnaptShot::PaiGowSnaptShot()
	:table_state(PGST_Unkown),
	room_owner(0)
{
	public_cards = new Card[32];
	players = new PaiGowPlayer[4];
}

PaiGowSnaptShot::~PaiGowSnaptShot()
{
	delete public_cards;
	delete players;
}

void PaiGowSnaptShot::init(const proto3_proto::S2C_MatchSnapshot & mc_st)
{
	initByMatch(mc_st.match());
	table_state = mc_st.paigpow().state();
	room_owner = mc_st.paigpow().room_owner();
	
	size_t length = mc_st.paigpow().public_cards_size();
	for (size_t i = 0; i < length; i++)
	{
		public_cards[i] = mc_st.paigpow().public_cards(i);
	}

	length = mc_st.paigpow().players_size();

	for (size_t i = 0; i < length; i++)
	{
		players[i].initByPaiGowPlayer(mc_st.paigpow().players(i));
	}

}

NS_PAIGOW_END