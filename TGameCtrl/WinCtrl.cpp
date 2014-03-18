#include "WinCtrl.h"

CWinCtrl::CWinCtrl(){}
CWinCtrl::~CWinCtrl(){}

unsigned int CWinCtrl::Process(UINT uiMsg,WPARAM wParam,LPARAM lParam){ return 0; }
void CWinCtrl::Update(POINT ptMouse){}
void CWinCtrl::Draw(){}

void CWinCtrl::Draw(POINT draw){}
bool CWinCtrl::IsInside(int x, int y){ return false; }
void CWinCtrl::Init(DWORD type, int posX, int posY, int width, int height){}
void CWinCtrl::OwnerDraw(){}
void CWinCtrl::SetSelected(){}
void CWinCtrl::SetDeselected(){}
void CWinCtrl::Show(){}
void CWinCtrl::Hide(){}
void CWinCtrl::SetFocus(bool focus){}
bool CWinCtrl::IsVision(){ return false; }
void CWinCtrl::SetOffset(int x, int y){}
void CWinCtrl::SetOffset(POINT offset){}
void CWinCtrl::MoveWindow(POINT pos){}

void CWinCtrl::AddActionListener(IActionListener* actionListener){}
void CWinCtrl::RemoveActionListener(IActionListener* actionListener){}

bool CWinCtrl::IsActive(){ return false; }
bool CWinCtrl::IsEnable(){ return false; }
bool CWinCtrl::IsFocus(){ return false; }
bool CWinCtrl::IsOwnerDraw(){ return false; }
bool CWinCtrl::IsSelected(){ return false; }

unsigned int CWinCtrl::GetControlID(){ return 0; }
int CWinCtrl::GetControlType(){ return 0; }
int CWinCtrl::GetHeight(){ return 0; }
POINT CWinCtrl::GetOffset(){ return POINT(); }
CWinCtrl* CWinCtrl::GetParent(){ return 0; }
POINT CWinCtrl::GetPosition(){ return POINT(); }
int CWinCtrl::GetWidth(){ return 0; }

void CWinCtrl::SetActive(bool active){}
void CWinCtrl::SetAlphaValue(unsigned char alpha){}
void CWinCtrl::SetControlID(unsigned int id){}
void CWinCtrl::SetControlType(unsigned long type){}
void CWinCtrl::SetCtrlStatus(unsigned long status){}
void CWinCtrl::SetDraw(ITDraw* draw){}
void CWinCtrl::SetEnable(bool enable){}
void CWinCtrl::SetHeight(int height){}
void CWinCtrl::SetOwnerDraw(bool ownerDraw){}
void CWinCtrl::SetParent(CWinCtrl* parent){}
int CWinCtrl::SetPosition(int posX, int posY){ return 0; }
int CWinCtrl::SetPosition(POINT pos){ return 0; }
void CWinCtrl::SetScaleHeight(float scaleHeight){}
void CWinCtrl::SetScaleWidth(float scaleWidth){}
void CWinCtrl::SetWidth(int width){}
