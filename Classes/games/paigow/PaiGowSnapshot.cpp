#include "PaiGowSnapshot.h"
#include "PaigowManager.h"

NS_PAIGOW_BEGIN

PaiGowSnaptShot::PaiGowSnaptShot()
	:table_state(TableState::Unkown),
	room_owner(0)
{
	public_cards = new Card[32];

	for (size_t i = 0; i < 4; i++)
	{
		players.push_back(nullptr);
	}
}

PaiGowSnaptShot::~PaiGowSnaptShot()
{
	delete public_cards;
	for (size_t i = 0; i < players.size(); i++)
	{
		if (players[i])
		{
			delete players[i];
		}
	}
}

void PaiGowSnaptShot::init(const proto3_proto::S2C_MatchSnapshot & mc_st)
{
	initByMatch(mc_st.match());
	table_state = (TableState)mc_st.paigow().state();
	room_owner = mc_st.paigow().room_owner();
	
	size_t length = mc_st.paigow().public_cards_size();
	for (size_t i = 0; i < length; i++)
	{
		public_cards[i] = mc_st.paigow().public_cards(i);
	}

	length = mc_st.paigow().players_size();

	for (size_t i = 0; i < length; i++)
	{
		uint32_t seat_id = mc_st.paigow().players(i).player().seat_id();
		if (players[seat_id])
		{
			delete players[seat_id];
		}

		players[seat_id] = new PaiGowPlayer;

		players[seat_id]->initByPaiGowPlayer(mc_st.paigow().players(i));
	}

}

NS_PAIGOW_END