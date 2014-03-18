#include "SHO_GS.h"

void tagBaseITEM::Init(int iItem, unsigned int uiQuantity) { return CallMemberFunction<tagBaseITEM, void, int, unsigned int>(0x10098640, this, iItem, uiQuantity); }
void tagBaseITEM::Clear() { return CallMemberFunction<tagBaseITEM, void>(0x10006970, this); }
unsigned short tagBaseITEM::GetTYPE() { return CallMemberFunction<tagBaseITEM, unsigned short>(0x10001370, this); }
unsigned short tagBaseITEM::GetItemNO() { return CallMemberFunction<tagBaseITEM, unsigned short>(0x10001390, this); }
unsigned short tagBaseITEM::GetHEADER() { return CallMemberFunction<tagBaseITEM, unsigned short>(0x1000CA50, this); }
unsigned short tagBaseITEM::GetGrade() { return CallMemberFunction<tagBaseITEM, unsigned short>(0x100069A0, this); }
unsigned short tagBaseITEM::GetOption() { return CallMemberFunction<tagBaseITEM, unsigned short>(0x1000DE20, this); }
unsigned short tagBaseITEM::GetGemNO() { return CallMemberFunction<tagBaseITEM, unsigned short>(0x100069C0, this); }
unsigned short tagBaseITEM::GetLife() { return CallMemberFunction<tagBaseITEM, unsigned short>(0x1000FF70, this); }
unsigned short tagBaseITEM::GetDurability() { return CallMemberFunction<tagBaseITEM, unsigned short>(0x1000FF90, this); }
unsigned int tagBaseITEM::GetMoney() { return CallMemberFunction<tagBaseITEM, unsigned int>(0x1000FFB0, this); }
bool tagBaseITEM::IsEmpty() { return CallMemberFunction<tagBaseITEM, bool>(0x1000DE00, this); }
bool tagBaseITEM::IsAppraisal() { return CallMemberFunction<tagBaseITEM, bool>(0x1000FFD0, this); }
bool tagBaseITEM::HasSocket() { return CallMemberFunction<tagBaseITEM, bool>(0x10010000, this); }
bool tagBaseITEM::IsEnableDROP() { return CallMemberFunction<tagBaseITEM, bool>(0x10098510, this); }
bool tagBaseITEM::IsEnableSELL() { return CallMemberFunction<tagBaseITEM, bool>(0x10098490, this); }
bool tagBaseITEM::IsEnableKEEPING() { return CallMemberFunction<tagBaseITEM, bool>(0x10098590, this); }
bool tagBaseITEM::IsValidITEM() { return CallStaticFunction<0x100013B0, bool>(); }
bool tagBaseITEM::IsValidITEM(tagBaseITEM* pItem) { return CallStaticFunction<0x10010030, bool, tagBaseITEM*>(pItem); }
bool tagBaseITEM::IsValidITEM(unsigned short wType, unsigned short wItemNO) { return CallStaticFunction<0x10098430, bool, unsigned short, unsigned short>(wType, wItemNO); }
bool tagBaseITEM::IsEnableDupCNT() { return CallStaticFunction<0x10006A20, bool>(); }
bool tagBaseITEM::IsEnableDupCNT(unsigned short cType) { return CallStaticFunction<0x100069E0, bool, unsigned short>(cType); }
bool tagBaseITEM::IsCreated() { return 0; }
bool tagBaseITEM::IsEquipITEM() { return CallMemberFunction<tagBaseITEM, bool>(0x1000DE40, this); }
bool tagBaseITEM::IsEtcITEM() { return CallMemberFunction<tagBaseITEM, bool>(0x10010060, this); }
bool tagBaseITEM::IsTwoHands() { return CallMemberFunction<tagBaseITEM, bool>(0x100983B0, this); }
t_eSHOT tagBaseITEM::GetShotTYPE() { return CallMemberFunction<tagBaseITEM, t_eSHOT>(0x100982F0, this); }
t_EquipINDEX tagBaseITEM::GetEquipPOS() { return CallMemberFunction<tagBaseITEM, t_EquipINDEX>(0x10098210, this); }
unsigned int tagBaseITEM::GetQuantity() { return CallMemberFunction<tagBaseITEM, unsigned int>(0x10006A50, this); }



