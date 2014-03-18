#include "JTable.h"

CJTable::CJTable(){}
CJTable::~CJTable(){}

void CJTable::Draw(){}
void CJTable::Update(POINT ptMouse){}
unsigned int CJTable::Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam){ return 0; }
void CJTable::MoveWindow(POINT pos){}

int CJTable::GetValue(){ return 0; }
int CJTable::GetExtent(){ return 0; }
int CJTable::GetMaximum(){ return 0; }
int CJTable::GetMinimum(){ return 0; }

void CJTable::SetValue(int value){}
void CJTable::SetExtent(int extent){}
void CJTable::SetMaximum(int maximum){}
void CJTable::SetMinimum(int minimum){}

RECT CJTable::GetWindowRect(){ return RECT(); }

void CJTable::Add(CWinCtrl* ctrl){}

CWinCtrl* CJTable::GetItem(int index){ return 0; }

int CJTable::GetSelectedItemID(){ return 0; }

void CJTable::SetColumnCount(int count){}

void CJTable::SetCellHeight(int height){}
void CJTable::SetCellWidth(int width){}

void CJTable::SetColMargin(int margin){}
void CJTable::SetRowMargin(int margin){}
