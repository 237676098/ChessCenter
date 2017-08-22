#ifndef __PAI_GOW_LOGIC_H__
#define __PAI_GOW_LOGIC_H__
#include <stdint.h>
#include "utils/CommonMacros.h"


NS_PAIGOW_BEGIN

typedef uint16_t Card;
typedef uint16_t CardValue;
typedef uint16_t CardType;
typedef uint16_t CardNumber;

//0~3����type ���� ���� ������
//4~11�������
//12~15�������
const Card cards[21] = {
	0x00fc,0x00e2,0x00d8,0x00c4,0x00ba,0x00a6,0x0094,0x008b,0x007a,0x0067,0x0056,				//����
	0x1049,0x1049,0x1038,0x1038,0x1027,0x1027,0x1015,0x1015,									//����
	0x2003,0x2006																				//������
};

//��ֵ����
#define	MASK_TYPE					0xF000								//��������
#define MASK_NUMBER					0x0FF0								//�������
#define	MASK_VALUE					0x000F								//��ֵ����

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
	static int compare(const Card* card1, const Card* card2);
	static void parseGroup(const Card* card,CardGroup& group);
	static void sortGroup(const Card* card, Card* sortedCard);
	inline static CardValue getValue(const Card& card) { return card&MASK_VALUE; };
	inline static CardType getType(const Card& card) { return card&MASK_TYPE; };
	inline static CardNumber getNumber(const Card& card) { return card&MASK_NUMBER; };
private:

};

NS_PAIGOW_END
#endif // !PaiGowLogic

