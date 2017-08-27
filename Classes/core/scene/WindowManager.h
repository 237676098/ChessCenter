#ifndef __WINDOW_MANAGER_H__
#define __WINDOW_MANAGER_H__
#include "utils/CommonMacros.h"
#include "BaseUI.h"
#include "BaseWindow.h"
#include "window_ids.h"


NS_CORE_BEGIN
typedef enum _WindowState
{
	WindowClose = 0,
	WindowOpen  = 1
}WindowState;

class WindowStruct
{
public:
	WindowStruct() {};
	WindowStruct(WindowId winid) :window_id(winid), window(nullptr), state(WindowClose) {};
	WindowId window_id;
	IBaseWindow* window;
	WindowState  state;
};

typedef std::map<int, WindowStruct> WindowMap;

class WindowManager
{
	SINGLETON(WindowManager)
public:

	template <typename WIND_NAME>
	void open();

	template <typename WIND_NAME, typename PARAM_TYPE1>
	void open_1(PARAM_TYPE1 param);

	template <typename WIND_NAME, typename PARAM_TYPE1,typename PARAM_TYPE2>
	void open_2(PARAM_TYPE1 param1, PARAM_TYPE2 param2);
	
	void close(WindowId);
	bool isOpen(WindowId windowId);
	IBaseWindow* getWindow(WindowId windowId);

private:
	void insertWindow(IBaseWindow* widnow, int id);

private:
	WindowMap m_windows;
};

template <typename WIND_NAME>
void WindowManager::open()
{
	WindowStruct window(WIND_NAME::s_id);

	if (m_windows.find(WIND_NAME::s_id) == m_windows.end())
	{
		m_windows[WIND_NAME::s_id] = window;
		window.state = WindowClose;
	}
	else
	{
		if (m_windows[WIND_NAME::s_id].state == WindowOpen)
		{
			return;
		}
	}
	WIND_NAME* wnd = new (std::nothrow) WIND_NAME();
	this->insertWindow(wnd, WIND_NAME::s_id);
}

template <typename WIND_NAME, typename PARAM_TYPE1>
void WindowManager::open_1(PARAM_TYPE1 param)
{
	WindowStruct window(WIND_NAME::s_id);

	if (m_windows.find(WIND_NAME::s_id) == m_windows.end())
	{
		m_windows[WIND_NAME::s_id] = window;
		window.state = WindowClose;
	}
	else
	{
		if (m_windows[WIND_NAME::s_id].state == WindowOpen)
		{
			return;
		}
	}

	WIND_NAME* wnd = new (std::nothrow) WIND_NAME(param);
	this->insertWindow(wnd, WIND_NAME::s_id);
}

template <typename WIND_NAME, typename PARAM_TYPE1, typename PARAM_TYPE2>
void WindowManager::open_2(PARAM_TYPE1 param1, PARAM_TYPE2 param2)
{
	WindowStruct window(WIND_NAME::s_id);

	if (m_windows.find(WIND_NAME::s_id) == m_windows.end())
	{
		m_windows[WIND_NAME::s_id] = window;
		window.state = WindowClose;
	}
	else
	{
		if (m_windows[WIND_NAME::s_id].state == WindowOpen)
		{
			return;
		}
	}

	WIND_NAME* wnd = new (std::nothrow) WIND_NAME(param1, param2);
	this->insertWindow(wnd, WIND_NAME::s_id);
}

NS_CORE_END

#endif
