#include "CParty.h"

void CParty::LevelUP() { return CallMemberFunction<CParty, void>(0x100AD010, this); }
bool CParty::Send_PartyUserLIST(classUSER* pUSER, unsigned long dwUserTAG) { return CallMemberFunction<CParty, bool, classUSER*, unsigned long>(0x100AE310, this, pUSER, dwUserTAG); }
bool CParty::Send_gsv_PARTY_ITEM(classUSER* pPicker, CObjITEM* pItemOBJ) { return CallMemberFunction<CParty, bool, classUSER*, CObjITEM*>(0x100AD980, this, pPicker, pItemOBJ); }
CParty::CParty() {};
void CParty::InitPARTY() { return CallMemberFunction<CParty, void>(0x1000FA70, this); }
classUSER* CParty::GetPartyOWNER() { return CallMemberFunction<CParty, classUSER*>(0x10009D20, this); }
bool CParty::AddEXP(CObjMOB* pMobCHAR, int iTotalEXP, int iPartyExpA, int iPartyExpB) { return CallMemberFunction<CParty, bool, CObjMOB*, int, int, int>(0x100AE630, this, pMobCHAR, iTotalEXP, iPartyExpA, iPartyExpB); }
bool CParty::Change_PartyOWNER(classUSER* pNewOWNER, unsigned char btReply) { return CallMemberFunction<CParty, bool, classUSER*, unsigned char>(0x100ADA20, this, pNewOWNER, btReply); }
bool CParty::Change_ObjectIDX(classUSER* pUSER) { return CallMemberFunction<CParty, bool, classUSER*>(0x100ADB20, this, pUSER); }
unsigned char CParty::Add_PartyUSER(classUSER* pUSER) { return CallMemberFunction<CParty, unsigned char, classUSER*>(0x100AED20, this, pUSER); }
bool CParty::Sub_PartyUSER(short nPartyPOS) { return CallMemberFunction<CParty, bool, short>(0x100AE070, this, nPartyPOS); }
bool CParty::Kick_MEMBER(unsigned long dwDBID) { return CallMemberFunction<CParty, bool, unsigned long>(0x100AEA20, this, dwDBID); }
void CParty::Member_LevelUP(short nPartyPOS, short nLevelDIFF) { return CallMemberFunction<CParty, void, short, short>(0x100ACD90, this, nPartyPOS, nLevelDIFF); }
bool CParty::Give_Item2ORDER(classUSER* pTryOBJ, CObjITEM* pItemOBJ) { return CallMemberFunction<CParty, bool, classUSER*, CObjITEM*>(0x100ADF20, this, pTryOBJ, pItemOBJ); }
bool CParty::Is_ShareMODE() { return CallMemberFunction<CParty, bool>(0x10010DF0, this); }
void CParty::Share_MONEY(int iMoney) { return CallMemberFunction<CParty, void, int>(0x100ACF10, this, iMoney); }
int CParty::GetMemberCNT() { return CallMemberFunction<CParty, int>(0x10009D90, this); }
unsigned char CParty::GetPartyLEV() { return CallMemberFunction<CParty, unsigned char>(0x10009DB0, this); }
int CParty::GetAverageLEV() { return CallMemberFunction<CParty, int>(0x10010E20, this); }
int CParty::GetPartyEXP() { return CallMemberFunction<CParty, int>(0x100163D0, this); }
bool CParty::SendWhisperToPartyMembers(char* szMessage) { return CallMemberFunction<CParty, bool, char*>(0x100ADD40, this, szMessage); }
bool CParty::Send_gsv_PARTY_REPLY2Members(unsigned char btReply, unsigned long dwFromIDXorTAG) { return CallMemberFunction<CParty, bool, unsigned char, unsigned long>(0x100AD910, this, btReply, dwFromIDXorTAG); }
bool CParty::SendToPartyMembers(classPACKET* pCPacket) { return CallMemberFunction<CParty, bool, classPACKET*>(0x100AD1D0, this, pCPacket); }
bool CParty::SendToPartyMembersExceptME(classUSER* pSender, classPACKET* pCPacket) { return CallMemberFunction<CParty, bool, classUSER*, classPACKET*>(0x100ACCC0, this, pSender, pCPacket); }
bool CParty::SendPartyLEVnEXP(classUSER* pUSER, unsigned char bitLevelUP) { return CallMemberFunction<CParty, bool, classUSER*, unsigned char>(0x100ADC60, this, pUSER, bitLevelUP); }
bool CParty::Send_gsv_CHECK_NPC_EVENT(classUSER* pTryOBJ, short nNpcIDX) { return CallMemberFunction<CParty, bool, classUSER*, short>(0x100AD770, this, pTryOBJ, nNpcIDX); }
void CParty::Set_PartyRULE(unsigned char btRULE) { return CallMemberFunction<CParty, void, unsigned char>(0x100AD610, this, btRULE); }
void CParty::Warp_USERS(int iZoneNO, CVec2& PosGOTO) { return CallMemberFunction<CParty, void, int, CVec2&>(0x100AD580, this, iZoneNO, PosGOTO); }
void CParty::OnConnect(classUSER* pUSER) { return CallMemberFunction<CParty, void, classUSER*>(0x100AEC10, this, pUSER); }
void CParty::OnDisconnect(classUSER* pUSER) { return CallMemberFunction<CParty, void, classUSER*>(0x100AEB00, this, pUSER); }
CParty::~CParty() {};

CParty* CPartyBUFF::Pool_Alloc() { return CallMemberFunction<CPartyBUFF, CParty*>(0x1000FB10, this); }
void CPartyBUFF::Pool_Free(CParty* pCParty) { return CallMemberFunction<CPartyBUFF, void, CParty*>(0x1000FBA0, this, pCParty); }
CPartyBUFF::CPartyBUFF() { }
CPartyBUFF::CPartyBUFF(unsigned short wMaxPartyCNT) {};
CPartyBUFF::~CPartyBUFF() {};
bool CPartyBUFF::CreatePARTY(classUSER* pOwner) { return CallMemberFunction<CPartyBUFF, bool, classUSER*>(0x100AD2B0, this, pOwner); }
void CPartyBUFF::DeletePARTY(CParty* pCParty) { return CallMemberFunction<CPartyBUFF, void, CParty*>(0x100ADDC0, this, pCParty); }
void CPartyBUFF::OnConnect(unsigned int uiPartyIDX, classUSER* pUSER) { return CallMemberFunction<CPartyBUFF, void, unsigned int, classUSER*>(0x1000E260, this, uiPartyIDX, pUSER); }


