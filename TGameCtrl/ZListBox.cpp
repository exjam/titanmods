#include "ZListBox.h"

CZListBox::CZListBox(){}
CZListBox::~CZListBox(){}

unsigned CZListBox::Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam){ return 0; }
void CZListBox::Update(POINT ptMouse){}
void CZListBox::Draw(){}

void CZListBox::Show(){}
void CZListBox::Hide(){}
void CZListBox::MoveWindow(POINT pos){}

int CZListBox::GetValue(){ return 0; }
int CZListBox::GetExtent(){ return 0; }
int CZListBox::GetMaximum(){ return 0; }
int CZListBox::GetMinimum(){ return 0; }

void CZListBox::SetValue(int value){}
void CZListBox::SetExtent(int extent){}
void CZListBox::SetMaximum(int max){}
void CZListBox::SetMinimum(int min){}

RECT CZListBox::GetWindowRect(){ return RECT(); }

void CZListBox::Add(CWinCtrl* ctrl){}
void CZListBox::Clear(){}
void CZListBox::SetSelected(int index){}
void CZListBox::DeselectAll(){}
int CZListBox::GetSelectedItemIndex(){ return 0; }
CWinCtrl* CZListBox::GetItem(int index){ return 0; }
void CZListBox::InsertItem(int index, CWinCtrl* ctrl){}
bool CZListBox::DelItem(int iIndex){ return 0; }
bool CZListBox::DelItemByControlID(int id){ return 0; }
int CZListBox::GetSize(){ return 0; }
