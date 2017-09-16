#ifndef __PAI_GOW_HAND_CARDS_PANEL_H__
#define __PAI_GOW_HAND_CARDS_PANEL_H__
#include <vector>
#include "PaiGowCardView.h"

NS_PAIGOW_BEGIN

class PaiGowHandCardsPanel:public cocos2d::Node
{
public:
	PaiGowHandCardsPanel();
	~PaiGowHandCardsPanel();
	static PaiGowHandCardsPanel* create();
	void clear();

	void push(uint32_t index);										//��ĳһ��������ȥ
	void pull(uint32_t index);										//��ĳһ����������
	void setCards(const std::vector<Card>& cards,bool isShow = false);				//��ʼ����
	void playCollocation();										//����������
	void playCollocation(const std::vector<Card>& cards);		//���Լ�����
	void getResultCards(std::vector<Card>& first, std::vector<Card>& second) const;
	void setInteractive(bool b) { m_interactive = b; };


private:
	void onClickCard(PaiGowCardView* view);
	void push(PaiGowCardView* view);
	void pull(PaiGowCardView* view);
private:
	static const cocos2d::Vec2 key_points[6];
	std::vector<PaiGowCardView*> m_cards;
	bool m_interactive;
};

NS_PAIGOW_END

#endif // !__PAI_GOW_HAND_CARDS_PANEL_H__
