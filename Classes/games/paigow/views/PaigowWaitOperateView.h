#ifndef __PAI_GOW_WAIT_OPERATE_VIEW_H__
#define __PAI_GOW_WAIT_OPERATE_VIEW_H__
#include "core/scene/BaseUI.h"

NS_PAIGOW_BEGIN

class PaiGowWaitOperateView :public core::IBaseUI
{
public:
	static PaiGowWaitOperateView* create();
	PaiGowWaitOperateView():IBaseUI() {};
	bool initWithFile(const std::string fileName) override;
	void update();
private:
	
};

NS_PAIGOW_END

#endif
