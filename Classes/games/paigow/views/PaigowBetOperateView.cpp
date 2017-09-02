#include "PaigowBetOperateView.h"
#include "cocos2d.h"

USING_NS_CC;
NS_PAIGOW_BEGIN

PaigowBetOperateView * PaigowBetOperateView::create()
{
	PaigowBetOperateView* view = new (std::nothrow) PaigowBetOperateView();
	if (view && view->init())
	{
		view->autorelease();
		view->initWithFile("paigow/paigow_bet_operate_view");
		return view;
	}
	CC_SAFE_DELETE(view);
	return nullptr;
}

bool PaigowBetOperateView::initWithFile(const std::string fileName)
{
	if (!IBaseUI::initWithFile(fileName))
	{
		return false;
	}
	return true;
}

void PaigowBetOperateView::update()
{
}


NS_PAIGOW_END