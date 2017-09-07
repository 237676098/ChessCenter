#ifndef __PAI_GOW_COLLOCATION_OPERATE_VIEW_H__
#define __PAI_GOW_COLLOCATION_OPERATE_VIEW_H__
#include "core/scene/BaseUI.h"

NS_PAIGOW_BEGIN
class PaiGowViewController;

class PaigowCollocationOperateView :public core::IBaseUI
{
public:
	static PaigowCollocationOperateView* create(PaiGowViewController*);
	PaigowCollocationOperateView(PaiGowViewController* controller) :
		m_controller(controller),
		IBaseUI() {};
	bool initWithFile(const std::string fileName) override;

private:
	PaiGowViewController* m_controller;
	void onClickTip(Ref* ref);
	void onClickSure(Ref* ref);

};

NS_PAIGOW_END

#endif
