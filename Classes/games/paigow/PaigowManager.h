#ifndef __PAIGOW_MANAGER_H__
#define __PAIGOW_MANAGER_H__
#include <functional>
#include "PaiGowLogic.h"
#include "core/network/socket/SocketManager.h"
#include "PaiGowSnapshot.h"
#include "core/event/EventManager.h"
#include "PaiGowViewController.h"

NS_PAIGOW_BEGIN

//class  PaiGowProxy;

enum class TableState
{
	Wait = 1,
	GrabBanker,
	Bet,
	Collocation,
	Result,
	Unkown
};


class PaigowManager
{
	SINGLETON(PaigowManager);
public:
	void init(const proto3_proto::S2C_MatchSnapshot& shot);
	void dispose();

private:
	friend class PaiGowProxy;
	PaiGowProxy* m_proxy;
	PaiGowSnaptShot* m_data;
	PaiGowViewController* m_controller;
};

NS_PAIGOW_END
#endif