#include "CEconomy.h"

bool CEconomy::IsEssentialGoods(int iItemTYPE) { return CallStaticFunction<0x100587B0, bool, int>(iItemTYPE); }
CEconomy::CEconomy() {};
CEconomy::~CEconomy() {};
void CEconomy::Init() { return CallMemberFunction<CEconomy, void>(0x10058850, this); }
void CEconomy::SetTownRATE(int iValue) { return CallMemberFunction<CEconomy, void, int>(0x10058830, this, iValue); }
void CEconomy::SetItemRATE(int iPriceType, int iValue) { return CallMemberFunction<CEconomy, void, int, int>(0x100587E0, this, iPriceType, iValue); }
unsigned char CEconomy::Get_TownRATE() { return CallMemberFunction<CEconomy, unsigned char>(0x10010FC0, this); }
int CEconomy::Get_ItemRATE(short nItemTYPE) { return CallMemberFunction<CEconomy, int, short>(0x10015C50, this, nItemTYPE); }
int CEconomy::Get_ItemBuyPRICE(short nItemTYPE, short nItemNO, short nBuySkillVALUE) { return CallMemberFunction<CEconomy, int, short, short, short>(0x10058940, this, nItemTYPE, nItemNO, nBuySkillVALUE); }
int CEconomy::Get_ItemSellPRICE(tagITEM& sITEM, short nSellSkillVALUE) { return CallMemberFunction<CEconomy, int, tagITEM&, short>(0x10058EE0, this, sITEM, nSellSkillVALUE); }
int CEconomy::Get_EconomyVAR(short nVarIDX) { return CallMemberFunction<CEconomy, int, short>(0x10014410, this, nVarIDX); }
bool CEconomy::Load(_iobuf* fp) { return CallMemberFunction<CEconomy, bool, _iobuf*>(0x10058D60, this, fp); }
void CEconomy::BuyITEM(tagITEM& sITEM) { return CallMemberFunction<CEconomy, void, tagITEM&>(0x10058C70, this, sITEM); }
void CEconomy::SellITEM(tagITEM& sITEM, int iQuantity) { return CallMemberFunction<CEconomy, void, tagITEM&, int>(0x10058B80, this, sITEM, iQuantity); }
int CEconomy::Get_TownITEM(short Var1) { return 0; }
bool CEconomy::Proc(unsigned long dwCurTIME) { return CallMemberFunction<CEconomy, bool, unsigned long>(0x10059260, this, dwCurTIME); }



