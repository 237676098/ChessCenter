#ifndef __LOGIN_VIEW_H__
#define __LOGIN_VIEW_H__
#include "core/scene/scene.h"

NS_LOGIN_BEGIN

class LoginView:public core::IBaseUI
{
public:
	static LoginView* create();
	LoginView():IBaseUI() {};
	bool initWithFile(const std::string fileName) override;

	

private:
	void onLoginBtnClick(Ref* btn);
};


NS_LOGIN_END

#endif
