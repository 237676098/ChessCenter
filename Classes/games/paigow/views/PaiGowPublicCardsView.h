#ifndef __PAIGOW_PUBLIC_CARDS_VIEW_H__
#define __PAIGOW_PUBLIC_CARDS_VIEW_H__

#include "PaiGowCardView.h"
#include <vector>

NS_PAIGOW_BEGIN
class PaiGowViewController;

class PaiGowPublicCardsView :public cocos2d::Node
{
public:
	PaiGowPublicCardsView(PaiGowViewController* controller);
	~PaiGowPublicCardsView();
	static PaiGowPublicCardsView* create(PaiGowViewController* controller);

	void initWithCard(const std::vector<Card>& cards);
	void playDeal();
	void clear();


private:
	//根据卡牌索引获取其位置
	cocos2d::Vec2 pos(int index, int card_count);

private:
	std::vector<PaiGowCardView*> card_views;
	PaiGowViewController* m_controller;
};

NS_PAIGOW_END

#endif // !__PAIGOW_PUBLIC_CARDS_VIEW_H__

