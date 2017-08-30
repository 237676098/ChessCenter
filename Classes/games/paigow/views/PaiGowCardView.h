#ifndef __PAI_GOW_CARD_VIEW_H__
#define __PAI_GOW_CARD_VIEW_H__
#include "core/scene/BaseUI.h"
#include "games/paigow/PaiGowLogic.h"

NS_PAIGOW_BEGIN

class PaiGowCardView:public core::IBaseUI
{
public:
	static PaiGowCardView* create();
	PaiGowCardView():IBaseUI() {};
	bool initWithFile(const std::string fileName) override;
	void setCard(const Card& card);
	void turnBack(bool isAnimation);
	void turnFront(bool isAnimation);
private:
	Card m_card;
};

NS_PAIGOW_END

#endif
