#ifndef __PAIGOW_MANAGER_H__
#define __PAIGOW_MANAGER_H__
#include <functional>
#include "PaiGowLogic.h"
#include "views/PaigowTableView.h"
#include "views/PaigowWaitOperateView.h"
#include "views/PaiGowSeatView.h"
#include "views/PaigowBetOperateView.h"
#include "core/network/socket/SocketManager.h"

NS_PAIGOW_BEGIN

class  PaiGowProxy;

typedef enum _PGTableState
{
	PGST_Wait = 1,
	PGST_GrabBanker,
	PGST_Bet,
	PGST_Collocation,
	PGST_Result
}PGTableState;


class PaigowManager
{
	SINGLETON(PaigowManager);
public:
	void init();
	void dispose();

private:
	friend class PaiGowProxy;
	PaiGowProxy* m_proxy;
	PaigowTableView* m_view;
	PaiGowWaitOperateView* m_wait_operate_view;
	PaiGowSeatView* m_seat_view;
	PaigowBetOperateView* m_bet_operate_view;
};

NS_PAIGOW_END
#endif