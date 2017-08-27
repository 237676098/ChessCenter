#ifndef __PAI_GOW_SEAT_VIEW_H__
#define __PAI_GOW_SEAT_VIEW_H__
#include "core/scene/BaseUI.h"

NS_PAIGOW_BEGIN

class PaiGowSeatView :public core::IBaseUI
{
public:
	static PaiGowSeatView* create();
	PaiGowSeatView() :IBaseUI() {};
	bool initWithFile(const std::string fileName) override;
	void update();
private:

};

NS_PAIGOW_END

#endif
