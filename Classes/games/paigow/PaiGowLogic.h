#ifndef __PAI_GOW_LOGIC_H__
#define __PAI_GOW_LOGIC_H__
#include <stdint.h>
#include "utils/CommonMacros.h"
#include <string>
#include <map>


NS_PAIGOW_BEGIN

typedef uint16_t Card;
typedef uint16_t CardValue;
typedef uint16_t CardNumber;

//0~8�������
//9~16������ֵ��С
const Card cards[22] = {
	//����
	0x010c, 0x0202, 0x0308, 0x0404, 0x050a, 0x0606, 0x0704, 0x080b, 0x090a, 0x0a07, 0x0b06,
	//����
	0x0c09, 0x0d09, 0x0e08, 0x0f08, 0x1007, 0x1107, 0x1205, 0x1305,
	//����
	0x1406, 0x1503,
	//δ��ʼ������
	0x0000
};


#define MASK_NUMBER					0xFF00								//�������
#define	MASK_VALUE					0x00FF								//��ֵ����

enum CardGroupType
{
	CGTypeZhiZunBao		= 9,				//����
	CGDoublePen			= 8,				//˫����
	CGDoubleMix			= 7,				//˫����
	CGHeavenNine		= 6,				//������
	CGEarthNine			= 5,				//������
	CGHeavenEight		= 4,				//�����
	CGEarthEight		= 3,				//�ظ���
	CGHeavenHighNine	= 2,				//��߾�
	CGEarthHighNine		= 1,				//�ظ߾�
	CGMix				= 0,				//����
};

typedef struct _CardGroup
{
	CardGroupType type;				//��������
	CardValue value;				//������ֵ
}CardGroup;

class PaiGowLogic
{
public:
	inline static bool isWen(const Card& card);
	inline static bool isWu(const Card& card);
	static int compare(const Card* card1, const Card* card2);
	static void parseGroup(const Card* card,CardGroup& group);
	static void sortGroup(const Card* card, Card* sortedCard);
	inline static CardValue getValue(const Card& card) { return card&MASK_VALUE; };
	inline static CardNumber getNumber(const Card& card) { return card&MASK_NUMBER; };
	static std::string getCardGroupName(const Card* card);


public:
	static std::map<Card, std::string> CreateCardStringMap()
	{
		std::map<Card, std::string> cardString;
		cardString[0x010c] = "card_group_name_tian";
		cardString[0x0202] = "card_group_name_di";
		cardString[0x0308] = "card_group_name_ren";
		cardString[0x0404] = "card_group_name_e";
		cardString[0x050a] = "card_group_name_chang";
		cardString[0x0606] = "card_group_name_chang";
		cardString[0x0704] = "card_group_name_chang";
		cardString[0x080b] = "card_group_name_duan";
		cardString[0x090a] = "card_group_name_duan";
		cardString[0x0a07] = "card_group_name_duan";
		cardString[0x0b06] = "card_group_name_duan";
		cardString[0x0d09] = "card_group_name_za";
		cardString[0x0c09] = "card_group_name_za";
		cardString[0x0e08] = "card_group_name_za";
		cardString[0x0f08] = "card_group_name_za";
		cardString[0x1007] = "card_group_name_za";
		cardString[0x1107] = "card_group_name_za";
		cardString[0x1205] = "card_group_name_za";
		cardString[0x1305] = "card_group_name_za";
		return cardString;
	}
	const static std::map<Card, std::string> card_str;
};
NS_PAIGOW_END
#endif // !PaiGowLogic

