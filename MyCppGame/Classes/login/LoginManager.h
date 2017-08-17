#pragma once
#include "utils\CommonMacros.h"
#include "LoginView.h"

NS_LOGIN_BEGIN

class LoginManager
{
	SINGLETON(LoginManager)
public:
		void init();
		void dispose();
private:
	LoginView* m_view = nullptr;
};

NS_LOGIN_END