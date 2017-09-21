#include "PaiGowPublicCardsView.h"
#include "games/paigow/PaiGowViewController.h"
#include "games/paigow/events/paigow_events.h"
#include <math.h>

NS_PAIGOW_BEGIN

PaiGowPublicCardsView::PaiGowPublicCardsView(PaiGowViewController* controller)
	:m_controller(controller)
{

}


PaiGowPublicCardsView::~PaiGowPublicCardsView()
{
}

PaiGowPublicCardsView * PaiGowPublicCardsView::create(PaiGowViewController* controller)
{
	PaiGowPublicCardsView* view = new (std::nothrow) PaiGowPublicCardsView(controller);
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
	size_t start_index = 0;
	for (size_t i = 0; i < card_views.size(); i++)
	{
		if (card_views[i]->getCard() == 0x0000)
		{
			start_index = i;
			break;
		}
	}
	
	int cur_seatid = 1;
	int cur_card = 0;
	int card_num = 4;
	for (size_t i = start_index; i < start_index +  4 * card_num; i++)
	{
		cocos2d::Vec2 scene_pos = m_controller->cardPos(cur_seatid, cur_card);
		cocos2d::Vec2 view_pos = this->convertToNodeSpace(scene_pos);
		CCLOG("seat:%d,index:%d", cur_seatid, cur_card);
		CCLOG("scene_pos:(%d,%d)", scene_pos.x, scene_pos.y);
		CCLOG("view_pos:(%d,%d)", view_pos.x, view_pos.y);
		cocos2d::DelayTime* delay = cocos2d::DelayTime::create((i - start_index) * 0.05);
		cocos2d::MoveTo* move_action = cocos2d::MoveTo::create(0.7,view_pos);
		cocos2d::ScaleTo* scale_action = cocos2d::ScaleTo::create(0.7,1);
		cocos2d::Spawn* spawn_acttion = cocos2d::Spawn::create(move_action, scale_action,NULL);
		cocos2d::CallFunc* complete_call = cocos2d::CallFunc::create([this,i,card_num,start_index] {
			//card_views[i]->removeFromParent();
			//card_views[i] = nullptr;
			CCLOG("i:%d", i);
			if (i == start_index + 4 * card_num - 1)
			{
				EventDealActionComplete event;
				core::EventManager::Instance().DispatchEvent(&event);
			}
		});
		cocos2d::Sequence* seq = cocos2d::Sequence::create(delay,spawn_acttion, complete_call,NULL);
		card_views[i]->runAction(seq);
		++cur_card;
		if (cur_card >= card_num)
		{
			++cur_seatid;
			cur_card = 0;
		}
	}
}

void PaiGowPublicCardsView::clear()
{
	std::vector<PaiGowCardView*>::iterator iter;
	for (iter = card_views.begin(); iter != card_views.end(); iter++)
	{
		if (*iter)
		{
			(*iter)->removeFromParent();
			(*iter) = nullptr;
		}
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
