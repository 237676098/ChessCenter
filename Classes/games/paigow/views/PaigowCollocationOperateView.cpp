#include "PaigowCollocationOperateView.h"
#include "cocos2d.h"
#include "core/network/socket/SocketManager.h"

USING_NS_CC;
NS_PAIGOW_BEGIN

PaigowCollocationOperateView * PaigowCollocationOperateView::create()
{
	PaigowCollocationOperateView* view = new (std::nothrow) PaigowCollocationOperateView();
	if (view && view->init())
	{
		view->autorelease();
		view->initWithFile("paigow/paigow_collocation_operate_view");
		return view;
	}
	CC_SAFE_DELETE(view);
	return nullptr;
}

bool PaigowCollocationOperateView::initWithFile(const std::string fileName)
{
	if (!IBaseUI::initWithFile(fileName))
	{
		return false;
	}

	m_csb->getChildByName<Button*>("btn_tip")->addClickEventListener(
		std::bind(&PaigowCollocationOperateView::onClickTip, this, std::placeholders::_1)
	);

	m_csb->getChildByName<Button*>("btn_sure")->addClickEventListener(
		std::bind(&PaigowCollocationOperateView::onClickSure, this, std::placeholders::_1)
	);

	return true;
}

void PaigowCollocationOperateView::onClickTip(Ref * ref)
{
}

void PaigowCollocationOperateView::onClickSure(Ref * ref)
{
}


NS_PAIGOW_END