#include "AgreementTipsWindow.h"
#include "AgreementTipsWindow.h"

NS_LOGIN_BEGIN

void AgreementTipsWindow::onLoadCompleted()
{
	CCLOG("AgreementTipsWindow onLoadCompleted");
}

void AgreementTipsWindow::onClickCloseBtn(Ref * btn)
{
	core::WindowManager::getInstance()->close(AgreementTipsWindow::s_id);
}

NS_LOGIN_END