#include "TRadioButton.h"

CTRadioButton::CTRadioButton(){}
CTRadioButton::~CTRadioButton(){}

unsigned int CTRadioButton::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){ return 0; }
void CTRadioButton::Update(POINT ptMouse){}
void CTRadioButton::Draw(){}

bool CTRadioButton::Create(int posX, int posY, int width, int height, int normalGID, int overGID, int downGID, int moduleID){ return false; }

short CTRadioButton::GetButtonState(){ return 0; }
CSinglelineString& CTRadioButton::GetText(){ return mString; }
void CTRadioButton::SetButtonState(int state){}
void CTRadioButton::SetGhost(){}
void CTRadioButton::SetRadioBox(CTRadioBox* box){}
void CTRadioButton::SetSoundDisableID(int id){}
void CTRadioButton::SetText(char* text){}
