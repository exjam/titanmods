#ifndef classODBC_H
#define classODBC_H

#include "SHO_GS.h"
#include "classSQL.h"

struct tagTIMESTAMP_STRUCT;
struct tagODBCDATA;
struct tagODBCCOL;

class TGAMESERVER_API classODBC  : public classSQL   { 
public: 
  CStrVAR m_ErrMSG;
  short m_nBindParamCNT;
  void AllocParam(short nCntToAlloc);
  tagODBCDATA* m_pBindPARAM;
  short m_nAllocColCnt;
  void AllocColumn(short nCntToAlloc);
  tagODBCCOL* m_pColumn;
  void* m_hENV;
  void* m_hDBC1;
  void* m_hSTMT1;
  short m_nResultColCnt;
  long m_iResultRowCnt;
  short m_RetCode;
  classODBC(short nBindParamCNT, unsigned short wQueryBufferLEN);
  virtual ~classODBC();
  virtual bool QuerySQL(char* szFormat);
  virtual int ExecSQL(char* szFormat);
  void Clear();
  short GetColDataType(unsigned char Var1);
  bool FirstDSN(char* pszDSN, int lMax);
  bool NextDSN(char* pszDSN, int lMax);
  bool RegisterDSN(char* szDSN, char* szDBName, char* szServerIP, char* szUser);
  bool ReigsterDsnIfNone(char* szDSN, char* szDBName, char* szServerIP, char* szUser);
  virtual bool Connect(char* szDSN, char* szUserName, char* szPassword);
  virtual void Disconnect();
  virtual bool SelectDB(char* szDBName);
  virtual const char* GetERROR();
  virtual int GetRecordCNT();
  virtual int GetColumnCNT();
  virtual bool Fetch();
  virtual bool BindPARAM(short nParamIDX, unsigned char* pData, unsigned int uiDataSize);
  virtual unsigned long MakeQuery(char* szCommand);
  virtual int ExecSQLBuffer(char* szQuery, unsigned long ulLength);
  virtual int ExecSQLBuffer(char* szQuery);
  virtual int ExecSQLBuffer();
  virtual int ExecSQLPacket(char* szQuery, unsigned long ulLength);
  virtual bool QueryString(char* szQuery);
  virtual bool QueryString(char* szQuery, unsigned long ulLength);
  virtual bool QuerySQLBuffer();
  virtual unsigned char* GetDataPTR(unsigned short wColumnIDX);
  virtual char* GetStrPTR(unsigned short wColumnIDX, bool bSetSpaceToNULL);
  virtual int GetStrLen(unsigned short wColumnIDX);
  virtual int GetInteger(unsigned short wColumnIDX);
  virtual short GetInteger16(unsigned short wColumnIDX);
  virtual __int64 GetInt64(unsigned short wColumnIDX);
  virtual bool GetTimestamp(unsigned short wColumnIDX, sqlTIMESTAMP* pTimeStamp);
  virtual bool BindRESULT();
  virtual bool GetMoreRESULT();
  virtual bool SetParameter(short nParamIDX, unsigned char* pData, unsigned int uiDataSize, short nIOType, short nValueType, short nParamType);
  virtual bool SetParam_string(short nParamIDX, char* szStr);
  virtual bool SetParam_wstring(short nParamIDX, char* szStr);
  virtual bool SetParam_long(short nParamIDX, long& lOutResult, long& cbLen);
};

#endif

