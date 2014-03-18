////////////////////////////////////////////////////////////////////////
///////  CLIB_GameSRV  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CLIB_GameSRV_H
#define CLIB_GameSRV_H
#include "SHO_GS.h"

class STBDATA;
class CTimer;

class TGAMESERVER_API EXE_GS_API   { 
public: 
  virtual void SetUserCNT(int Var1);
  virtual void WriteLOG(char* Var1);
  virtual void SetListItemINT(void* Var1, int Var2, int Var3);
  virtual void SetListItemSTR(void* Var1, int Var2, char* Var3);
  virtual void* AddZoneITEM(void* Var1, short Var2, char* Var3);
  virtual void DelZoneITEM(void* Var1);
  EXE_GS_API();
};

class TGAMESERVER_API CLIB_GameSRV   { 
public: 
  static CLIB_GameSRV* m_pInstance;//static, [000CBA44][0003:00002A44];
  EXE_GS_API* m_pExeAPI;
  HWND__* m_hMainWND;
  CTimer* m_pWorldTIMER;
  bool* m_pCheckedLocalZONE;
  CStrVAR m_BaseDataDIR;
  CStrVAR m_ServerNAME;
  CStrVAR m_ServerIP;
  int m_iListenPortNO;
  CStrVAR m_DBServerIP;
  CStrVAR m_DBName;
  CStrVAR m_DBUser;
  CStrVAR m_DBPassword;
  CStrVAR m_LogUser;
  CStrVAR m_LogPW;
  CStrVAR m_AccountServerIP;
  int m_iAccountServerPORT;
  CStrVAR m_LoginServerIP;
  int m_iLoginServerPORT;
  unsigned long m_dwRandomSEED;
  unsigned char m_btChannelNO;
  unsigned char m_btLowAGE;
  unsigned char m_btHighAGE;
  unsigned long m_dwUserLIMIT;
  int m_iLangTYPE;
  bool m_bTestServer;
  CLIB_GameSRV(const CLIB_GameSRV& Var1);
  CLIB_GameSRV(EXE_GS_API* pExeAPI);
  virtual ~CLIB_GameSRV();
  void SystemINIT(HINSTANCE__* hInstance, char* szBaseDataDIR, int iLangType);
  bool CheckSTB_UseITEM();
  bool CheckSTB_NPC();
  bool CheckSTB_DropITEM();
  bool CheckSTB_ItemRateTYPE();
  bool CheckSTB_Motion();
  bool CheckSTB_GemITEM();
  bool CheckSTB_ListPRODUCT();
  bool Load_BasicDATA();
  void Free_BasicDATA();
  bool ConnectToLSV();
  void DisconnectFromLSV();
  bool ConnectToASV();
  void DisconnectFromASV();
  bool ConnectToLOG();
  void DisconnectFromLOG();
  void TranslateNameWithDescKey(STBDATA* pOri, char* szStbFile, int iLangCol);
  void TranslateNameWithColoumKey(STBDATA* pOri, char* szStbFile, int iLangCol, int iNameCol, int iDescCol);
  bool ConnectSERVER(char* szDBServerIP, char* szDBName, char* szDBUser, char* szDBPassword, char* szLogUser, char* szLogPW, char* szMallUser, char* szMallPW, char* szLoginServerIP, int iLoginServerPort, char* szAccountServerIP, int iAccountServerPortNO);
  bool Start(HWND__* hMainWND, char* szServerName, char* szClientListenIP, int iClientListenPort, unsigned char btChannelNO, unsigned char btLowAge, unsigned char btHighAge);
  void Shutdown();
  short InitLocalZone(bool bAllActive);
  bool CheckZoneToLocal(short nZoneNO, bool bChecked);
  char* GetZoneName(short nZoneNO);
  bool IsLocalCheckedZONE(short nZoneNO);
  char* GetServerName();
  char* GetServerIP();
  int GetListenPort();
  unsigned long GetRandomSeed();
  unsigned char GetChannelNO();
  unsigned char GetLowAGE();
  unsigned char GetHighAGE();
  bool IsTestServer();
  int GetLangTYPE();
  void Send_ANNOUNCE(short nZoneNO, char* szMsg);
  void Set_UserLIMIT(unsigned long dwUserLimit);
  unsigned long Get_UserLIMIT();
  static EXE_GS_API* ExeAPI();
  static CLIB_GameSRV* GetInstance();
  static CLIB_GameSRV* InitInstance(HINSTANCE__* hInstance, char* szBaseDataDIR, EXE_GS_API* pExeAPI, int iLangType);
  void Destroy();
};

#endif