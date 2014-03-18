////////////////////////////////////////////////////////////////////////
///////  CInventory  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CInventory_H
#define CInventory_H
#include "SHO_GS.h"

#pragma pack(push, 1)
class TGAMESERVER_API CInventory   { 
public: 
  static t_InvTYPE m_InvTYPE[0x20];//static, [000CA918][0003:00001918];
  __int64 m_i64Money;
	union {
		struct {
			tagITEM m_ItemLIST[0x8B];
		};
		struct { 
			tagITEM m_ItemEQUIP[0xC];
			tagITEM m_ItemPAGE[0x4][0x1E];
			tagITEM m_ItemSHOT[0x3];
			tagITEM m_ItemRIDE[0x4];
		};
	};
  void Clear();
  static short GetBodyPartByEquipSlot(short nEquipSlot);
  bool IDX_GetITEM(short Var1, short Var2, tagITEM& Var3);
  bool IDX_GetITEM(short Var1, tagITEM& Var2);
  tagITEM LST_GetITEM(t_InvTYPE InvTYPE, short nPageListNO);
  tagITEM LST_GetITEM(short nListNO);
  bool IDX_SetITEM(t_InvTYPE IdxInvTYPE, short nIdxPageListNO, t_InvTYPE LstInvTYPE, short nLstPageListNO, tagITEM& sITEM);
  bool IDX_SetITEM(t_InvTYPE InvTYPE, short nPageListNO, short nTotListNO, tagITEM& sITEM);
  bool IDX_SetITEM(short nIndexNO, short nListNO, tagITEM& sITEM);
  short AppendITEM(short nListRealNO, tagITEM& sITEM, short& nCurWeight);
  short AppendITEM(tagITEM& sITEM, short& nCurWeight);
  void DeleteITEM(unsigned short wListRealNO);
  short FindITEM(tagITEM& sITEM);
  void SubtractITEM(short nListNO, tagITEM& sITEM, short& nCurWEIGHT);
  short GetWEIGHT(short nListNO);
  void SetInventory(short nListNO, int iItem, int iQuantity);
  short GetEmptyInventory(short nInvPAGE);
  short GetEmptyInvenSlotCount(t_InvTYPE InvType);
  static t_InvTYPE GetInvPageTYPE(tagITEM& Var1);
};
#pragma pack(pop)

#endif

