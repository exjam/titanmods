#include "CLIB_GameSRV.h"

void EXE_GS_API::SetUserCNT(int Var1) { return; }
void EXE_GS_API::WriteLOG(char* Var1) { return; }
void EXE_GS_API::SetListItemINT(void* Var1, int Var2, int Var3) { return; }
void EXE_GS_API::SetListItemSTR(void* Var1, int Var2, char* Var3) { return; }
void* EXE_GS_API::AddZoneITEM(void* Var1, short Var2, char* Var3) { return 0; }
void EXE_GS_API::DelZoneITEM(void* Var1) { return; }
EXE_GS_API::EXE_GS_API() { }

CLIB_GameSRV::CLIB_GameSRV(EXE_GS_API* pExeAPI) {};
CLIB_GameSRV::~CLIB_GameSRV() {};
void CLIB_GameSRV::SystemINIT(HINSTANCE__* hInstance, char* szBaseDataDIR, int iLangType) { return CallMemberFunction<CLIB_GameSRV, void, HINSTANCE__*, char*, int>(0x100AB3C0, this, hInstance, szBaseDataDIR, iLangType); }
bool CLIB_GameSRV::CheckSTB_UseITEM() { return CallMemberFunction<CLIB_GameSRV, bool>(0x100A8C00, this); }
bool CLIB_GameSRV::CheckSTB_NPC() { return CallMemberFunction<CLIB_GameSRV, bool>(0x100A90D0, this); }
bool CLIB_GameSRV::CheckSTB_DropITEM() { return CallMemberFunction<CLIB_GameSRV, bool>(0x100A88D0, this); }
bool CLIB_GameSRV::CheckSTB_ItemRateTYPE() { return CallMemberFunction<CLIB_GameSRV, bool>(0x100A87D0, this); }
bool CLIB_GameSRV::CheckSTB_Motion() { return CallMemberFunction<CLIB_GameSRV, bool>(0x100A9020, this); }
bool CLIB_GameSRV::CheckSTB_GemITEM() { return CallMemberFunction<CLIB_GameSRV, bool>(0x100A86F0, this); }
bool CLIB_GameSRV::CheckSTB_ListPRODUCT() { return CallMemberFunction<CLIB_GameSRV, bool>(0x100A9360, this); }
bool CLIB_GameSRV::Load_BasicDATA() { return CallMemberFunction<CLIB_GameSRV, bool>(0x100AA970, this); }
void CLIB_GameSRV::Free_BasicDATA() { return CallMemberFunction<CLIB_GameSRV, void>(0x100A9D10, this); }
bool CLIB_GameSRV::ConnectToLSV() { return CallMemberFunction<CLIB_GameSRV, bool>(0x100A8BD0, this); }
void CLIB_GameSRV::DisconnectFromLSV() { return CallMemberFunction<CLIB_GameSRV, void>(0x100A8590, this); }
bool CLIB_GameSRV::ConnectToASV() { return CallMemberFunction<CLIB_GameSRV, bool>(0x100A8BA0, this); }
void CLIB_GameSRV::DisconnectFromASV() { return CallMemberFunction<CLIB_GameSRV, void>(0x100A8560, this); }
bool CLIB_GameSRV::ConnectToLOG() { return CallMemberFunction<CLIB_GameSRV, bool>(0x100A8540, this); }
void CLIB_GameSRV::DisconnectFromLOG() { return CallMemberFunction<CLIB_GameSRV, void>(0x100A8520, this); }
void CLIB_GameSRV::TranslateNameWithDescKey(STBDATA* pOri, char* szStbFile, int iLangCol) { return CallMemberFunction<CLIB_GameSRV, void, STBDATA*, char*, int>(0x100A9F60, this, pOri, szStbFile, iLangCol); }
void CLIB_GameSRV::TranslateNameWithColoumKey(STBDATA* pOri, char* szStbFile, int iLangCol, int iNameCol, int iDescCol) { return CallMemberFunction<CLIB_GameSRV, void, STBDATA*, char*, int, int, int>(0x100A9D60, this, pOri, szStbFile, iLangCol, iNameCol, iDescCol); }
bool CLIB_GameSRV::ConnectSERVER(char* szDBServerIP, char* szDBName, char* szDBUser, char* szDBPassword, char* szLogUser, char* szLogPW, char* szMallUser, char* szMallPW, char* szLoginServerIP, int iLoginServerPort, char* szAccountServerIP, int iAccountServerPortNO) { return CallMemberFunction<CLIB_GameSRV, bool, char*, char*, char*, char*, char*, char*, char*, char*, char*, int, char*, int>(0x100A9910, this, szDBServerIP, szDBName, szDBUser, szDBPassword, szLogUser, szLogPW, szMallUser, szMallPW, szLoginServerIP, iLoginServerPort, szAccountServerIP, iAccountServerPortNO); }
bool CLIB_GameSRV::Start(HWND__* hMainWND, char* szServerName, char* szClientListenIP, int iClientListenPort, unsigned char btChannelNO, unsigned char btLowAge, unsigned char btHighAge) { return CallMemberFunction<CLIB_GameSRV, bool, HWND__*, char*, char*, int, unsigned char, unsigned char, unsigned char>(0x100AB740, this, hMainWND, szServerName, szClientListenIP, iClientListenPort, btChannelNO, btLowAge, btHighAge); }
void CLIB_GameSRV::Shutdown() { return CallMemberFunction<CLIB_GameSRV, void>(0x100A9740, this); }
short CLIB_GameSRV::InitLocalZone(bool bAllActive) { return CallMemberFunction<CLIB_GameSRV, short, bool>(0x100A8620, this, bAllActive); }
bool CLIB_GameSRV::CheckZoneToLocal(short nZoneNO, bool bChecked) { return CallMemberFunction<CLIB_GameSRV, bool, short, bool>(0x100A85C0, this, nZoneNO, bChecked); }
char* CLIB_GameSRV::GetZoneName(short nZoneNO) { return CallMemberFunction<CLIB_GameSRV, char*, short>(0x100A8F40, this, nZoneNO); }
bool CLIB_GameSRV::IsLocalCheckedZONE(short nZoneNO) { return CallMemberFunction<CLIB_GameSRV, bool, short>(0x1000EDE0, this, nZoneNO); }
char* CLIB_GameSRV::GetServerName() { return CallMemberFunction<CLIB_GameSRV, char*>(0x100041A0, this); }
char* CLIB_GameSRV::GetServerIP() { return CallMemberFunction<CLIB_GameSRV, char*>(0x10001A30, this); }
int CLIB_GameSRV::GetListenPort() { return CallMemberFunction<CLIB_GameSRV, int>(0x100041D0, this); }
unsigned long CLIB_GameSRV::GetRandomSeed() { return CallMemberFunction<CLIB_GameSRV, unsigned long>(0x100041F0, this); }
unsigned char CLIB_GameSRV::GetChannelNO() { return CallMemberFunction<CLIB_GameSRV, unsigned char>(0x10004210, this); }
unsigned char CLIB_GameSRV::GetLowAGE() { return CallMemberFunction<CLIB_GameSRV, unsigned char>(0x10004230, this); }
unsigned char CLIB_GameSRV::GetHighAGE() { return CallMemberFunction<CLIB_GameSRV, unsigned char>(0x10004250, this); }
bool CLIB_GameSRV::IsTestServer() { return CallMemberFunction<CLIB_GameSRV, bool>(0x1000F910, this); }
int CLIB_GameSRV::GetLangTYPE() { return CallMemberFunction<CLIB_GameSRV, int>(0x10001A60, this); }
void CLIB_GameSRV::Send_ANNOUNCE(short nZoneNO, char* szMsg) { return CallMemberFunction<CLIB_GameSRV, void, short, char*>(0x100AA920, this, nZoneNO, szMsg); }
void CLIB_GameSRV::Set_UserLIMIT(unsigned long dwUserLimit) { return CallMemberFunction<CLIB_GameSRV, void, unsigned long>(0x100A96F0, this, dwUserLimit); }
unsigned long CLIB_GameSRV::Get_UserLIMIT() { return CallMemberFunction<CLIB_GameSRV, unsigned long>(0x10004270, this); }
EXE_GS_API* CLIB_GameSRV::ExeAPI() { return CallStaticFunction<0x10001A80, EXE_GS_API*>(); }
CLIB_GameSRV* CLIB_GameSRV::GetInstance() { return CallStaticFunction<0x10001050, CLIB_GameSRV*>(); }
CLIB_GameSRV* CLIB_GameSRV::InitInstance(HINSTANCE__* hInstance, char* szBaseDataDIR, EXE_GS_API* pExeAPI, int iLangType) { return CallStaticFunction<0x10001060, CLIB_GameSRV*, HINSTANCE__*, char*, EXE_GS_API*, int>(hInstance, szBaseDataDIR, pExeAPI, iLangType); }
void CLIB_GameSRV::Destroy() { return CallMemberFunction<CLIB_GameSRV, void>(0x10001150, this); }



