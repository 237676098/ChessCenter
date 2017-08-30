#ifndef __PAI_GOW_LOGIC_H__
#define __PAI_GOW_LOGIC_H__
#include <stdint.h>
#include "utils/CommonMacros.h"


NS_PAIGOW_BEGIN

typedef uint16_t Card;
typedef uint16_t CardValue;
typedef uint16_t CardNumber;

//0~8�������
//9~16������ֵ��С
const Card cards[21] = {
	//����
	0x010c, 0x0202, 0x0308, 0x0404, 0x050a, 0x0606, 0x0704, 0x080b, 0x090a, 0x0a07, 0x0b06,
	//����
	0x0c09, 0x0d09, 0x0e08, 0x0f08, 0x1007, 0x1107, 0x1205, 0x1305,
	//����
	0x1406, 0x1503,
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
	
private:

};

NS_PAIGOW_END
#endif // !PaiGowLogic

