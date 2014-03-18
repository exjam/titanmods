#include "TScrollBox.h"

CTScrollBox::CTScrollBox(){}
CTScrollBox::~CTScrollBox(){}

unsigned int CTScrollBox::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){ return 0; }
void CTScrollBox::Update(POINT ptMouse){}
void CTScrollBox::Draw(){}

bool CTScrollBox::Create(int width, int height, int graphicID, int moduleID, int type){ return false; }

void CTScrollBox::SetTickMove(int i){}
void CTScrollBox::SetScrollBar(CTScrollBar* scrollbar){}
void CTScrollBox::MoveBoxPosition(int value, int max, int extent){}
void CTScrollBox::MoveBoxPositionByScreenPoint(POINT pt){}
void CTScrollBox::SetBlink(){}
void CTScrollBox::SetUnblink(){}
void CTScrollBox::SetBlinkImage(CTImage* image){}
