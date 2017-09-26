#include "RoomCreateWindow.h"
#include "games/paigow/views/PaiGowSelectParamsView.h"
NS_LOBBY_BEGIN
void RoomCreateWindow::onLoadCompleted()
{

	auto center = m_node_csb->getChildByName("center");
	Button* paigow_btn = dynamic_cast<Button*>(center->getChildByName("m_node_paigow")->getChildByName("btn"));
	paigow_btn->addClickEventListener([this](Ref* btn)->void {
		CCLOG("click  paigow");
		core::WindowManager::getInstance()->open<chess::game::paigow::PaiGowSelectParamsView>();
	});
}

void RoomCreateWindow::onClickCloseBtn(Ref * btn)
{
	core::WindowManager::getInstance()->close(RoomCreateWindow::s_id);
}
NS_LOBBY_END
