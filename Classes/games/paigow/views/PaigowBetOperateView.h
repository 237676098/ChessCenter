#ifndef __PAI_GOW_BET_OPERATE_VIEW_H__
#define __PAI_GOW_BET_OPERATE_VIEW_H__
#include "core/scene/BaseUI.h"

NS_PAIGOW_BEGIN

class PaigowBetOperateView :public core::IBaseUI
{
public:
	static PaigowBetOperateView* create();
	PaigowBetOperateView() :IBaseUI() {};
	bool initWithFile(const std::string fileName) override;
	void update();
	void onClickChip(Ref* ref);

	//1为庄家等待其他玩家抢庄  2:还未抢庄 3:已经抢庄了
	void show(int status);

private:
	std::vector<uint32_t> m_chips;
	static const uint32_t m_chips_level[5];
};

NS_PAIGOW_END

#endif
