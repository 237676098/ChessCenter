#ifndef __PAI_GOW_CARD_GRUOP_VIEW_H__
#define __PAI_GOW_CARD_GROUP_VIEW_H__
#include "PaiGowCardView.h"

NS_PAIGOW_BEGIN

class PaiGowCardGroupView :public cocos2d::Node
{
public:
	static PaiGowCardGroupView* create();
	PaiGowCardGroupView();
private:
	PaiGowCardView* m_cards;
};

NS_PAIGOW_END

#endif
