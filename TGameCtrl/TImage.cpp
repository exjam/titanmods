#include "TImage.h"

CTImage::CTImage(){}
CTImage::~CTImage(){}

unsigned int CTImage::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){ return 0; }
void CTImage::Update(POINT ptMouse){}
void CTImage::Draw(){}
void CTImage::Draw(POINT pos){}

bool CTImage::Create(int posX, int posY, int width, int height, int graphicID ,int moduleID){ return false; }

void CTImage::SetImage(int graphicID, int moduleID){}
void CTImage::SetBlinkImage(int graphicID, int moduleID){}

void CTImage::SetBlink(){}
void CTImage::SetUnblink(){}
void CTImage::SetBlinkSwapTime(DWORD swap_time){}
