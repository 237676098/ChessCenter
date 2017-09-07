#ifndef __PAI_GOW_VIEW_CONTROLLER__
#define __PAI_GOW_VIEW_CONTROLLER__
#include "core/event/EventManager.h"
#include "PaiGowSnapshot.h"
#include "views/PaigowTableView.h"
#include "views/PaigowWaitOperateView.h"
#include "views/PaiGowSeatView.h"
#include "views/PaigowBetOperateView.h"
#include "views/PaigowGrabOperateView.h"
#include "views/PaiGowHandCardsPanel.h"
#include "views/PaigowCollocationOperateView.h"

NS_PAIGOW_BEGIN

class PaiGowPlayer;

class PaiGowViewController:public core::EventHandler
{
public:
	PaiGowViewController(PaiGowSnaptShot* data);
	~PaiGowViewController() {};

	void init();
	void dispose();

	int HandleEvent(core::Event* evt) override;


//界面间的交互接口
public:
	void onClickCollcationTips();
	void onClickCollcationSure();

private:
	void addSeat(PaiGowPlayer* seat);
	void deleteSeat(uint32_t seat_id);

private:
	cocos2d::Vec2 seatPos(PaiGowPlayer * player);
	cocos2d::Vec2 seatPos(int seat_id);
	cocos2d::Vec2 betPos(PaiGowPlayer * player);
	cocos2d::Vec2 betPos(int seat_id);
	cocos2d::Vec2 handCardsPos(int seat_index);

private:
	PaiGowSnaptShot* m_data;
	PaigowTableView* m_view;
	PaiGowWaitOperateView* m_wait_operate_view;
	PaigowGrabOperateView* m_grab_operate_view;
	std::map<uint32_t,PaiGowSeatView*> m_seat_views;
	std::map<uint32_t, PaiGowHandCardsPanel*> m_handcards_views;
	PaigowBetOperateView* m_bet_operate_view;
	PaigowCollocationOperateView* m_collocation_operate_view;
};

NS_PAIGOW_END

#endif // !__PAI_GOW_VIEW_CONTROLLER__