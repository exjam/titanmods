#include "TEditBox.h"

CTEditBox::CTEditBox(){}
CTEditBox::~CTEditBox(){}

unsigned int CTEditBox::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){ return 0; }
void CTEditBox::Draw(){}
void CTEditBox::SetFocus(bool focus){}
void CTEditBox::Hide(){}
void CTEditBox::Show(){}

bool CTEditBox::Create(int posX, int posY, int width, int height, int charWidth){ return 0; }
void CTEditBox::AddType(unsigned long type){}
void CTEditBox::AppendText(char const* text){}
unsigned long CTEditBox::GetType(){ return 0; }
void CTEditBox::Insert(char const* text){}
bool CTEditBox::IsTypeHideCursor(){ return 0; }
bool CTEditBox::IsTypeNumber(){ return 0; }
bool CTEditBox::IsTypePassword(){ return 0; }
void CTEditBox::MoveEnd(){}
bool CTEditBox::OnChar(WPARAM wParam, LPARAM lParam){ return 0; }
bool CTEditBox::OnKeyDown(WPARAM wParam, LPARAM lParam){ return 0; }
void CTEditBox::SetCharHeight(int height){}
void CTEditBox::SetLimitText(int limit){}
void CTEditBox::SetMultiline(bool multiline){}
void CTEditBox::SetText(char const* text){}
void CTEditBox::SetTextAlign(int align){}
void CTEditBox::SetTextColor(int colour){}
void CTEditBox::SetType(unsigned long type){}
bool CTEditBox::chk_number(char const* text){ return 0; }
void CTEditBox::clear_text(){}
void CTEditBox::delete_one_char(int type){}
char* CTEditBox::get_text(){ return 0; }
