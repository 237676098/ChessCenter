#ifndef __PAI_GOW_BET_OPERATE_VIEW_H__
#define __PAI_GOW_BET_OPERATE_VIEW_H__
#include "core/scene/BaseUI.h"
#include "core/event/EventManager.h"

NS_PAIGOW_BEGIN

class PaigowBetOperateView :public core::IBaseUI,public core::EventHandler
{
public:
	static PaigowBetOperateView* create();
	PaigowBetOperateView() :IBaseUI() {};
	bool initWithFile(const std::string fileName) override;
	void update();
	virtual int HandleEvent(core::Event *evt) override;
private:

};

NS_PAIGOW_END

#endif
