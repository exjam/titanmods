#include "TScrollBar.h"

CTScrollBar::CTScrollBar(){}
CTScrollBar::~CTScrollBar(){}

unsigned int CTScrollBar::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){ return 0; }
void CTScrollBar::Update(POINT ptMouse){}
void CTScrollBar::Draw(){}

void CTScrollBar::Show(){}
void CTScrollBar::Hide(){}

void CTScrollBar::SetOffset(POINT offset){}
void CTScrollBar::MoveWindow(POINT pos){}

bool CTScrollBar::Create(int posX, int posY, int width, int height, int type){ return 0; }

int CTScrollBar::GetExtent(){ return 0; }
int CTScrollBar::GetMaximum(){ return 0; }
RECT CTScrollBar::GetThumbMoveRange(){ return RECT(); }

void CTScrollBar::MoveEnd(){}
void CTScrollBar::MoveHome(){}

void CTScrollBar::SetModel(IScrollModel* model){}
void CTScrollBar::SetModelValue(int value){}

void CTScrollBar::SetNextButton(CTButton* button){}
void CTScrollBar::SetPrevButton(CTButton* button){}

void CTScrollBar::SetScrollBox(CTScrollBox* scrollbox){}
void CTScrollBar::SetValue(int value){}
