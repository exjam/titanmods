#include "TCaption.h"

CTCaption::CTCaption(){}
CTCaption::~CTCaption(){}

unsigned int CTCaption::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){ return 0; }
void CTCaption::Update(POINT ptMouse){}
void CTCaption::Draw(){}
void CTCaption::Hide(){}
void CTCaption::MoveWindow(POINT pos){}

bool CTCaption::Create(int posX, int posY, int width, int height){ return false; }
bool CTCaption::IsClicked(){ return false; }

void CTCaption::SetString(const char* string){}

void CTCaption::SetIcon(CTImage* image){}
void CTCaption::SetImage(CTImage* image){}
void CTCaption::SetCloseButton(CTButton* button){}
void CTCaption::SetIconButton(CTButton* button){}
