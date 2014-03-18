#include "TGuage.h"

CTGuage::CTGuage(){}
CTGuage::~CTGuage(){}

void CTGuage::Draw(){}

bool CTGuage::Create(int posX, int posY, int width, int height, int guageImgID, int backImgID, int moduleID){ return false; }
char const* CTGuage::GetText(){ return 0; }
int CTGuage::GetValue(){ return 0; }
void CTGuage::SetGuageImageID(int imageID){}
void CTGuage::SetText(char const* text){}
void CTGuage::SetValue(int value){}
