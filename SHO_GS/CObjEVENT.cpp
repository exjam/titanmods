#include "CObjEVENT.h"

bool CObjEVENT::Send_gsv_SET_EVENT_STATUS() { return CallMemberFunction<CObjEVENT, bool>(0x100ABFA0, this); }
CObjEVENT::CObjEVENT(const CObjEVENT& Var1) { }
CObjEVENT::CObjEVENT() {};
CObjEVENT::~CObjEVENT() {};
t_ObjTAG CObjEVENT::Get_TYPE() { return CallMemberFunction<CObjEVENT, t_ObjTAG>(0x100168A0, this); }
bool CObjEVENT::Make_gsv_ADD_OBJECT(classPACKET* pCPacket) { return CallMemberFunction<CObjEVENT, bool, classPACKET*>(0x100ABD00, this, pCPacket); }
short CObjEVENT::VGetCur_ZoneNO() { return CallMemberFunction<CObjEVENT, short>(0x100ABD80, this); }
float CObjEVENT::VGetCur_XPOS() { return CallMemberFunction<CObjEVENT, float>(0x100168C0, this); }
float CObjEVENT::VGetCur_YPOS() { return CallMemberFunction<CObjEVENT, float>(0x100168E0, this); }
int CObjEVENT::VGetCur_ZoneTIME() { return CallMemberFunction<CObjEVENT, int>(0x10016900, this); }
void CObjEVENT::Set_ObjVAR(unsigned char btVarIDX, short nValue) { return CallMemberFunction<CObjEVENT, void, unsigned char, short>(0x10016930, this, btVarIDX, nValue); }
unsigned long CObjEVENT::Get_ID() { return CallMemberFunction<CObjEVENT, unsigned long>(0x1000E240, this); }
bool CObjEVENT::Init(CZoneTHREAD* pZONE, char cMapX, char cMapY, float fWorldX, float fWorldY, unsigned short wMapEventID) { return CallMemberFunction<CObjEVENT, bool, CZoneTHREAD*, char, char, float, float, unsigned short>(0x100ABEF0, this, pZONE, cMapX, cMapY, fWorldX, fWorldY, wMapEventID); }
int CObjEVENT::Proc() { return CallMemberFunction<CObjEVENT, int>(0x100ABDB0, this); }



