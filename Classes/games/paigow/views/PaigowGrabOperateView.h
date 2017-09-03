#ifndef __PAI_GOW_GRAB_OPERATE_VIEW_H__
#define __PAI_GOW_GRAB_OPERATE_VIEW_H__
#include "core/scene/BaseUI.h"

NS_PAIGOW_BEGIN

class PaigowGrabOperateView :public core::IBaseUI
{
public:
	static PaigowGrabOperateView* create();
	PaigowGrabOperateView() :IBaseUI() {};
	bool initWithFile(const std::string fileName) override;
private:

};

NS_PAIGOW_END

#endif
