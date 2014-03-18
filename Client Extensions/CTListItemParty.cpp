#include "main.h"
#include "PartyList.h"
#include <TRose\TooltipMGR.h>

extern Tooltip* gPartyToolTip;

CTListItemParty::CTListItemParty(){
	SetHeight(20);
	SetWidth(178);
	SetEnable(true);
	Show();
}

CTListItemParty::~CTListItemParty(){
	free(mParty.mLeaderName);
}

unsigned int CTListItemParty::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){
	if(!IsVision())	return 0;

	CMousePos pos;
	pos.mousePos = (long)lParam;
	
	if(IsInside(pos.x, pos.y)){
		if(uiMsg == WM_LBUTTONUP){
			((CZListBox*)GetParent())->DeselectAll();
			SetSelected();
			return 1;
		}
		else if(uiMsg == WM_LBUTTONDBLCLK){
			if(CTDialog* dlgChat = IT_MGR::Instance()->FindDlg(DLG_TYPE_CHAT)){
				if(CTEditBox* editBox = (CTEditBox*)dlgChat->Find(15)){
					editBox->clear_text();
					editBox->AppendText(String("@%1 ").arg(mParty.mLeaderName));
				}
			}

			return 1;
		}
	}

	return 0;
}

void CTListItemParty::Update(POINT ptMouse){
	if(IsVision())
		mMouse = ptMouse;
}

void CTListItemParty::Draw(){
	if(!IsVision())	return;
	
	POINT pt = GetPosition();
	ResetTransform((float)pt.x, (float)pt.y);

	tagRECT pos;
	SetRect(&pos, 4, 0, 174, 20);

	unsigned int colour = 0xFF0000FF;

	if(!IsSelected())
		colour = (mParty.mMemberCount < MaxMembers(mParty.mPartyLevel)) ? 0xFF000000 : 0xFFFF0000;

	drawFont(GameDATA->m_hFONT[FONT_SMALL], 1, &pos, colour, FONT_POS_LEFT, mParty.mLeaderName);
	drawFont(GameDATA->m_hFONT[FONT_SMALL], 1, &pos, colour, FONT_POS_RIGHT, String("Lev: %1").arg(mParty.mPartyLevel));

	if(IsInside(mMouse.x, mMouse.y)){
		if(!gPartyToolTip)
			gPartyToolTip = new Tooltip();
		
		gPartyToolTip->Clear();
		gPartyToolTip->AddString(String("Leader: %1").arg(mParty.mLeaderName));
		gPartyToolTip->AddString(String("Party Level: %1").arg(mParty.mPartyLevel));
		gPartyToolTip->AddString(String("Players: %1/%2").arg(mParty.mMemberCount).arg(MaxMembers(mParty.mPartyLevel)));
		gPartyToolTip->AddString(String("Average Level: %1").arg(mParty.mAverageLevel));
		gPartyToolTip->AddString(String("Zone: %1").arg(StringManager::Instance()->GetZoneName(mParty.mZoneNO)));
		mMouse.x += 20;
		gPartyToolTip->SetPosition(mMouse);

		gDrawToolTip = true;
	}
}