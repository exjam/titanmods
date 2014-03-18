////////////////////////////////////////////////////////////////////////
///////  CIndexARRAY  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#include "CIndexARRAY.h"

class CParty;

void CIndexARRAY<CParty *>::Lock() { return CallMemberFunction< CIndexARRAY<CParty *>, void>(0x1000FD10, this ); }
void CIndexARRAY<CParty *>::Unlock() { return CallMemberFunction< CIndexARRAY<CParty *>, void>(0x1000FD30, this ); }
unsigned int CIndexARRAY<CParty *>::GetEmptySlot() { return CallMemberFunction< CIndexARRAY<CParty *>, unsigned int>(0x1000FD50, this ); }
int CIndexARRAY<CParty *>::GetEmptySlotCNT() { return CallMemberFunction< CIndexARRAY<CParty *>, int>(0xFFFFFFFF, this ); }
int CIndexARRAY<CParty *>::GetUsedSlotCNT() { return CallMemberFunction< CIndexARRAY<CParty *>, int>(0x10002180, this ); }
CParty* CIndexARRAY<CParty *>::GetData(unsigned int Var0 ) { return CallMemberFunction< CIndexARRAY<CParty *>, CParty*, unsigned int>(0x1000E810, this, Var0  ); }

class CGameOBJ;

void CIndexARRAY<CGameOBJ *>::Lock() { return CallMemberFunction<CIndexARRAY<CGameOBJ *>, void>(0x1000C650, this); }
void CIndexARRAY<CGameOBJ *>::Unlock() { return CallMemberFunction<CIndexARRAY<CGameOBJ *>, void>(0x1000C670, this); }
unsigned int CIndexARRAY<CGameOBJ *>::GetEmptySlot() { return CallMemberFunction<CIndexARRAY<CGameOBJ *>, unsigned int>(0x10015830, this); }
CGameOBJ* CIndexARRAY<CGameOBJ *>::GetData(unsigned int uiSlotNo) { return CallMemberFunction<CIndexARRAY<CGameOBJ *>, CGameOBJ*, unsigned int>(0x1000C6E0, this, uiSlotNo); }
