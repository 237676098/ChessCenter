#ifndef __PAI_GOW_RESULT_WINDOW_H__
#define __PAI_GOW_RESULT_WINDOW_H__
#include "core/scene/scene.h"
#include "core/network/socket/SocketManager.h"


NS_PAIGOW_BEGIN

class PaiGowViewController;
class PaiGowResultWindow :public core::IBaseWindow
{
public:
	const static WindowId s_id = ID_PAI_GOW_RESULT;
	PaiGowResultWindow(PaiGowViewController* controller, const proto3_proto::S2C_PG_Result& result)
		:m_controller(controller),
		m_result(result),
		core::IBaseWindow("paigow/paigow_result_view") {};
	void onLoadCompleted() override;
	void onClickCloseBtn(Ref* btn) override;
	void onClickSure(Ref * btn) const;
private:
	proto3_proto::S2C_PG_Result m_result;
	PaiGowViewController* m_controller;
};

NS_PAIGOW_END

#endif