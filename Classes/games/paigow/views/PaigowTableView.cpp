#include "PaigowTableView.h"

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

void PaigowTableView::initView()
{
	//TODO  ������ʼ��
}

NS_PAIGOW_END