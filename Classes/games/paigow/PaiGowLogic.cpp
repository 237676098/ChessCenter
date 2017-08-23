#include "PaiGowLogic.h"

NS_PAIGOW_BEGIN

int PaiGowLogic::compare(const Card * card1, const Card * card2)
{
	//先进行排序
	Card sortedGroup1[2];
	Card sortedGroup2[2];
	sortGroup(card1,sortedGroup1);
	sortGroup(card2, sortedGroup2);

	//解析牌组数据
	CardGroup  group1,group2;
	parseGroup(sortedGroup1,group1);
	parseGroup(sortedGroup2, group2);

	if (group1.type > group2.type)
	{
		return 1;
	}
	else if (group1.type < group2.type)
	{
		return -1;
	}
	else
	{
		CardNumber number1 = getNumber(sortedGroup1[0]);
		CardNumber number2 = getNumber(sortedGroup2[0]);

		if (number1 > number2)
		{
			return 1;
		}
		else if (number1 < number2)
		{
			return -1;
		}
		else
		{
			return 0;
		}

	}

}

void PaiGowLogic::parseGroup(const Card * card, CardGroup & group)
{

	Card card1 = card[0];
	Card card2 = card[1];
	
	CardType type1 = getType(card1);
	CardType type2 = getType(card2);

	CardNumber number1 = getNumber(card1);
	CardNumber number2 = getNumber(card2);

	CardValue value1 = getValue(card1);
	CardValue value2 = getValue(card2);

	//解析牌组值
	group.value = (value1 + value2) % 10;


	//解析牌组类型
	if (type1 == 0x2000 && type2 == 0x2000)
	{
		group.type = CGTypeZhiZunBao;
	}
	else if(card1 == card2)
	{
		group.type = CGDoublePen;
	}
	else if(type1 == 0x1000 && type2 == 0x1000 & value1 == value2)
	{
		group.type = CGDoubleMix;
	}
	else if ((card1 == 0x00fc || card2 == 0x00fc) & (value1 + value2) == 21)
	{
		group.type = CGHeavenNine;
	}
	else if ((card1 == 0x00e2 || card2 == 0x00e2) & (value1 + value2) == 11)
	{
		group.type = CGEarthNine;
	}
	else if ((card1 == 0x00fc || card2 == 0x00fc) & (value1 + value2) == 20)
	{
		group.type = CGHeavenEight;
	}
	else if ((card1 == 0x00e2 || card2 == 0x00e2) & (value1 + value2) == 10)
	{
		group.type = CGEarthEight;
	}
	else if ((card1 == 0x00fc || card2 == 0x00fc) & (value1 + value2) == 19)
	{
		group.type = CGHeavenHighNine;
	}
	else if ((card1 == 0x00e2 || card2 == 0x00e2) & (value1 + value2) == 9)
	{
		group.type = CGEarthHighNine;
	}
	else
	{
		group.type = CGMix;
	}
}

void PaiGowLogic::sortGroup(const Card * card, Card * sortedCard)
{
	CardNumber number1 = getNumber(card[0]);
	CardNumber number2 = getNumber(card[1]);
	if (number1 < number2)
	{
		sortedCard[0] = card[1];
		sortedCard[1] = card[0];
	}
	else
	{
		sortedCard[0] = card[0];
		sortedCard[1] = card[1];
	}
}

NS_PAIGOW_END