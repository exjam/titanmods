#include "main.h"
#include "CTListItemPvPInstance.hpp"

CTListItemPvPInstance::CTListItemPvPInstance(PvPInstance* instance){
	mInstance = instance;
	SetHeight(24);
	SetWidth(250);
	SetEnable(true);
	Show();
}

CTListItemPvPInstance::~CTListItemPvPInstance(){
}

unsigned int CTListItemPvPInstance::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){
	if(!IsVision())	return 0;

	if(uiMsg == WM_LBUTTONUP){
		CMousePos pos;
		pos.mousePos = (long)lParam;

		if(IsInside(pos.x, pos.y)){
			((CZListBox*)GetParent())->DeselectAll();
			SetSelected();
			return 1;
		}
	}else if(uiMsg == WM_LBUTTONDBLCLK){
		if(CZListBox* listBox = (CZListBox*)GetParent()){
			if(CTListItemPvPInstance* seectedItem = (CTListItemPvPInstance*)(listBox->GetItem(listBox->GetSelectedItemIndex()))){
				gPvPInstance->SetData(seectedItem->mInstance);
				gPvPInstance->Hide();
			}

			IT_MGR::Instance()->OpenDialog(DLG_TYPE_PVPINSTANCE, false);
		}
		return 1;
	}
	return 0;
}

void CTListItemPvPInstance::Draw(){
	if(!IsVision())	return;

	POINT pt = this->GetPosition();
	ResetTransform((float)pt.x,(float)pt.y);

	tagRECT pos;
	SetRect(&pos, 29, 0, 249, 22);

	if(!mInstance->mIsNewb){
		if(IsSelected())
			drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_BLUE, DT_LEFT | DT_VCENTER, String("Instance %1 :: %2").arg(mInstance->mID).arg(gGameStatus[mInstance->mStatus]));
		else
			drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, 0xFF000000, DT_LEFT | DT_VCENTER, String("Instance %1 :: %2").arg(mInstance->mID).arg(gGameStatus[mInstance->mStatus]));
	}else{
		if(IsSelected())
			drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_BLUE, DT_LEFT | DT_VCENTER, String("Instance (70-110) :: %2").arg(gGameStatus[mInstance->mStatus]));
		else
			drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, 0xFF000000, DT_LEFT | DT_VCENTER, String("Instance (70-110) :: %2").arg(gGameStatus[mInstance->mStatus]));
	}

	DrawImpl::Instance()->Draw2D(GetPosition().x + 3, GetPosition().y, IMAGE_RES_STATE_ICON, 88, 0xFFFFFFFF);
}

void CTListItemPvPInstance::Update(CObservable* observable, CTObject* object){
}