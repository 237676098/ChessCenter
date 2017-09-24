#ifndef __PAI_GOW_MATCH_RESULT_WINDOW_H__
#define __PAI_GOW_MATCH_RESULT_WINDOW_H__
#include "core/scene/scene.h"

NS_PAIGOW_BEGIN

class PaiGowViewController;
class PaiGowMatchResultWindow :public core::IBaseWindow
{
public:
	const static WindowId s_id = ID_PAI_GOW_MATCH_RESULT;
	PaiGowMatchResultWindow(PaiGowViewController* controller)
		:m_controller(controller),
		core::IBaseWindow("paigow/paigow_match_result_view") {};
	void onLoadCompleted() override;
	void onClickBack(Ref* btn);
	void onClickShare(Ref * btn);
private:
	PaiGowViewController* m_controller;
};

NS_PAIGOW_END

#endif