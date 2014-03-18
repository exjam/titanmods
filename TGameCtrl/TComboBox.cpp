#include "TComboBox.h"

CTComboBox::CTComboBox(){}
CTComboBox::~CTComboBox(){}

unsigned int CTComboBox::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){  return 0; }
void CTComboBox::Update(POINT ptMouse){}
void CTComboBox::Draw(){}

void CTComboBox::Show(){}
void CTComboBox::Hide(){}
void CTComboBox::SetOffset(POINT offaet){}
void CTComboBox::MoveWindow(POINT pt){}
void CTComboBox::OwnerDraw(){}

bool CTComboBox::Create(int posX, int posY, int width, int height){ return false;}

void CTComboBox::AddItem(char* item){}
void CTComboBox::ClearItem(){}
void CTComboBox::DrawDropBoxImage(){}
void CTComboBox::DrawSelectedItem(){}
CTListBox* CTComboBox::GetListBox(){ return 0; }
char const* CTComboBox::GetSelectedItem(){ return 0;}
short CTComboBox::GetSelectedItemID(){ return 0; }
bool CTComboBox::IsShowDropBox(){ return false; }
void CTComboBox::SetButton(CTButton* button){}
void CTComboBox::SetImage(CTImage* top, CTImage* middle, CTImage* bottom){}
void CTComboBox::SetListBox(CTListBox* listbox){}
void CTComboBox::SetSelectedItem(short index){}
void CTComboBox::ToggleShowDropBox(){}

