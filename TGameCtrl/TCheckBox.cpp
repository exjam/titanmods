#include "TCheckBox.h"

CTCheckBox::CTCheckBox(){}
CTCheckBox::~CTCheckBox(){}

unsigned CTCheckBox::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){ return 0; }
void CTCheckBox::Draw(){}

bool CTCheckBox::Create(int posX, int posY, int width, int height, int moduleID, int checkImageID, int uncheckImageID){ return false; }

bool CTCheckBox::IsCheck(){ return false; }
void CTCheckBox::SetCheck(){}
void CTCheckBox::SetUncheck(){}
