#ifndef __PAI_GOW_HAND_CARDS_PANEL_H__
#define __PAI_GOW_HAND_CARDS_PANEL_H__
#include <vector>
#include "PaiGowCardView.h"

NS_PAIGOW_BEGIN

class PaiGowHandCardsPanel:cocos2d::Node
{
public:
	PaiGowHandCardsPanel();
	~PaiGowHandCardsPanel();

	void push(int index);
	void pull(int index);
	///void other

private:
	static const cocos2d::Vec2 key_points[6];
	std::vector<PaiGowCardView*> m_cards;
};

NS_PAIGOW_END

#endif // !__PAI_GOW_HAND_CARDS_PANEL_H__
