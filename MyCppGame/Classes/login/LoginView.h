#pragma once
#include "utils\CommonMacros.h"
#include "core\scene\scene.h"

NS_LOGIN_BEGIN

class LoginView:public core::IBaseUI
{
public:
	static LoginView* create();
	LoginView():IBaseUI() {};
	bool initWithFile(const std::string fileName);

	

private:
	void onLoginBtnClick(Ref* btn);
};


NS_LOGIN_END
