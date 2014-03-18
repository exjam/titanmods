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

SkillBar2* gSkillBar2;
int gLastKey;

typedef int (*getScreenHeight_)(void);

void __stdcall AddInvenCmds(CDragItem* dragItem){
	CTCmdDragInven2SkillBar2* command = new CTCmdDragInven2SkillBar2();
	dragItem->AddTarget(DLG_TYPE_SKILLBAR2, command);
}

void __stdcall AddSkillCmds(CDragItem* dragItem){
	CTCmdDragSkill2SkillBar2* command = new CTCmdDragSkill2SkillBar2();
	dragItem->AddTarget(DLG_TYPE_SKILLBAR2, command);
}

void __stdcall AddSkillBar1Cmds(CDragItem* dragItem){
	CTCmdMoveIconInQuickBar* command = new CTCmdMoveIconInQuickBar();
	dragItem->AddTarget(DLG_TYPE_SKILLBAR2, command);
}

void __stdcall UpdateQuickBar(){
	gSkillBar2->UpdateIcons();
}

static _declspec(naked) void ASMQuickSkillINFO(){
	static int retAddr = 0x004D3145;
	_asm {		
		CMP DWORD PTR SS:[ESP+0x8], DLG_TYPE_QUICKBAR
		JE jRET
		CMP DWORD PTR SS:[ESP+0x8], DLG_TYPE_SKILLBAR2  // Not 0x8, maybe it's quickbar2 then
jRET:
		JMP retAddr
	};
}

void _declspec(naked) ASMAddInvenCmd(){
	static const char* func1 = (char*)0x00500B32;
	static const char* retAddr = (char*)0x004AB30A;
	_asm {
		MOV ECX, DWORD PTR DS:[EDI+0x50AC]
		PUSH ECX
		CALL AddInvenCmds
		PUSH DLG_TYPE_SKILL
		CALL func1
		JMP retAddr
	}
}

void _declspec(naked) ASMAddSkillCmd(){
	static const char* retAddr = (char*)0x004CC942;
	_asm {
		MOV ECX, DWORD PTR DS:[ESI+0x108]
		PUSH ECX
		CALL AddSkillCmds
		MOV ECX, DWORD PTR DS:[ESI+0x108]
		JMP retAddr
	}
}

void _declspec(naked) ASMUpdateQuickBar(){
	static const char* retAddr = (char*)0x0048E636;
	_asm {
		PUSH ECX
		CALL UpdateQuickBar
		POP ECX
		MOV EDX, DWORD PTR DS:[ECX+0x404]
		JMP retAddr
	}
}

void _declspec(naked) ASMAddSkillBar1Cmds(){
	static const char* func1 = (char*)0x00500B32;
	static const char* retAddr = (char*)0x004C5B7C;
	_asm {
		MOV ECX, DWORD PTR DS:[ESI+0x57C]
		PUSH ECX
		CALL AddSkillBar1Cmds
		PUSH DLG_TYPE_QUICKBAR
		CALL func1
		JMP retAddr
	}
}

SkillBar2::SkillBar2(int type){
	SetDialogType(DLG_TYPE_SKILLBAR2);
	CodeHook::ApplyJmpHook((unsigned char*)0x004AB303, (unsigned char*)&ASMAddInvenCmd, 2);
	CodeHook::ApplyJmpHook((unsigned char*)0x004CC93C, (unsigned char*)&ASMAddSkillCmd, 1);
	CodeHook::ApplyJmpHook((unsigned char*)0x0048E630, (unsigned char*)&ASMUpdateQuickBar, 1);
	CodeHook::ApplyJmpHook((unsigned char*)0x004C5B75, (unsigned char*)&ASMAddSkillBar1Cmds, 2);
	CodeHook::ApplyJmpHook((unsigned char*)0x004D3140, (unsigned char*)&ASMQuickSkillINFO, 0);

	CTCommand* command = new CTCmdDragItemFromQuickBar();
	CDragItem* dragItem = new CDragItem();
	dragItem->AddTarget(DLG_TYPE_MAX, command);//0x31 = target anything (so we can drag away from skillbar and remove skill)
	
	command = new CTCmdMoveIconInQuickBar();
	dragItem->AddTarget(DLG_TYPE_SKILLBAR2, command);
	
	command = new CTCmdMoveIconToQuickBar1();
	dragItem->AddTarget(DLG_TYPE_QUICKBAR, command);
	
	for(int i = 0; i < 8; ++i){
		mQuickSlots[i] = new CSlot();
		mQuickSlots[i]->SetParent(DLG_TYPE_SKILLBAR2);
		mQuickSlots[i]->SetDragAvailable();
		mQuickSlots[i]->SetDragItem(dragItem);
		mQuickSlots[i]->Show();
	}

	UpdateSlotOffset();
}

bool SkillBar2::IsVision(){

	if (!CTDialog::IsVision() || !gOptions.mSkillBarEnable)
		return false;

	return true;
}

