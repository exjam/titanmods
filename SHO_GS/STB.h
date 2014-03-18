////////////////////////////////////////////////////////////////////////
///////  STB class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef STB_H
#define STB_H
#include "SHO_GS.h"
#include "classHASH.h"

class TGAMESERVER_API STBVALUE   { 
public: 
	bool m_bString;
	int m_iValue;
	CStrVAR* m_pString;
	STBVALUE();
	~STBVALUE();
	void SetTYPE(bool bString);
	bool IsString();
	void SetVALUE(int iValue);
	void SetVALUE(char* szValue);
	int GetINT();
	char* GetSTR();
	int GetStrLEN();
};

class TGAMESERVER_API STBDATA   { 
public: 
	classHASH<short> m_KeyTable;
	bool m_bLoad2;
	short m_nDataCnt;
	short m_nColCnt;
	char** m_ppNAME;
	char** m_ppDESC;
	union {
		int** m_ppDATA;
		STBVALUE** m_ppVALUE;
	};
	STBDATA(const STBDATA& Var1);
	STBDATA();
	virtual ~STBDATA();
	bool Load2(char* szFileName, bool bHasTYPE, bool bMakeKEY);
	bool Load(char* szFileName, bool bHasNameCol, bool bHasDescCol, bool bMakeKEY);
	void Free();
	bool LoadWSTB(bool bCheckQuotationMark, char* szFileName, int iKeyColIDX);
	char* GetValueSTR(short nCol, short nRow);
	short GetRowIndex(char* szName);
	short GetRowIndex(unsigned long HashKey);
};

#endif