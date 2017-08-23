#ifndef __ROOM_JOIN_WINDOW_H__
#define __ROOM_JOIN_WINDOW_H__

#include "core/scene/scene.h"

NS_LOBBY_BEGIN

class RoomJoinWindow :public core::IBaseWindow
{
public:
	const static WindowId s_id = ID_RoomJoin;
	RoomJoinWindow() :core::IBaseWindow("room_join_view") {};
	~RoomJoinWindow() {};
	virtual void onLoadCompleted() override;
	void onClickCloseBtn(Ref* btn) override;
};

NS_LOBBY_END

#endif // !__ROOM_JOIN_WINDOW_H__
