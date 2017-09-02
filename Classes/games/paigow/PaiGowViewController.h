#ifndef __PAI_GOW_VIEW_CONTROLLER__
#define __PAI_GOW_VIEW_CONTROLLER__
#include "core/event/EventManager.h"
#include "PaiGowSnapshot.h"
#include "views/PaigowTableView.h"
#include "views/PaigowWaitOperateView.h"
#include "views/PaiGowSeatView.h"
#include "views/PaigowBetOperateView.h"

NS_PAIGOW_BEGIN

class PaiGowPlayer;

class PaiGowViewController:public core::EventHandler
{
public:
	PaiGowViewController(PaiGowSnaptShot* data);
	~PaiGowViewController() {};

	void init();

	int HandleEvent(core::Event* evt) override;


private:
	void addSeat(PaiGowPlayer* seat);
	void deleteSeat(int seat_id);

private:
	cocos2d::Vec2 seatPos(PaiGowPlayer * player);
	cocos2d::Vec2 seatPos(int seat_id);

private:
	PaiGowSnaptShot* m_data;
	PaigowTableView* m_view;
	PaiGowWaitOperateView* m_wait_operate_view;
	std::map<uint32_t,PaiGowSeatView*> m_seat_views;
	PaigowBetOperateView* m_bet_operate_view;
};

NS_PAIGOW_END

#endif // !__PAI_GOW_VIEW_CONTROLLER__