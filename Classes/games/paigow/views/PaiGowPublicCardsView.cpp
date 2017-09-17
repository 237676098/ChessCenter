#include "PaiGowPublicCardsView.h"
#include <math.h>

NS_PAIGOW_BEGIN

PaiGowPublicCardsView::PaiGowPublicCardsView()
{
}


PaiGowPublicCardsView::~PaiGowPublicCardsView()
{
}

PaiGowPublicCardsView * PaiGowPublicCardsView::create()
{
	PaiGowPublicCardsView* view = new (std::nothrow) PaiGowPublicCardsView();
	if (view && view->init())
	{
		view->autorelease();
		return view;
	}
	CC_SAFE_DELETE(view);
	return nullptr;
}

void PaiGowPublicCardsView::initWithCard(const std::vector<Card>& cards)
{
	clear();
	std::vector<Card>::const_iterator iter;
	int index = 0;
	int card_count = cards.size();
	for (iter = cards.begin(); iter != cards.end(); iter++)
	{
		PaiGowCardView* view = PaiGowCardView::create();
		view->setCard(*iter);
		view->setScale(0.5);
		view->setPosition(pos(index, card_count));
		index++;
		this->addChild(view);
		card_views.push_back(view);
	}
}

void PaiGowPublicCardsView::playDeal()
{

}

void PaiGowPublicCardsView::clear()
{
	std::vector<PaiGowCardView*>::iterator iter;
	for (iter = card_views.begin(); iter != card_views.end(); iter++)
	{
		(*iter)->removeFromParent();
		(*iter) = nullptr;
	}

	card_views.clear();
}


cocos2d::Vec2 PaiGowPublicCardsView::pos(int index, int card_count)
{
	int rows = floor(index / 8);
	int columns = index % 8;
	int width = 30;
	int height = -66;

	int start_x ;
	int start_y;
	if (card_count == 32)
	{
		start_x = -105;
		start_y = 99;
	}
	else if (card_count == 16)
	{
		start_x = -105;
		start_y = 33;
	}
	return cocos2d::Vec2(start_x + columns * width,start_y + rows * height);
}

NS_PAIGOW_END
