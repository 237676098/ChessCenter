#ifndef __PAIGOW_TABLE_VIEW_H__
#define __PAIGOW_TABLE_VIEW_H__
#include "core/scene/BaseUI.h"

NS_PAIGOW_BEGIN

class PaigowTableView:public core::IBaseUI
{
public:
	static PaigowTableView* create();
	PaigowTableView():IBaseUI() {};
	bool initWithFile(const std::string fileName) override;

private:

};

NS_PAIGOW_END

#endif