bool SkillBar2::Create(const char* xmlFile){
	if(!CTDialog::Create(xmlFile))	return false;

	gOptions.mSkillBarType = GetPrivateProfileInt("QUICKBAR2", "TYPE", 0, gConfig);
	gOptions.mSkillBarPage = GetPrivateProfileInt("QUICKBAR2", "PAGE", 1, gConfig);
	gOptions.mSkillBarX = GetPrivateProfileInt("QUICKBAR2", "X", 0, gConfig);
	gOptions.mSkillBarY = GetPrivateProfileInt("QUICKBAR2", "Y", 0, gConfig);

	if(gOptions.mSkillBarX == 0 && gOptions.mSkillBarY == 0){
		if(gOptions.mSkillBarType == 0){
			gOptions.mSkillBarX = 400;
			gOptions.mSkillBarY = getScreenHeight() - 128;
			SetDefaultAdjustPosY(-63);
			SetDefaultAdjustPosX(400);
		}else{
			gOptions.mSkillBarX = 400;
			gOptions.mSkillBarY = getScreenHeight() - 464;
			SetDefaultAdjustPosY(-402);
			SetDefaultAdjustPosX(464);
		}
	}

	SetDefaultVisible(true);

	return true;
}

SkillBar2::~SkillBar2(){
}

void SkillBar2::Draw(){
	if(!IsVision()) return;

	CTDialog::Draw();
	
	::endSprite();
	::beginSprite(D3DXSPRITE_ALPHABLEND); 

	for(int i = 0; i < 8; ++i)
		mQuickSlots[i]->Draw();
}

void SkillBar2::UpdateSlotOffset(){
	POINT offset;

	if(gOptions.mSkillBarType == HORIZONTAL){
		offset.y = 21;
		for(int i = 0; i < 8; ++i){
			offset.x = 40 + (mQuickSlots[i]->GetWidth() + 1) * i + (2 * i / 8) * 9;
			mQuickSlots[i]->SetOffset(offset);
		}
	}else if(gOptions.mSkillBarType == VERTICAL){
		offset.x = 3;
		for(int i = 0; i < 8; ++i){
			offset.y = 40 + (mQuickSlots[i]->GetHeight() + 1) * i + (2 * i / 8) * 10;
			mQuickSlots[i]->SetOffset(offset);
		}
	}
}

void SkillBar2::Update(CObservable* observable, CTObject* command){
	if(!command) return;
}

unsigned char SkillBar2::GetMouseClickSlot(POINT mousePos){
	for(int i = 0; i < 8; ++i){
		if(mQuickSlots[i]->IsInside(mousePos.x, mousePos.y))
			return gOptions.mSkillBarPage * 8 + i;
	}

	return -1;
}

void SkillBar2::MoveWindow(POINT pt){
	CTDialog::MoveWindow(pt);
	CTDialog::SetPosition(pt.x, pt.y);

	UpdateSlotOffset();

	for(int i = 0; i < 8; ++i)
		mQuickSlots[i]->MoveWindow(mPosition);

	if(mLoaded){
		gOptions.mSkillBarX = pt.x;
		gOptions.mSkillBarY = pt.y;
	}
}

void SkillBar2::UpdateIcons(){
	int pageOffset = gOptions.mSkillBarPage * 8;

	for(int i = 0; i < 8; ++i){
		mQuickSlots[i]->DetachIcon();
		CIcon* icon = CHotIconSlot::Instance()->GetIcon(i + pageOffset);
		mQuickSlots[i]->AttachIcon(icon);
	}
}

void SkillBar2::Update(POINT ptMouse){	
	if(!mLoaded){
		POINT pos;
		pos.x = gOptions.mSkillBarX;
		pos.y = gOptions.mSkillBarY;
		ChangeType(gOptions.mSkillBarType);
		SetPage(gOptions.mSkillBarPage);
		MoveWindow(pos);
		mLoaded = true;
	}

	if(!IsVision()) return;

	UpdateIcons();
	CTDialog::Update(ptMouse);

	for(int i = 0; i < 8; ++i){
		if(mQuickSlots[i])
			mQuickSlots[i]->Update(ptMouse);
		else {
			CTCommand* command = new CTCmdDragItemFromQuickBar();
			CDragItem* dragItem = new CDragItem();
			dragItem->AddTarget(DLG_TYPE_MAX, command);//0x31 = target anything (so we can drag away from skillbar and remove skill)
	
			mQuickSlots[i] = new CSlot();
			mQuickSlots[i]->SetParent(DLG_TYPE_SKILLBAR2);
			mQuickSlots[i]->SetDragAvailable();
			mQuickSlots[i]->SetDragItem(dragItem);
			mQuickSlots[i]->Show();
			UpdateSlotOffset();
		}
	}
}

