#include "TDialog.h"

CTDialog::CTDialog(void){}
CTDialog::~CTDialog(void){}

unsigned int CTDialog::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){ return 0; }
void CTDialog::Update(POINT ptMouse){}
void CTDialog::Draw(){}

void CTDialog::Show(){}
void CTDialog::Hide(){}
void CTDialog::MoveWindow(POINT pos){}
bool CTDialog::Create(const char* xml){ return false; }
bool CTDialog::IsModal(){ return false; }
void CTDialog::PostMsg(unsigned msg, unsigned param1, unsigned param2){}
int CTDialog::IsInValidShow(){ return 0; }

bool CTDialog::Create(int posX, int posY, int width, int height){ return false; }

void CTDialog::Add(CWinCtrl* control){}
bool CTDialog::Remove(int id){ return false; }
CWinCtrl* CTDialog::Find(int id){ return 0; }

bool CTDialog::ShowChild(unsigned int id){ return false; }
bool CTDialog::HideChild(unsigned int id){ return false; }

void CTDialog::Push_Back_Cmd(CTCommand* command){}
void CTDialog::Push_Front_Cmd(CTCommand* command){}
void CTDialog::ClearCommandQ(){}

void CTDialog::ChangeCaptionRect(RECT rect){}

CTCaption* CTDialog::GetCaption(){ return 0; }
long CTDialog::GetChildCount(){ return 0; }
int CTDialog::GetDefaultAdjustPosX(){ return 0; }
int CTDialog::GetDefaultAdjustPosY(){ return 0; }
int CTDialog::GetDefaultPosX(){ return 0; }
int CTDialog::GetDefaultPosY(){ return 0; }
DWORD CTDialog::GetDialogType(){ return 0; }
CTCommand* CTDialog::GetTCommand(){ return 0; }

void CTDialog::SetCaption(CTCaption* caption){}
void CTDialog::SetDefaultAdjustPosX(int posX){}
void CTDialog::SetDefaultAdjustPosY(int posY){}
void CTDialog::SetDefaultPosX(int posX){}
void CTDialog::SetDefaultPosY(int posY){}
void CTDialog::SetDefaultVisible(bool visible){}
void CTDialog::SetDialogType(DWORD type){}
bool CTDialog::SetEnableChild(unsigned int id, bool enable){ return false; }
void CTDialog::SetExtent(int i){}
void CTDialog::SetImage(CTImage* image){}
void CTDialog::SetModal(){}
void CTDialog::SetModeless(){}
void CTDialog::SetSoundShowID(int i){}
void CTDialog::SetSoundHideID(int i){}
void CTDialog::SetStatusBar(CTStatusBar* statusbar){}

bool CTDialog::IsDefaultVisible(){ return false; }

void CTDialog::MoveCtrl2ListEnd(int id){}
void CTDialog::ProcessLButtonDown(){}
