#ifndef __PAI_GOW_RESULT_WINDOW_H__
#define __PAI_GOW_RESULT_WINDOW_H__
#include "core/scene/scene.h"
#include "core/network/socket/SocketManager.h"

NS_PAIGOW_BEGIN


class PaiGowResultWindow :public core::IBaseWindow
{
public:
	const static WindowId s_id = ID_PAI_GOW_RESULT;
	PaiGowResultWindow(const proto3_proto::S2C_PG_Result& result, uint32_t my_seat)
		:m_result(result),
		m_my_seat(my_seat),
		core::IBaseWindow("paigow_result_view") {};
	void onLoadCompleted() override;
	void onClickCloseBtn(Ref* btn) override;
private:
	proto3_proto::S2C_PG_Result m_result;
	uint32_t m_my_seat;
};

NS_PAIGOW_END

#endif