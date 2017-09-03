#include "PaigowManager.h"
#include "PaiGowProxy.h"

NS_PAIGOW_BEGIN

PaigowManager::PaigowManager()
{
	m_data = new PaiGowSnaptShot();
	m_proxy = new PaiGowProxy(m_data);
	m_controller = new PaiGowViewController(m_data);
}

PaigowManager::~PaigowManager()
{
	delete m_controller;
	delete m_proxy;
	delete m_data;
}

void PaigowManager::init(const proto3_proto::S2C_MatchSnapshot& shot)
{

	//根据快照初始化游戏数据
	m_data->init(shot);
	m_controller->init();
}

void PaigowManager::dispose()
{
	//if (m_view)
	//{
		//core::SceneManager::getInstance()->remove(core::LayerMainUI, m_view);
	//}
	//m_view = nullptr;
	m_data->clear();
	m_controller->dispose();
}

NS_PAIGOW_END
