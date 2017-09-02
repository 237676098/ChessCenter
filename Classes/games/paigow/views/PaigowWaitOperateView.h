#ifndef __PAI_GOW_WAIT_OPERATE_VIEW_H__
#define __PAI_GOW_WAIT_OPERATE_VIEW_H__
#include "core/scene/BaseUI.h"
#include "games/paigow/PaiGowSnapshot.h"

NS_PAIGOW_BEGIN

class PaiGowWaitOperateView :public core::IBaseUI
{
public:
	static PaiGowWaitOperateView* create();
	PaiGowWaitOperateView():m_data(nullptr),IBaseUI() {};
	bool initWithFile(const std::string fileName) override;
	void initView(PaiGowSnaptShot* data);
private:
	PaiGowSnaptShot* m_data;
};

NS_PAIGOW_END

#endif
