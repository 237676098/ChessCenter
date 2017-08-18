#pragma once
#include "core\scene\scene.h"

NS_LOGIN_BEGIN

class AgreementTipsWindow:public core::IBaseWindow
{
public:
	AgreementTipsWindow() :core::IBaseWindow("agreement_tips_view") {};
	AgreementTipsWindow(int a) :core::IBaseWindow("agreement_tips_view") { CCLOG("a:%d", a); };
	AgreementTipsWindow(std::string str) :core::IBaseWindow("agreement_tips_view") { CCLOG("str:%s", str); };
	AgreementTipsWindow(std::string str,int a) :core::IBaseWindow("agreement_tips_view") { CCLOG("str:%s a:%d", str,a); };
	~AgreementTipsWindow() {};
	void onLoadCompleted() override;

private:

};


NS_LOGIN_END