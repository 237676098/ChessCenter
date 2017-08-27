#ifndef __LOBBY_VIEW_H__
#define __LOBBY_VIEW_H__

#include "utils/CommonMacros.h"
#include "core/scene/scene.h"

NS_LOBBY_BEGIN

class LobbyView :public core::IBaseUI
{
public:
	static LobbyView* create();
	LobbyView() :IBaseUI() {};
	bool initWithFile(const std::string fileName);

private:
	
};

NS_LOBBY_END

#endif