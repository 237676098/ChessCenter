#ifndef __EVENTMANAGER_H__
#define __EVENTMANAGER_H__
#include<algorithm>
#include "utils/CommonMacros.h"
#include <list>
#include <map>

NS_CORE_BEGIN
enum EventId
{
	EVT_PG_AddPlayer = 0,					//牌桌加入玩家 
	EVT_PG_DeletePlayer,					//牌桌离开玩家
	EVT_PG_StartGame,						//开始游戏
	EVT_PG_GrabStatus,						//设置抢庄状态
	EVT_PG_BankerConfirm,					//庄家确定
	EVT_PG_Bet,								//玩家下注
	EVT_PG_OffLine,							//玩家下线
	EVT_PG_DealCard,						//发牌
	EVT_PG_DealActionComplete,				//某个玩家的发牌动画结束
	EVT_PG_Collocation,						//玩家配牌返回
	EVT_PG_Result,							//结果结算
	EVT_PG_Sure,							//玩家准备
};

struct Event
{
	Event(int id) : id_(id)
	{}
	~Event()
	{}
	int id_;
	//params
};

class EventHandler
{
public:
	virtual int HandleEvent(Event *evt)
	{
		return 0;
	}
};

class EventManager
{
public:
	typedef std::list<EventHandler *> HandlerList;
	typedef std::map<int, HandlerList> IdHandlerMap;

public:
	static EventManager &Instance()
	{
		static EventManager inst_;
		return inst_;
	}

	void AddEventHandler(int id, EventHandler *handler)
	{
		if (handler == NULL)
			return;
		auto pair = handler_map_.insert(std::make_pair(id, HandlerList()));
		auto it = pair.first;
		if (it == handler_map_.end())
			return;
		it->second.push_back(handler);
	}

	void RemoveEventHandler(int id, EventHandler *handler)
	{
		if (handler == NULL)
			return;
		auto it = handler_map_.find(id);
		if (it == handler_map_.end())
			return;
		auto listIt = std::find(it->second.begin(), it->second.end(), handler);
		if (listIt != it->second.end())
			it->second.erase(listIt);
	}

	void ClearEventHandler(int id)
	{
		handler_map_.erase(id);
	}

	void DispatchEvent(Event *evt)
	{
		auto it = handler_map_.find(evt->id_);
		if (it == handler_map_.end())
			return;
		auto &handler_list = it->second;
		for (auto listIt = handler_list.begin(); listIt != handler_list.end(); ++listIt)
		{
			if ((*listIt) == NULL) continue;
			(*listIt)->HandleEvent(evt);
		}
	}

private:
	EventManager() {}
	EventManager(const EventManager&) {}
	~EventManager() {}

	IdHandlerMap handler_map_;
};
NS_CORE_END
#endif