unsigned int SkillBar2::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){
	if(!IsVision()) return 0;

	if(gLastKey != wParam && (wParam >= VK_F1 && wParam <= VK_F8) && GetKeyState(VK_MENU) & 0x8000){
		int i = wParam - 0x70;

		POINT pt = mQuickSlots[i]->GetOffset();
		POINT pt2 = gSkillBar2->GetPosition();
		pt.x += (pt2.x + 10);
		pt.y += (pt2.y + 10);

		mQuickSlots[i]->Process(WM_LBUTTONDBLCLK, 0, MAKELPARAM((WORD) pt.x,(WORD) pt.y));
	}

	gLastKey = wParam;

	unsigned int controlID = CTDialog::Process(uiMsg, wParam, lParam);
	if(controlID == 0)	return 0;

	for(int i = 0; i < 8; ++i){
		if(mQuickSlots[i]->Process(uiMsg, wParam, lParam))
			return uiMsg;
	}

	if(uiMsg == WM_LBUTTONUP){
		switch(controlID){
			case IID_BTN_ROTATE:
				ChangeType((gOptions.mSkillBarType == HORIZONTAL) ? VERTICAL : HORIZONTAL);
				break;
			case IID_BTN_HORIZONTAL_PREV:
			case IID_BTN_VERTICAL_PREV:
				{
					if(gOptions.mSkillBarPage == 0)
						SetPage(3);
					else
						SetPage(gOptions.mSkillBarPage - 1);
				}
				break;
			case IID_BTN_HORIZONTAL_NEXT:
			case IID_BTN_VERTICAL_NEXT:
				{
					if(gOptions.mSkillBarPage == 3)
						SetPage(0);
					else
						SetPage(gOptions.mSkillBarPage + 1);
				}
				break;
		}
	}

	return uiMsg;
}

void SkillBar2::SetPage(int page){
	gOptions.mSkillBarPage = page;

	CTImage* image = (CTImage*)Find(IID_NUMBER);
	if(!image)	return;

	image->SetImage(gPageGID + page, IMAGE_RES_UI);

	UpdateIcons();
}

void SkillBar2::Show()
{
	POINT pt;
	pt.x = gOptions.mSkillBarX;
	pt.y = gOptions.mSkillBarY;
	MoveWindow(pt);

	CTDialog::Show();
	ChangeType(gOptions.mSkillBarType);
}

void SkillBar2::ChangeType(int type)
{
	RECT rc;
	POINT pt = GetPosition();

	int oldType = gOptions.mSkillBarType;
	gOptions.mSkillBarType = type;

	UpdateSlotOffset();

	if(gOptions.mSkillBarType == HORIZONTAL){
		ShowChild(IID_BG_HORIZONTAL);
		ShowChild(IID_BTN_HORIZONTAL_PREV);
		ShowChild(IID_BTN_HORIZONTAL_NEXT);

		HideChild(IID_BG_VERTICAL);
		HideChild(IID_BTN_VERTICAL_PREV);
		HideChild(IID_BTN_VERTICAL_NEXT);

		SetRect(&rc, 0, 0, 18, 63);

		if(CWinCtrl* ctrl = Find(IID_BTN_ROTATE))
			ctrl->SetOffset(377, 27);

		if(CWinCtrl* ctrl = Find(IID_NUMBER))
			ctrl->SetOffset(19, 24);

		if(oldType != gOptions.mSkillBarType){
			pt.x -= 169;
			pt.y += 169;
		}
	
		SetHeight(63);
		SetWidth(401);

		SetDefaultAdjustPosY(-63);
		SetDefaultAdjustPosX(400);
	}else{
		HideChild(IID_BG_HORIZONTAL);
		HideChild(IID_BTN_HORIZONTAL_PREV);
		HideChild(IID_BTN_HORIZONTAL_NEXT);

		ShowChild(IID_BG_VERTICAL);
		ShowChild(IID_BTN_VERTICAL_PREV);
		ShowChild(IID_BTN_VERTICAL_NEXT);

		SetRect(&rc, 1, 1, 63, 18);

		if(CWinCtrl* ctrl = Find(IID_BTN_ROTATE))
			ctrl->SetOffset(17, 377);

		if(CWinCtrl* ctrl = Find(IID_NUMBER))
			ctrl->SetOffset(21, 20);

		if(oldType != gOptions.mSkillBarType) {
			pt.y -= 169;
			pt.x += 169;
		}
		
		SetHeight(401);
		SetWidth(63);

		SetDefaultAdjustPosY(0);
		SetDefaultAdjustPosX(464);
	}

	ChangeCaptionRect(rc);

	if(pt.y + GetHeight() > getScreenHeight() )
		pt.y = getScreenHeight() - GetHeight();

	if(pt.y < 0)
		pt.y = 0;

	if(pt.x + GetWidth() > getScreenWidth())
		pt.x = getScreenWidth() - GetWidth();

	if(pt.x < 0)
		pt.x = 0;

	MoveWindow(pt);
}