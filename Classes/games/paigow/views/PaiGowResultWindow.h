#ifndef __PAI_GOW_RESULT_WINDOW_H__
#define __PAI_GOW_RESULT_WINDOW_H__
#include "core/scene/scene.h"
#include "games/paigow/PaiGowResult.h"


NS_PAIGOW_BEGIN

class PaiGowViewController;
class PaiGowResultWindow :public core::IBaseWindow
{
public:
	const static WindowId s_id = ID_PAI_GOW_RESULT;
	PaiGowResultWindow(PaiGowViewController* controller, const std::vector<PaiGowResult*>& result)
		:m_controller(controller),
		m_results(result),
		core::IBaseWindow("paigow/paigow_result_view") {};
	void onLoadCompleted() override;
	void onClickCloseBtn(Ref* btn) override;
	void onClickSure(Ref * btn) const;
private:
	std::vector<PaiGowResult*> m_results;
	PaiGowViewController* m_controller;
};

NS_PAIGOW_END

#endif