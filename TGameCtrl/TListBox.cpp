#include "TListBox.h"

CTListBox::CTListBox(){}
CTListBox::~CTListBox(){}

unsigned int CTListBox::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){ return 0; }
void CTListBox::Update(POINT ptMouse){}
void CTListBox::Draw(){}

int CTListBox::GetValue(){ return 0; }
int CTListBox::GetExtent(){ return 0; }
int CTListBox::GetMaximum(){ return 0; }
int CTListBox::GetMinimum(){ return 0; }

void CTListBox::SetValue(int value){}
void CTListBox::SetExtent(int extent){}
void CTListBox::SetMaximum(int max){}
void CTListBox::SetMinimum(int min){}

RECT CTListBox::GetWindowRect(){ return RECT(); }
bool CTListBox::IsLastItemDrawn(){ return 0; }

bool CTListBox::Create(int posX, int posY, int width, int height, int maxline, int charWidth, int charHeight){ return 0; }

void CTListBox::AppendText(char const* text, unsigned long colour, bool autoIncValue){}
void CTListBox::ClearText(){}
void CTListBox::DeleteText(int index){}
short CTListBox::GetCharHeight(){ return 0; }
short CTListBox::GetCharWidthA(){ return 0; }
t_list_item CTListBox::GetItem(int index){ return t_list_item(); }
short CTListBox::GetLineSpace(){ return 0; }
int CTListBox::GetMaxSize(){ return 0; }
char const* CTListBox::GetSelectedItem(){ return 0; }
short CTListBox::GetSelectedItemID(){ return 0; }
char const* CTListBox::GetText(int index){ return 0; }
bool CTListBox::IsSelectable(){ return 0; }
bool CTListBox::ProcessSelectable(UINT uiMsg, WPARAM wParam, LPARAM lParam){ return 0; }
void CTListBox::SetCharHeight(short height){}
void CTListBox::SetCharWidth(short width){}
void CTListBox::SetFont(int font){}
void CTListBox::SetLineSpace(short space){}
void CTListBox::SetMaxSize(int size){}
void CTListBox::SetSelectable(bool selectable){}
void CTListBox::SetSelectedItem(short index){}
void CTListBox::SetText(int index, char const* text, unsigned long colour){}
