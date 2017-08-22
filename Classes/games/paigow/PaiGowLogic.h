#ifndef __PAI_GOW_LOGIC_H__
#define __PAI_GOW_LOGIC_H__
#include <stdint.h>
#include "utils/CommonMacros.h"


NS_PAIGOW_BEGIN

typedef uint16_t Card;
typedef uint16_t CardValue;
typedef uint16_t CardType;
typedef uint16_t CardNumber;

//0~3代表type 文牌 杂牌 至尊牌
//4~11代表序号
//12~15代表点数
const Card cards[21] = {
	0x00fc,0x00e2,0x00d8,0x00c4,0x00ba,0x00a6,0x0094,0x008b,0x007a,0x0067,0x0056,				//文牌
	0x1049,0x1049,0x1038,0x1038,0x1027,0x1027,0x1015,0x1015,									//杂牌
	0x2003,0x2006																				//至尊牌
};

//数值掩码
#define	MASK_TYPE					0xF000								//类型掩码
#define MASK_NUMBER					0x0FF0								//序号掩码
#define	MASK_VALUE					0x000F								//数值掩码

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

