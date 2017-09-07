#include "PaiGowSnapshot.h"
#include "PaigowManager.h"

NS_PAIGOW_BEGIN

PaiGowSnaptShot::PaiGowSnaptShot()
	:table_state(TableState::Unkown),
	room_owner(0)
{
	for (size_t i = 0; i < 4; i++)
	{
		players.insert(std::make_pair(i,nullptr));
	}
}

PaiGowSnaptShot::~PaiGowSnaptShot()
{
	clear();
}

void PaiGowSnaptShot::init(const proto3_proto::S2C_MatchSnapshot & mc_st)
{
	initByMatch(mc_st.match());
	table_state = (TableState)mc_st.paigow().state();
	room_owner = mc_st.paigow().room_owner();
	banker_seat_id = mc_st.paigow().banker_seat_id();
	size_t length = mc_st.paigow().public_cards_size();
	for (size_t i = 0; i < length; i++)
	{
		public_cards.push_back(mc_st.paigow().public_cards(i));
	}

	length = mc_st.paigow().players_size();

	for (size_t i = 0; i < length; i++)
	{
		addPlayer(mc_st.paigow().players(i));
	}

}

void PaiGowSnaptShot::clear()
{
	MatchSnaptShot::clear();
	table_state = TableState::Unkown;
	room_owner = 0;
	public_cards.clear();
	for (size_t i = 0; i < players.size(); i++)
	{
		if (players[i])
		{
			delete players[i];
			players[i] = nullptr;
		}
	}
}

void PaiGowSnaptShot::addPlayer(const proto3_proto::PaiGowPlayer& p)
{
	uint32_t seatid = p.player().seat_id();
	CCASSERT(players[seatid] == nullptr, "add player faield ");
	players[seatid] = new PaiGowPlayer;
	players[seatid]->initByPaiGowPlayer(p);
}

void PaiGowSnaptShot::deletePlayer(uint32_t seatid)
{
	CCASSERT(players[seatid] != nullptr, "delete player failed");
	delete players[seatid];
	players[seatid] = nullptr;
}

int PaiGowSnaptShot::getSeatIndex(int seatid) const
{
	int my_seat_id = -1;

	std::map<uint32_t, PaiGowPlayer*>::const_iterator iter;

	for (iter = players.begin(); iter != players.end(); iter++)
	{
		if ((*iter).second && (*iter).second->isMainChar())
		{
			my_seat_id = (*iter).second->seat_id - 1;
		}
	}
	seatid--;
	CCASSERT(my_seat_id != -1,"my seat id is null");

	return (seatid + (4 - my_seat_id)) % 4;
}

PaiGowPlayer * PaiGowSnaptShot::getMainPlayer() const
{

	std::map<uint32_t, PaiGowPlayer*>::const_iterator iter;
	for (iter = players.begin();iter != players.end();iter ++)
	{
		if (iter->second && iter->second->isMainChar())
		{
			return iter->second;
		}
	}
	return nullptr;
}

bool PaiGowSnaptShot::isMainPlayer(uint32_t seat_id) const
{
	std::map<uint32_t, PaiGowPlayer*>::const_iterator iter;
	for (iter = players.begin(); iter != players.end(); iter++)
	{
		if (iter->first == seat_id && iter->second && iter->second->isMainChar())
		{
			return true;
		}
	}

	return false;
}

NS_PAIGOW_END