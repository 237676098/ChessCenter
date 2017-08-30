#ifndef __PAI_GOW_LOGIC_H__
#define __PAI_GOW_LOGIC_H__
#include <stdint.h>
#include "utils/CommonMacros.h"


NS_PAIGOW_BEGIN

typedef uint16_t Card;
typedef uint16_t CardValue;
typedef uint16_t CardNumber;

//0~8代表序号
//9~16代表数值大小
const Card cards[21] = {
	//文牌
	0x010c, 0x0202, 0x0308, 0x0404, 0x050a, 0x0606, 0x0704, 0x080b, 0x090a, 0x0a07, 0x0b06,
	//武牌
	0x0c09, 0x0d09, 0x0e08, 0x0f08, 0x1007, 0x1107, 0x1205, 0x1305,
	//至尊
	0x1406, 0x1503,
};


#define MASK_NUMBER					0xFF00								//序号掩码
#define	MASK_VALUE					0x00FF								//数值掩码

enum CardGroupType
{
	CGTypeZhiZunBao		= 9,				//至尊宝
	CGDoublePen			= 8,				//双文牌
	CGDoubleMix			= 7,				//双杂牌
	CGHeavenNine		= 6,				//天王牌
	CGEarthNine			= 5,				//地王牌
	CGHeavenEight		= 4,				//天杠牌
	CGEarthEight		= 3,				//地杠牌
	CGHeavenHighNine	= 2,				//天高九
	CGEarthHighNine		= 1,				//地高九
	CGMix				= 0,				//杂牌
};

typedef struct _CardGroup
{
	CardGroupType type;				//牌组类型
	CardValue value;				//牌组数值
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

