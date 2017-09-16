#ifndef __AGREEMENT_TIPS_WINDOW_H__
#define __AGREEMENT_TIPS_WINDOW_H__
#include "core/scene/scene.h"

NS_LOGIN_BEGIN

class AgreementTipsWindow:public core::IBaseWindow
{
public:
	const static WindowId s_id = ID_AgreementTips;
	AgreementTipsWindow() :core::IBaseWindow("agreement_tips_view") {};
	~AgreementTipsWindow() {};
	void onLoadCompleted() override;
	void onClickCloseBtn(Ref* btn) override;
private:

};

NS_LOGIN_END

#endif