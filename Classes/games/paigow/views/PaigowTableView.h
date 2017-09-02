#ifndef __PAIGOW_TABLE_VIEW_H__
#define __PAIGOW_TABLE_VIEW_H__
#include "core/scene/BaseUI.h"
#include "games/paigow/PaiGowSnapshot.h"

NS_PAIGOW_BEGIN

class PaigowTableView :public core::IBaseUI
{
public:
	static PaigowTableView* create();
	PaigowTableView():m_data(nullptr),IBaseUI() {};
	bool initWithFile(const std::string fileName) override;
	void initView(PaiGowSnaptShot* data);
private:
	void updateDesc();

private:
	PaiGowSnaptShot* m_data;
};

NS_PAIGOW_END

#endif
