#include "main.h"
#include "SkillBar2.h"
#include "Network.h"
#include "DragCommand.h"
#include <TRose\CodeHook.h>
#include <TRose\DragItem.h>
#include <TRose\Game.h>
#include <TRose\IconManager.h>
#include <TRose\IconSkill.h>
#include <TRose\IconItem.h>

bool CTCmdMoveIconInQuickBar::Exec(CTObject* object){
	if(!object)	return true;

	CIconQuick* icon = (CIconQuick*)object;	
	short previousSlotIndex = icon->GetQuickBarSlotIndex();

	if(previousSlotIndex < 0 || previousSlotIndex >= 32)
		return true;

	POINT ptMouse;
	CGame::Instance()->GetMousePos(ptMouse);

	short newSlotIndex = gSkillBar2->GetMouseClickSlot(ptMouse);
	if(newSlotIndex < 0 || newSlotIndex >= 32 || newSlotIndex == previousSlotIndex)
		return true;

	tagHotICON hotIcon;
	hotIcon.mType = 0;
	hotIcon.mSlotNo = 0;

	SendPacket::Instance()->SendSetHotIcon((BYTE)previousSlotIndex, hotIcon);
	CHotIconSlot::Instance()->GetHotItem(&hotIcon, (BYTE)previousSlotIndex);
	SendPacket::Instance()->SendSetHotIcon((BYTE)newSlotIndex, hotIcon);

	return true;	
}

bool CTCmdDragInven2SkillBar2::Exec(CTObject* object){
	if(!object)	return true;

	CIconItem* iconItem = (CIconItem*)object;

	POINT ptMouse;
	CGame::Instance()->GetMousePos(ptMouse);

	short newSlotIndex = gSkillBar2->GetMouseClickSlot(ptMouse);

	if(newSlotIndex < 0 || newSlotIndex >= 32)
		return true;

	tagHotICON icon;
	icon.mSlotNo = iconItem->GetIndex();
	icon.mType = INV_ICON;

	SendPacket::Instance()->SendSetHotIcon((BYTE)newSlotIndex, icon);

	return true;
}

bool CTCmdDragItemFromQuickBar::Exec(CTObject* object){
	if(!object)	return true;

	CIconItem* iconItem = (CIconItem*)object;

	tagHotICON icon;
	icon.mSlotNo = 0;
	icon.mType = 0;

	SendPacket::Instance()->SendSetHotIcon((unsigned char)iconItem->GetIndex(), icon);

	return true;
}

bool CTCmdDragSkill2SkillBar2::Exec(CTObject* object){
	if(!object)	return true;

	CIconSkill* iconSkill = (CIconSkill*)object;

	POINT ptMouse;
	CGame::Instance()->GetMousePos(ptMouse);

	short newSlotIndex = gSkillBar2->GetMouseClickSlot(ptMouse);
	
	if(newSlotIndex < 0 || newSlotIndex >= 32)
		return true;

	tagHotICON icon;
	icon.mSlotNo = iconSkill->GetIndex();
	icon.mType = SKILL_ICON;

	SendPacket::Instance()->SendSetHotIcon((BYTE)newSlotIndex, icon);

	return true;
}

bool CTCmdMoveIconToQuickBar1::Exec(CTObject* object){
	if(!object)	return true;

	CIconQuick* icon = (CIconQuick*)object;
	short previousSlotIndex = icon->GetQuickBarSlotIndex();

	if(previousSlotIndex < 0 || previousSlotIndex >= 32)
		return true;

	CQuickBAR* dlgQuickbar = (CQuickBAR*)IT_MGR::Instance()->FindDlg(DLG_TYPE_QUICKBAR);
	if(!dlgQuickbar) return true;

	POINT ptMouse;
	CGame::Instance()->GetMousePos(ptMouse);

	short newSlotIndex = dlgQuickbar->GetMouseClickSlot(ptMouse);

	if(newSlotIndex < 0 || newSlotIndex >= 32 || newSlotIndex == previousSlotIndex)
		return true;

	tagHotICON hotIcon;
	hotIcon.mType = 0;
	hotIcon.mSlotNo = 0;

	SendPacket::Instance()->SendSetHotIcon((BYTE)newSlotIndex, hotIcon);
	CHotIconSlot::Instance()->GetHotItem(&hotIcon, (BYTE)previousSlotIndex);
	SendPacket::Instance()->SendSetHotIcon((BYTE)newSlotIndex, hotIcon);

	return true;
}