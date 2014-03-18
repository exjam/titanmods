////////////////////////////////////////////////////////////////////////
///////  CEconomy  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CEconomy_H
#define CEconomy_H
#include "SHO_GS.h"

class TGAMESERVER_API CEconomy   { 
public: 
  int m_iTownCounter;
  static bool IsEssentialGoods(int iItemTYPE);
  CEconomy();
  ~CEconomy();
  void Init();
  void SetTownRATE(int iValue);
  void SetItemRATE(int iPriceType, int iValue);
  unsigned char Get_TownRATE();
  int Get_ItemRATE(short nItemTYPE);
  int Get_ItemBuyPRICE(short nItemTYPE, short nItemNO, short nBuySkillVALUE);
  int Get_ItemSellPRICE(tagITEM& sITEM, short nSellSkillVALUE);
  int Get_EconomyVAR(short nVarIDX);
  bool Load(_iobuf* fp);
  void BuyITEM(tagITEM& sITEM);
  void SellITEM(tagITEM& sITEM, int iQuantity);
  int Get_TownITEM(short Var1);
  bool Proc(unsigned long dwCurTIME);
};

#endif

