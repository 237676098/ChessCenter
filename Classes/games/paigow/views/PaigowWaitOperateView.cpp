#include "PaigowWaitOperateView.h"
#include "cocos2d.h"

USING_NS_CC;
NS_PAIGOW_BEGIN

PaiGowWaitOperateView * PaiGowWaitOperateView::create()
{
	PaiGowWaitOperateView* view = new (std::nothrow) PaiGowWaitOperateView();
	if (view && view->init())
	{
		view->autorelease();
		view->initWithFile("paigow/paigow_wait_operate_view");
		return view;
	}
	CC_SAFE_DELETE(view);
	return nullptr;
}

bool PaiGowWaitOperateView::initWithFile(const std::string fileName)
{
	if (!IBaseUI::initWithFile(fileName))
	{
		return false;
	}
	return true;
}

void PaiGowWaitOperateView::update()
{
}

NS_PAIGOW_END