#ifndef classSQL_H
#define classSQL_H

#include "SHO_GS.h"

 struct sqlTIMESTAMP   { 
  unsigned short m_wYear;
  unsigned char m_btMon;
  unsigned char m_btDay;
  unsigned char m_btHour;
  unsigned char m_btMin;
  unsigned char m_btSec;
 };

class TGAMESERVER_API classSQL   { 
public: 
  char m_szTemp[0x100];
  char* m_pQueryBuff;
  unsigned long m_dwMaxQueryBuffSize;
  unsigned long m_dwQueryBuffSize;
  classSQL(const classSQL& Var1);
  classSQL();
  virtual ~classSQL();
  bool GetNextRECORD();
  char* GetQueryBuffPTR();
  virtual bool Connect(char* Var1, char* Var2, char* Var3);
  virtual void Disconnect();
  virtual bool SelectDB(char* Var1);
  virtual const char* GetERROR();
  virtual int GetRecordCNT();
  virtual int GetColumnCNT();
  virtual bool Fetch();
  virtual bool BindPARAM(short Var1, unsigned char* Var2, unsigned int Var3);
  virtual unsigned long MakeQuery(char* szCommand, ...);
  virtual int ExecSQLBuffer(char* szQuery, unsigned long ulLength);
  virtual int ExecSQLBuffer(char* szQuery);
  virtual int ExecSQLBuffer();
  virtual int ExecSQLPacket(char* szQuery, unsigned long ulLength);
  virtual bool QuerySQL(char* szQuery,  ...);
  virtual int ExecSQL(char* szQuery,  ...);
  virtual bool QueryString(char* Var1);
  virtual bool QueryString(char* Var1, unsigned long Var2);
  virtual bool QuerySQLBuffer();
  virtual unsigned char* GetDataPTR(unsigned short Var1);
  virtual char* GetStrPTR(unsigned short Var1, bool Var2);
  virtual int GetStrLen(unsigned short Var1);
  virtual int GetInteger(unsigned short Var1);
  virtual short GetInteger16(unsigned short Var1);
  virtual __int64 GetInt64(unsigned short Var1);
  virtual bool GetTimestamp(unsigned short Var1, sqlTIMESTAMP* Var2);
  virtual bool BindRESULT();
  virtual bool GetMoreRESULT();
  virtual bool SetParameter(short nParamIDX, unsigned char* pData, unsigned int uiDataSize, short nIOType, short nValueType, short nParamType);
  virtual bool SetParam_string(short nParamIDX, char* szStr);
  virtual bool SetParam_wstring(short nParamIDX, char* szStr);
  virtual bool SetParam_long(short nParamIDX, long& lOutResult, long& cbLen);
};

#endif

