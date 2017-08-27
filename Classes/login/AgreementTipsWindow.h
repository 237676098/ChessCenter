#ifndef __AGREEMENT_TIPS_WINDOW_H__
#define __AGREEMENT_TIPS_WINDOW_H__
#include "core/scene/scene.h"

NS_LOGIN_BEGIN

class AgreementTipsWindow:public core::IBaseWindow
{
public:
	const static WindowId s_id = ID_AgreementTips;
	AgreementTipsWindow() :core::IBaseWindow("agreement_tips_view") {};
	AgreementTipsWindow(int a) :core::IBaseWindow("agreement_tips_view") { CCLOG("a:%d", a); };
	AgreementTipsWindow(std::string str) :core::IBaseWindow("agreement_tips_view") { CCLOG("str:%s", str); };
	AgreementTipsWindow(std::string str,int a) :core::IBaseWindow("agreement_tips_view") { CCLOG("str:%s a:%d", str,a); };
	~AgreementTipsWindow() {};
	void onLoadCompleted() override;
	void onClickCloseBtn(Ref* btn) override;
private:

};

NS_LOGIN_END

#endif