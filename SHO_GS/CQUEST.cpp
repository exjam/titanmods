#include "CQUEST.h"

CQUEST::CQUEST() { }
CQUEST::~CQUEST() { }
void CQUEST::ClearAllSwitch() { return CallMemberFunction<CQUEST, void>(0x100640C0, this); }
unsigned char CQUEST::GetBit(int iIndex) { return CallMemberFunction<CQUEST, unsigned char, int>(0x10064080, this, iIndex); }
void CQUEST::SetBit(int iIndex) { return CallMemberFunction<CQUEST, void, int>(0x10064040, this, iIndex); }
void CQUEST::ClearBit(int iIndex) { return CallMemberFunction<CQUEST, void, int>(0x10064000, this, iIndex); }
unsigned char CQUEST::FlipBit(int iIndex) { return CallMemberFunction<CQUEST, unsigned char, int>(0x100642D0, this, iIndex); }
void CQUEST::Init() { return CallMemberFunction<CQUEST, void>(0x10064160, this); }
void CQUEST::SetID(unsigned short wID, bool bResetTimer) { return CallMemberFunction<CQUEST, void, unsigned short, bool>(0x10064380, this, wID, bResetTimer); }
unsigned short CQUEST::GetID() { return CallMemberFunction<CQUEST, unsigned short>(0x1000CA70, this); }
void CQUEST::Set_VAR(int iVarNO, int iValue) { return CallMemberFunction<CQUEST, void, int, int>(0x10064120, this, iVarNO, iValue); }
int CQUEST::Get_VAR(int iVarNO) { return CallMemberFunction<CQUEST, int, int>(0x100640F0, this, iVarNO); }
unsigned long CQUEST::Get_SWITCHs() { return 0; }
void CQUEST::Set_SWITCHs(unsigned long Var1) { return; }
void CQUEST::Set_SWITCH(int iSwitchNO, int iValue) { return CallMemberFunction<CQUEST, void, int, int>(0x10064280, this, iSwitchNO, iValue); }
int CQUEST::Get_SWITCH(int iSwitchNO) { return CallMemberFunction<CQUEST, int, int>(0x10064240, this, iSwitchNO); }
int CQUEST::Flip_SWITCH(int iSwitchNO) { return CallMemberFunction<CQUEST, int, int>(0x100645C0, this, iSwitchNO); }
unsigned long CQUEST::GetExpirationTIME() { return 0; }
unsigned long CQUEST::GetRemainTIME() { return CallMemberFunction<CQUEST, unsigned long>(0x10064330, this); }
tagBaseITEM* CQUEST::GetSameITEM(unsigned short wItemHEADER) { return CallMemberFunction<CQUEST, tagBaseITEM*, unsigned short>(0x100641C0, this, wItemHEADER); }
tagBaseITEM* CQUEST::GetSlotITEM(int iSlotNo) { return CallMemberFunction<CQUEST, tagBaseITEM*, int>(0x10063FC0, this, iSlotNo); }
bool CQUEST::SubITEM(tagITEM& sITEM) { return CallMemberFunction<CQUEST, bool, tagITEM&>(0x10064600, this, sITEM); }
bool CQUEST::AddITEM(tagITEM& sITEM) { return CallMemberFunction<CQUEST, bool, tagITEM&>(0x10064490, this, sITEM); }
void CQUEST::CheckExpiredTIME() { return CallMemberFunction<CQUEST, void>(0x10064420, this); }



