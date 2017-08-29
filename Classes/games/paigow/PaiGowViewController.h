#ifndef __PAI_GOW_VIEW_CONTROLLER__
#define __PAI_GOW_VIEW_CONTROLLER__
#include "core/event/EventManager.h"
#include "PaiGowSnapshot.h"
#include "views/PaigowTableView.h"
#include "views/PaigowWaitOperateView.h"
#include "views/PaiGowSeatView.h"
#include "views/PaigowBetOperateView.h"

NS_PAIGOW_BEGIN


class PaiGowViewController:public core::EventHandler
{
public:
	PaiGowViewController(PaiGowSnaptShot* data): m_data(data) {};
	~PaiGowViewController() {};

	void init();

	int HandleEvent(core::Event* evt) override;

private:
	PaiGowSnaptShot* m_data;
	PaigowTableView* m_view;
	PaiGowWaitOperateView* m_wait_operate_view;
	PaiGowSeatView* m_seat_view;
	PaigowBetOperateView* m_bet_operate_view;
};

NS_PAIGOW_END

#endif // !__PAI_GOW_VIEW_CONTROLLER__