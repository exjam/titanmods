#include "TRadioBox.h"

CTRadioBox::CTRadioBox(){}
CTRadioBox::~CTRadioBox(){}

void CTRadioBox::Show(){}

void CTRadioBox::EventChangeSelect(unsigned int id){}

bool CTRadioBox::SetPressedButton(unsigned int id){ return 0; }
unsigned int CTRadioBox::GetPressedButtonID(){ return 0; }

void CTRadioBox::RegisterCtrl(CTRadioButton* button){}
void CTRadioBox::UnregisterCtrl(CTRadioButton* button){}
