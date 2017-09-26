#ifndef __PAIGOW_SELECT_PARAMS_VIEW_H__
#define __PAIGOW_SELECT_PARAMS_VIEW_H__

#include "core/scene/scene.h"
#include "games/paigow/PaigowManager.h"
#include <map>
#include <vector>
#include "ui/UICheckBox.h"

NS_PAIGOW_BEGIN

typedef  std::map<CheckBox*,bool> RadioBox;

class PaiGowSelectParamsView :public core::IBaseWindow
{
public:
	const static WindowId s_id = ID_PAI_GOW_SELECT_PARAMS;
	PaiGowSelectParamsView():current_tab(-1),core::IBaseWindow("paigow/paigow_select_params_view") {};
	~PaiGowSelectParamsView() {};
	virtual void onLoadCompleted() override;
	void onClickCloseBtn(Ref* btn) override;

public:
	void onClickCreate(Ref* btn);
	void onClickCreateForOthers(Ref* btn);
	void onClickHasCreated(Ref* btn);

private:
	void selectTab(int tab);
	void onCbSelected(Ref*, CheckBoxEventType);

private:
	proto3_proto::PaiGowConfig config;
	std::vector<ImageView*> tabs;
	std::vector<Node*> tab_panels;
	std::vector<RadioBox*> rbs0;
	int current_tab;
};

NS_PAIGOW_END

#endif // !__PAIGOW_SELECT_PARAMS_VIEW_H__

