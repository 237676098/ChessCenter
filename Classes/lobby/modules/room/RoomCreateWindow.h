#ifndef __ROOM_CREATE_WINDOW_H__
#define __ROOM_CREATE_WINDOW_H__
#include "core/scene/scene.h"

NS_LOBBY_BEGIN

class RoomCreateWindow :public core::IBaseWindow
{
public:
	const static WindowId s_id = ID_RoomCreate;
	RoomCreateWindow() :core::IBaseWindow("room_create_view_select_game") {};
	~RoomCreateWindow() {};
	virtual void onLoadCompleted() override;
	void onClickCloseBtn(Ref* btn) override;
};

NS_LOBBY_END

#endif // !__ROOM_CREATE_WINDOW__

