#include "PaigowTableView.h"
#include "utils/LanguageManager.h"
#include "games/paigow/PaiGowSnapshot.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "utils/stdtostring.h"
#endif

NS_PAIGOW_BEGIN

PaigowTableView * PaigowTableView::create()
{
	PaigowTableView* view = new (std::nothrow) PaigowTableView();
	if (view && view->init())
	{
		view->autorelease();
		view->initWithFile("paigow/paigow_table");
		return view;
	}
	CC_SAFE_DELETE(view);
	return nullptr;
}


bool PaigowTableView::initWithFile(const std::string fileName)
{
	if (!IBaseUI::initWithFile(fileName))
	{
		return false;
	}
	return true;
}

void PaigowTableView::initView(PaiGowSnaptShot* data)
{
	m_data = data;
	//TODO  ÅÆ×À³õÊ¼»¯
	updateDesc();
}

void PaigowTableView::updateDesc()
{
	std::string desc = "";
	desc.append(core::LanguageManager::getInstance()->get("room_id"));
	desc.append(std::to_string(m_data->room_id));
	m_csb->getChildByName<Text*>("text_des")->setString(desc);
}

NS_PAIGOW_END