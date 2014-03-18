#include "TButton.h"

CTButton::CTButton(){}
CTButton::~CTButton(){}

unsigned int CTButton::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){ return 0; }
void CTButton::Update(POINT ptMouse){}
void CTButton::Draw(){}

bool CTButton::Create(int posX, int posY, int width, int height, int normalGID, int overGID, int downGID , int moduleID){ return false; }

CSinglelineString& CTButton::GetText(){ return mText; }
void CTButton::SetText(char* text){}
void CTButton::SetTextColor(unsigned long colour){}

void CTButton::SetButtonState(int state){}
int CTButton::GetButtonState(){ return 0; }

void CTButton::SetSoundOverID(int id){}
void CTButton::SetSoundClickID(int id){}
void CTButton::SetDisableGrahicID(int id){}

void CTButton::SetNoImage(){}
void CTButton::SetBlink(int blink, int blinkTime){}

void CTButton::SetBlinkGid(int graphicID){}
