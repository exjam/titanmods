#include "CAI_OBJ.h"

CAI_OBJ::CAI_OBJ() {};
unsigned long CAI_OBJ::Get_AICheckTIME(int iIDX) { return CallMemberFunction<CAI_OBJ, unsigned long, int>(0x10014620, this, iIDX); }
void CAI_OBJ::Set_AICheckTIME(int iIDX, unsigned long lCheckTIME) { return CallMemberFunction<CAI_OBJ, void, int, unsigned long>(0x10014640, this, iIDX, lCheckTIME); }
float CAI_OBJ::Get_CurXPOS() { return 0; }
float CAI_OBJ::Get_CurYPOS() { return 0; }
float CAI_OBJ::Get_BornXPOS() { return 0; }
float CAI_OBJ::Get_BornYPOS() { return 0; }
int CAI_OBJ::Get_TAG() { return 0; }
int CAI_OBJ::Get_ObjTYPE() { return 0; }
int CAI_OBJ::Get_PercentHP() { return 0; }
int CAI_OBJ::Get_HP() { return 0; }
int CAI_OBJ::Get_CharNO() { return 0; }
int CAI_OBJ::Get_LEVEL() { return 0; }
int CAI_OBJ::Get_ATK() { return 0; }
int CAI_OBJ::Get_DEF() { return 0; }
int CAI_OBJ::Get_RES() { return 0; }
int CAI_OBJ::Get_HIT() { return 0; }
int CAI_OBJ::Get_CHARM() { return 0; }
int CAI_OBJ::Get_AVOID() { return 0; }
int CAI_OBJ::Get_SENSE() { return 0; }
int CAI_OBJ::Get_GiveEXP() { return 0; }
int CAI_OBJ::Get_CRITICAL() { return 0; }
CAI_OBJ* CAI_OBJ::Get_TARGET(bool Var1) { return 0; }
CAI_OBJ* CAI_OBJ::Get_CALLER() { return CallMemberFunction<CAI_OBJ, CAI_OBJ*>(0x10011B50, this); }
float CAI_OBJ::Get_DISTANCE(CAI_OBJ* Var1) { return 0; }
float CAI_OBJ::Get_MoveDISTANCE() { return 0; }
int CAI_OBJ::Get_RANDOM(int Var1) { return 0; }
bool CAI_OBJ::Change_CHAR(int Var0) { return CallMemberFunction<CAI_OBJ, bool, int>(0x10007170, this, Var0); }
bool CAI_OBJ::Create_PET(int Var0, float Var1, float Var2, int Var3, unsigned char Var4, bool Var5) { return CallMemberFunction<CAI_OBJ, bool, int, float, float, int, unsigned char, bool>(0x10011B70, this, Var0, Var1, Var2, Var3, Var4, Var5); }
bool CAI_OBJ::Is_ClanMASTER() { return CallMemberFunction<CAI_OBJ, bool>(0x10011B90, this); }
void CAI_OBJ::Say_MESSAGE(char* Var0) { return CallMemberFunction<CAI_OBJ, void, char*>(0x10007190, this, Var0); }
void CAI_OBJ::Run_AWAY(int Var0) { return CallMemberFunction<CAI_OBJ, void, int>(0x100071B0, this, Var0); }
void CAI_OBJ::Drop_ITEM(short Var0, unsigned char Var1) { return CallMemberFunction<CAI_OBJ, void, short, unsigned char>(0x100071D0, this, Var0, Var1); }
int CAI_OBJ::Get_AiVAR(short Var0) { return CallMemberFunction<CAI_OBJ, int, short>(0x100071F0, this, Var0); }
void CAI_OBJ::Set_AiVAR(short Var0, int Var1) { return CallMemberFunction<CAI_OBJ, void, short, int>(0x10007210, this, Var0, Var1); }
void CAI_OBJ::Recv_ITEM(short Var0, short Var1) { return CallMemberFunction<CAI_OBJ, void, short, short>(0x10011BB0, this, Var0, Var1); }
void CAI_OBJ::Set_EMOTION(short Var0) { return CallMemberFunction<CAI_OBJ, void, short>(0x10007230, this, Var0); }
bool CAI_OBJ::SetCMD_STOP() { return 0; }
bool CAI_OBJ::SetCMD_MOVE2D(float Var1, float Var2, unsigned char Var3) { return 0; }
void CAI_OBJ::SetCMD_RUNnATTACK(int Var1) { return; }
void CAI_OBJ::Special_ATTACK() { return; }
CAI_OBJ* CAI_OBJ::AI_FindFirstOBJ(int Var1) { return 0; }
CAI_OBJ* CAI_OBJ::AI_FindNextOBJ() { return 0; }
int CAI_OBJ::Get_EconomyVAR(short Var0) { return CallMemberFunction<CAI_OBJ, int, short>(0x10011BD0, this, Var0); }
int CAI_OBJ::Get_WorldVAR(short Var0) { return CallMemberFunction<CAI_OBJ, int, short>(0x10011BF0, this, Var0); }
int CAI_OBJ::Get_TeamNO() { return 0; }
bool CAI_OBJ::Is_ALLIED(CAI_OBJ* pDestOBJ) { return CallMemberFunction<CAI_OBJ, bool, CAI_OBJ*>(0x10011C10, this, pDestOBJ); }
bool CAI_OBJ::Is_SameTEAM(CAI_OBJ* pDestOBJ) { return CallMemberFunction<CAI_OBJ, bool, CAI_OBJ*>(0x100165A0, this, pDestOBJ); }
unsigned char CAI_OBJ::Is_DAY() { return 0; }
int CAI_OBJ::Get_ZoneTIME() { return 0; }
int CAI_OBJ::Get_WorldTIME() { return 0; }
void CAI_OBJ::Set_TRIGGER(unsigned long Var0) { return CallMemberFunction<CAI_OBJ, void, unsigned long>(0x10007250, this, Var0); }
t_ObjTAG CAI_OBJ::Get_CharObjTAG() { return t_ObjTAG(); }
unsigned long CAI_OBJ::Get_MagicSTATUS() { return 0; }
CAI_OBJ* CAI_OBJ::Find_LocalNPC(int Var1) { return 0; }
void CAI_OBJ::Set_EconomyVAR(short Var1, int Var2) { return; }
void CAI_OBJ::Set_WorldVAR(short Var1, int Var2) { return; }
void CAI_OBJ::Add_DAMAGE(unsigned short Var1) { return; }
bool CAI_OBJ::Send_gsv_CHAT(char* Var1) { return 0; }
bool CAI_OBJ::Send_gsv_SHOUT(char* Var1) { return 0; }
void CAI_OBJ::Send_gsv_ANNOUNCE_CHAT(char* Var1) { return; }
bool CAI_OBJ::SetCMD_Skill2SELF(short Var0, short Var1) { return CallMemberFunction<CAI_OBJ, bool, short, short>(0x10007270, this, Var0, Var1); }
bool CAI_OBJ::SetCMD_Skill2OBJ(int Var0, short Var1, short Var2) { return CallMemberFunction<CAI_OBJ, bool, int, short, short>(0x10007290, this, Var0, Var1, Var2); }



