#include "PaiGowSeatView.h"
#include "cocos2d.h"

USING_NS_CC;
NS_PAIGOW_BEGIN

PaiGowSeatView * PaiGowSeatView::create()
{
	PaiGowSeatView* view = new (std::nothrow) PaiGowSeatView();
	if (view && view->init())
	{
		view->autorelease();
		view->initWithFile("paigow/paigow_seat");
		return view;
	}
	CC_SAFE_DELETE(view);
	return nullptr;
}

bool PaiGowSeatView::initWithFile(const std::string fileName)
{
	if (!IBaseUI::initWithFile(fileName))
	{
		return false;
	}
	return true;
}

void PaiGowSeatView::update()
{
}

NS_PAIGOW_END