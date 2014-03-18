#include "CInventory.h"

void CInventory::Clear() { return CallMemberFunction<CInventory, void>(0x1006F970, this); }
short CInventory::GetBodyPartByEquipSlot(short nEquipSlot) { return CallStaticFunction<0x1006F8D0, short, short>(nEquipSlot); }
bool CInventory::IDX_GetITEM(short Var1, short Var2, tagITEM& Var3) { return 0; }
bool CInventory::IDX_GetITEM(short Var1, tagITEM& Var2) { return 0; }
tagITEM CInventory::LST_GetITEM(t_InvTYPE InvTYPE, short nPageListNO) { return CallMemberFunction<CInventory, tagITEM, t_InvTYPE, short>(0x1006FD30, this, InvTYPE, nPageListNO); }
tagITEM CInventory::LST_GetITEM(short nListNO) { return CallMemberFunction<CInventory, tagITEM, short>(0x1006F850, this, nListNO); }
bool CInventory::IDX_SetITEM(t_InvTYPE IdxInvTYPE, short nIdxPageListNO, t_InvTYPE LstInvTYPE, short nLstPageListNO, tagITEM& sITEM) { return CallMemberFunction<CInventory, bool, t_InvTYPE, short, t_InvTYPE, short, tagITEM&>(0x1006FB30, this, IdxInvTYPE, nIdxPageListNO, LstInvTYPE, nLstPageListNO, sITEM); }
bool CInventory::IDX_SetITEM(t_InvTYPE InvTYPE, short nPageListNO, short nTotListNO, tagITEM& sITEM) { return CallMemberFunction<CInventory, bool, t_InvTYPE, short, short, tagITEM&>(0x1006FC50, this, InvTYPE, nPageListNO, nTotListNO, sITEM); }
bool CInventory::IDX_SetITEM(short nIndexNO, short nListNO, tagITEM& sITEM) { return CallMemberFunction<CInventory, bool, short, short, tagITEM&>(0x1006F810, this, nIndexNO, nListNO, sITEM); }
short CInventory::AppendITEM(short nListRealNO, tagITEM& sITEM, short& nCurWeight) { return CallMemberFunction<CInventory, short, short, tagITEM&, short&>(0x1006FF90, this, nListRealNO, sITEM, nCurWeight); }
short CInventory::AppendITEM(tagITEM& sITEM, short& nCurWeight) { return CallMemberFunction<CInventory, short, tagITEM&, short&>(0x100700C0, this, sITEM, nCurWeight); }
void CInventory::DeleteITEM(unsigned short wListRealNO) { return CallMemberFunction<CInventory, void, unsigned short>(0x1006FDE0, this, wListRealNO); }
short CInventory::FindITEM(tagITEM& sITEM) { return CallMemberFunction<CInventory, short, tagITEM&>(0x1006FA80, this, sITEM); }
void CInventory::SubtractITEM(short nListNO, tagITEM& sITEM, short& nCurWEIGHT) { return CallMemberFunction<CInventory, void, short, tagITEM&, short&>(0x1006FEF0, this, nListNO, sITEM, nCurWEIGHT); }
short CInventory::GetWEIGHT(short nListNO) { return CallMemberFunction<CInventory, short, short>(0x1006FE20, this, nListNO); }
void CInventory::SetInventory(short nListNO, int iItem, int iQuantity) { return CallMemberFunction<CInventory, void, short, int, int>(0x100703A0, this, nListNO, iItem, iQuantity); }
short CInventory::GetEmptyInventory(short nInvPAGE) { return CallMemberFunction<CInventory, short, short>(0x1006F720, this, nInvPAGE); }
short CInventory::GetEmptyInvenSlotCount(t_InvTYPE InvType) { return CallMemberFunction<CInventory, short, t_InvTYPE>(0x1006F9C0, this, InvType); }
t_InvTYPE CInventory::GetInvPageTYPE(tagITEM& Var1) { return t_InvTYPE(); }



