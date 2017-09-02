#include "RoomJoinWindow.h"
#include "games/game.h"
NS_LOBBY_BEGIN
void RoomJoinWindow::onLoadCompleted()
{

	auto center = m_node_csb->getChildByName("center");
	/*
	Button* paigow_btn = dynamic_cast<Button*>(center->getChildByName("m_node_paigow")->getChildByName("btn"));
	paigow_btn->addClickEventListener([this](Ref* btn)->void {
		CCLOG("click  paigow");
	});*/

	for (size_t i = 0; i < 10; i++)
	{
		auto btn = center->getChildByName("node_number")->getChildByName<Button*>("m_btn_num" + std::to_string(i));
		btn->setTag(i);
		btn->addClickEventListener(std::bind(&RoomJoinWindow::onClickNumber,this,std::placeholders::_1));
	}

	center->getChildByName("node_number")->getChildByName<Button*>("m_btn_clear")->addClickEventListener(
		std::bind(&RoomJoinWindow::onClearNumber, this, std::placeholders::_1)
	);

	center->getChildByName("node_number")->getChildByName<Button*>("m_btn_delete")->addClickEventListener(
		std::bind(&RoomJoinWindow::onDeleteNumber, this, std::placeholders::_1)
	);

	onClearNumber(nullptr);
}

void RoomJoinWindow::onClickCloseBtn(Ref * btn)
{
	core::WindowManager::getInstance()->close(RoomJoinWindow::s_id);
}

void RoomJoinWindow::onClickNumber(Ref * ref)
{

	if (m_numbers.size() == 6)
	{
		return;
	}

	auto btn_cast = dynamic_cast<Button*>(ref);
	int num = btn_cast->getTag();

	m_numbers.push_back(num);
	int number_index = m_numbers.size();
	auto parent_node = m_node_csb->getChildByName("center")->getChildByName("img_number");
	auto tf = parent_node->getChildByName<Text*>("m_tf_num" + std::to_string(number_index));
	tf->setString(std::to_string(num));
	tf->setVisible(true);

	if (m_numbers.size() == 6)
	{
		std::string s;
		for (size_t i = 0; i < m_numbers.size(); i++)
		{
			s.append(std::to_string(m_numbers[i]));
		}

		game::GameManager::getInstance()->joinMatch(std::stoi(s));
	}

}
void RoomJoinWindow::onClearNumber(Ref* ref)
{

	m_numbers.clear();
	for (size_t i = 0; i < 6; i++)
	{
		auto parent_node = m_node_csb->getChildByName("center")->getChildByName("img_number");
		auto tf = parent_node->getChildByName<Text*>("m_tf_num" + std::to_string(i +  1));
		tf->setVisible(false);
	}
}
void RoomJoinWindow::onDeleteNumber(Ref* ref)
{
	int number_index = m_numbers.size() - 1;
	//int number = m_numbers[number_index];
	auto parent_node = m_node_csb->getChildByName("center")->getChildByName("img_number");
	auto tf = parent_node->getChildByName<Text*>("m_tf_num" + std::to_string(number_index + 1));
	tf->setVisible(false);

	m_numbers.pop_back();
}
NS_LOBBY_END
