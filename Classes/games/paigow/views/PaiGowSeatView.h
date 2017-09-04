#ifndef __PAI_GOW_SEAT_VIEW_H__
#define __PAI_GOW_SEAT_VIEW_H__
#include "core/scene/BaseUI.h"
#include "games/paigow/PaiGowPlayer.h"

NS_PAIGOW_BEGIN

class PaiGowSeatView :public core::IBaseUI
{
public:
	static PaiGowSeatView* create();
	PaiGowSeatView() :IBaseUI() {};
	bool initWithFile(const std::string fileName) override;
	void initView(PaiGowPlayer* player);
	void reset();
	void showBanker();
	void setStatus(const std::string status,bool isHide = false);
	void showResult(int result);
	void showBet(uint32_t bet1, uint32_t bet2,cocos2d::Vec2 pos);
	void showOffline(bool b);
private:
	static const  cocos2d::Vec2 bet_positions[];
	PaiGowPlayer* m_player;
};

NS_PAIGOW_END

#endif
