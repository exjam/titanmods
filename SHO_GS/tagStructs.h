#ifndef tag_STRUCTS
#define tag_STRUCTS

class TGAMESERVER_API CStrVAR   { 
  public: CStrVAR();
  public: char * m_pStaticStr;
  public: unsigned short m_wStaticStrLen;
  public: char * m_pStr;
  public: unsigned short m_wStrLen;
  public : CStrVAR(unsigned short Var0 , unsigned short Var1 );
  public : ~CStrVAR();
  public : char * Alloc(unsigned short Var0 , unsigned short Var1 );
  public : void Set(char * Var0 );
  public : char * Get();
  public : void Del();
  public : unsigned short BuffLength();
  public : unsigned int GetHASH(char * Var0 );
  public : unsigned int GetHASH();
  public : char * Printf(char * Var0 );
  public : char * GetTokenFirst(char * Var0 , char * Var1 );
  public : char * GetTokenNext(char * Var0 );
  public : char * ReadString(_iobuf * Var0 , bool Var1 );
  public : bool SaveString(char * Var0 , char * Var1 );
 };

enum t_ObjTAG {
	OBJ_NULL = 0,
	OBJ_MORPH,
	OBJ_ITEM,
	OBJ_COLLISION,
	OBJ_GROUND,
	OBJ_CNST,
	OBJ_NPC,		// OBJ_NPC >= character object ...
	OBJ_MOB,
	OBJ_AVATAR,
	OBJ_USER,
	OBJ_CART,
	OBJ_CGEAR,
	OBJ_EVENTOBJECT,
	OBJ_MAX_TYPE
} ;

enum t_EquipINDEX {
	EQUIP_IDX_NULL = 0,
	EQUIP_IDX_FACE_ITEM,
	EQUIP_IDX_HELMET,
	EQUIP_IDX_ARMOR,
	EQUIP_IDX_KNAPSACK,
	EQUIP_IDX_GAUNTLET,
	EQUIP_IDX_BOOTS,	
	EQUIP_IDX_WEAPON_R=7,
	EQUIP_IDX_WEAPON_L,	
	EQUIP_IDX_NECKLACE,
	EQUIP_IDX_RING,
	EQUIP_IDX_EARRING,	// 2003. 10. 27 : 장착가능 반지가 2개...
	MAX_EQUIP_IDX		// 11
} ;

enum ePacketRECV   { 

};

struct uniDAMAGE   { 
	union {
		struct {
			unsigned short m_wVALUE : 11;
			unsigned short m_wACTION : 5;
		};
		unsigned short m_wDamage;
	};
};

struct tagBlockDATA   { 
  CStrVAR m_Tag;
  unsigned short m_wAttackTYPE;
  unsigned long m_dwAttackCOUNT;
  unsigned long m_dwBlockSECOND;
  unsigned long m_dwFirstTryTIME;
  unsigned long m_dwLastTryTIME;
  tagBlockDATA();
  virtual ~tagBlockDATA();
};

class CVec2   { 
	public: float x;
	public: float y;
	public : float Length();
	public : void Normalize();
	public : bool operator==(const CVec2 & Var0 );
	public : CVec2 & operator*=(const float & Var0 );
	public : CVec2 & operator-=(const CVec2 & Var0 );
	public : CVec2 & operator+=(const CVec2 & Var0 );
public : CVec2() {}
};

struct tagAtkIP   { 
	public: __int64 m_biTIME;
	public: unsigned int m_uiIP;
};

#pragma pack(push, 2)

struct tag_CLAN_ID   { 
	public: unsigned long m_dwClanID;
	union {
		unsigned long m_dwClanMARK;
		unsigned short m_wClanMARK[0x2];
	};
	public: unsigned char m_btClanLEVEL;
	public: unsigned char m_btClanPOS;
};


struct tagClanSKILL   { 
	public: short m_nSkillIDX;
	public: unsigned long m_dwExpiredAbsSEC;
};

struct tagClanBIN   { 
	union {
		unsigned char m_pDATA[0x1]; // 0 m_pDATA[0x0]
		tagClanSKILL m_SKILL[0x14];
	};
};

struct tag_MY_CLAN  : public tag_CLAN_ID   { 
	public: int m_iClanSCORE;
	public: int m_iClanRATE;
	public: __int64 m_biClanMONEY;
	public: short m_nMemberCNT;
	public: int m_iClanCONT;
	public: tagClanBIN m_ClanBIN;
	public: short Padding;
};
#pragma pack(pop)

class classUSER;

struct tagPartyUSER   { 
  public: unsigned long m_dwDisconnectTIME;
  public: classUSER * m_pUSER;
  public: unsigned long m_dwDBID;
  public: short m_nLevel;
  public: CStrVAR m_NameCHAR;
  public : tagPartyUSER();
  public : ~tagPartyUSER();
};

enum t_eSHOT {
	SHOT_TYPE_ARROW=0,			// 화살용
	SHOT_TYPE_BULLET,			// 총/쌍권총
	SHOT_TYPE_THROW,			// 투척기용
	MAX_SHOT_TYPE = 3
} ;

enum t_InvTYPE 
{
	INV_WEAPON = 0,
	INV_USE,
	INV_ETC,
	INV_RIDING,
	MAX_INV_TYPE
} ;


#pragma pack(push, 1)

/*
Bit Struct info:
: 1		(0 - 1)
: 2		(0 - 3)
: 3		(0 - 7)
: 4		(0 - 15)
: 5		(0 - 31)
: 6		(0 - 63)
: 7		(0 - 127)
: 8		(0 - 255)
: 9		(0 - 511)
: 10	(0 - 1023)
*/
struct tagBaseITEM {
	union {

		struct {
				struct {
					unsigned short m_cType : 5;		
					unsigned short m_nItemNo : 10;  // 5 + 10 + 1 = 16 bits = 2 bytes
					unsigned short m_bCreated : 1;
				};
				struct {
					unsigned int m_nGEM_OP : 9;		// 9 + 7 + 10 + 1 + 1 + 4 = 32 bits = 4 bytes
					unsigned int m_cDurability : 7;	
					unsigned int m_nLife : 10;		
					unsigned int m_bHasSocket : 1;	
					unsigned int m_bIsAppraisal : 1;
					unsigned int m_cGrade : 4;		
				};
		};

		struct {
				unsigned short m_cType_1 : 5;
				unsigned short m_nItemNo_1 : 10;
				unsigned int m_uiQuantity : 32;	
		};

		struct {
				unsigned short m_cType_2 : 5;	
				unsigned short m_nReserved1 : 11;
				unsigned int m_uiMoney : 32;		
		};

		struct {
				unsigned short m_wHeader : 16;	
				unsigned int m_dwBody : 32;			
		};

		struct {
				unsigned long m_dwLSB;
				unsigned short m_wMSB;
		};

		struct {
				unsigned short m_wLSB;
				unsigned long m_dwMSB;
		};

		unsigned long m_dwITEM;
		
	};

  public : void Init(int Var0 , unsigned int Var1 );
  public : void Clear();
  public : unsigned short GetTYPE();
  public : unsigned short GetItemNO();
  public : unsigned short GetHEADER();
  public : unsigned short GetGrade();
  public : unsigned short GetOption();
  public : unsigned short GetGemNO();
  public : unsigned short GetLife();
  public : unsigned short GetDurability();
  public : unsigned int GetMoney();
  public : bool IsEmpty();
  public : bool IsAppraisal();
  public : bool HasSocket();
  public : bool IsEnableDROP();
  public : bool IsEnableSELL();
  public : bool IsEnableKEEPING();
  public : static bool IsValidITEM();
  public : static bool IsValidITEM(tagBaseITEM * Var0 );
  public : static bool IsValidITEM(unsigned short Var0 , unsigned short Var1 );
  public : static bool IsEnableDupCNT();
  public : static bool IsEnableDupCNT(unsigned short Var0 );
  public : bool IsCreated();
  public : bool IsEquipITEM();
  public : bool IsEtcITEM();
  public : bool IsTwoHands();
  public : t_eSHOT GetShotTYPE();
  public : t_EquipINDEX GetEquipPOS();
  public : unsigned int GetQuantity();
};	

struct tagITEM  : public tagBaseITEM   { 
	union {
		unsigned long m_dwSN[0x2];
		__int64 m_iSN;
	};
	public : short Subtract(tagITEM & Var0 );
	public : void SubtractOnly(tagITEM & Var0 );
	public : bool SubQuantity(unsigned int Var0 );
	public : bool SubQuantity();
	public : void Init(int Var0 , unsigned int Var1 );
	public : void Clear();
	public : void operator=(tagBaseITEM & Var0 );
};

#pragma pack(pop)


struct tagBankData   { 
	public: tagITEM m_ItemLIST[0xA0];
	public: __int64 m_i64ZULY;
	public : void Init();
	public : short Get_EmptySlot(short Var0 , short Var1 );
	public : short Add_ITEM(short Var0 , tagITEM & Var1 );
	public : short Add_ITEM(tagITEM & Var0 , short Var1 , short Var2 );
	public : short Sub_ITEM(short Var0 , tagITEM & Var1 );
	public : void Set_ITEM(short Var0 , tagITEM & Var1 );
};


struct tagBasicAbility   { 
	union {
		struct {
			short m_nSTR;
			short m_nDEX;
			short m_nINT;
			short m_nCON;
			short m_nCHARM;
			short m_nSENSE;
		};
		short m_nBasicA[0x6];
	};
	public : void Init();
};

#pragma pack(push, 1)
struct tagBasicINFO   { 
	public: 
	  char m_cBirthStone;
      char m_cFaceIDX;
	  char m_cHairIDX;
	  short m_nClass;
	  char m_cUnion;
	  char m_cRank;
	  char m_cFame;
	  void Init(char Var0 , char Var1 , char Var2 );
};
#pragma pack(pop)

struct tagBattleAbility   { 
	public: short m_nMaxHP;
	public: short m_nMaxMP;
	public: short m_nATT;
	public: short m_nDEF;
	public: short m_nMAG;
	public: short m_nHIT;
	public: short m_nRES;
	public: short m_nAVOID;
	public: short m_nSPD;
	public: short m_nMaxWEIGHT;
	public: short m_nWEIGHT;
	public: int m_iDefDurabity;
	public: int m_iDefGrade;
	public: int m_iCritical;
	public: float m_fRateUseMP;
	//public: short m_nImmunity;
};

struct tagCalledMOB   { 
	public: unsigned long m_dwActionTIME;
	public: float m_fCenterX;
	public: float m_fCenterY;
	public: int m_iRange;
	public: int m_iCharNO;
	public: int m_iCount;
	public: int m_iTeamNO;
};

struct tagMaintainSTATUS   { 
	public: unsigned long m_dwExpiredSEC;
	public: short m_nValue;
	public: short m_nDummy;
};

#pragma pack(push, 1)
struct tagGrowAbility   { 
	union {
		struct {
			short m_nHP;
			short m_nMP;
			long m_lEXP;
			short m_nLevel;
			short m_nBonusPoint;
			short m_nSkillPoint;
			unsigned char m_btBodySIZE;
			unsigned char m_btHeadSIZE;
			long m_lPenalEXP;
			short m_nFameG;
			short m_nFameB;
			short m_nJoHapPOINT[0xA];
			int m_iNULL1;
			short m_nNULL2;
			unsigned char m_btNULL3;
			short m_nPKFlag;
			short m_nSTAMINA;
			tagMaintainSTATUS m_STATUS[0x28];
		};
		unsigned char m_pDATA[0x1];
	};
	public : void Init();
	public : bool UpdateSTATUS(unsigned long Var0 , int Var1 , int Var2 , short Var3 );
	public : bool IsBankFREE(unsigned long Var0 );
	public : bool IsBankAddON(unsigned long Var0 );
	public : short GetStoreSKIN(unsigned long Var0 );
};
#pragma pack(pop)

struct tagHotICON   { 
	union {
		struct {
			unsigned short m_cType : 5;
			unsigned short m_nSlotNo : 11;
		};
		unsigned short m_wHotICON;
	};
};

enum IO_MODE {

};


#include "classDLLIST.h"
class classPACKET;

struct tagIO_DATA   { 
	public: _OVERLAPPED m_Overlapped;
	public: IO_MODE m_IOmode;
	public: unsigned long m_dwIOBytes;
	public: classPACKET * m_pCPacket;
	public: classDLLNODE<tagIO_DATA> * m_pNODE;
};

struct tagMallITEM   { 
	public: unsigned __int64 m_ui64ID;
	public: tagBaseITEM m_ITEM;
};

struct tagMallDATA   { 
	public: tagMallITEM m_ITEMS[0x30];
	public: unsigned long m_HashDestCHAR;
	public: CStrVAR m_DestCHAR;
	public: CStrVAR m_DestACCOUNT;
	public : tagMallDATA();
	public : ~tagMallDATA();
};

struct tagMOTION   { 
	public: unsigned int m_hMotion;
	public: unsigned short m_wFPS;
	public: unsigned short m_wTotalFrame;
	public: short * m_pFrameEvent;
	public: short m_nActionIdx;
	public: short m_nActionPointCNT;
	public: unsigned short m_wTatalAttackFrame;
	public: short * m_pActionPoint;
	public : tagMOTION();
	public : virtual ~tagMOTION();
	public : bool LoadZMO(char * Var0 );
	public : unsigned short Get_TotalFRAME();
	public : unsigned short Get_ReaminFRAME(unsigned short Var0 );
	public : float Get_PassFRAME(unsigned long Var0 , float Var1 );
	public : unsigned long Get_NeedTIME(unsigned short Var0 , float Var1 );
	public : unsigned long Get_NeedTIME(unsigned short Var0 );
  
};

#pragma pack(push, 1)
class CQUEST {

public:
  CQUEST();
  ~CQUEST();
  unsigned short m_wID;
  unsigned long m_dwExpirationTIME;
  short m_pVAR[0xA];
  union {
	unsigned char m_btSWITCHES[0x4];
	unsigned long m_dwSWITCHES;
};
  tagBaseITEM m_ITEMs[0x6];
  void ClearAllSwitch();
  unsigned char GetBit(int iIndex);
  void SetBit(int iIndex);
  void ClearBit(int iIndex);
  unsigned char FlipBit(int iIndex);
  void Init();
  void SetID(unsigned short wID, bool bResetTimer);
  unsigned short GetID();
  void Set_VAR(int iVarNO, int iValue);
  int Get_VAR(int iVarNO);
  unsigned long Get_SWITCHs();
  void Set_SWITCHs(unsigned long Var1);
  void Set_SWITCH(int iSwitchNO, int iValue);
  int Get_SWITCH(int iSwitchNO);
  int Flip_SWITCH(int iSwitchNO);
  unsigned long GetExpirationTIME();
  unsigned long GetRemainTIME();
  tagBaseITEM* GetSameITEM(unsigned short wItemHEADER);
  tagBaseITEM* GetSlotITEM(int iSlotNo);
  bool SubITEM(tagITEM& sITEM);
  bool AddITEM(tagITEM& sITEM);
  void CheckExpiredTIME();
 };

struct tagQuestData   { 
	public: enum {	BIT_SHIFT=3, WHICH_BIT=0x07 };
	private : unsigned char GetBit(int Var0 );
	private : void SetBit(int Var0 );
	private : void ClearBit(int Var0 );
	private : unsigned char FlipBit(int Var0 );
	public: short m_nEpisodeVAR[0x5];
	public: short m_nJobVAR[0x3];
	public: short m_nPlanetVAR[0x7];
	public: short m_nUnionVAR[0xA];
	public: CQUEST m_QUEST[0xA];
	union {
		unsigned long m_dwSWITCHES[0x10];
		unsigned char m_btSWITCHES[0x40];
	};
	public : void Init();
	public : void CheckExpiredTIME();
	public : void ClearAllSwitchs();
	public : void Set_SWITCH(int Var0 , int Var1 );
	public : int Get_SWITCH(int Var0 );
	public : int Flip_SWITCH(int Var0 );
 };
#pragma pack(pop)

struct tagREGENMOB   { 
	public: short m_iMobIDX;
	public: short m_iMobCNT;
};

struct tagSavedDAMAGE   { 
	public: unsigned long m_dwInsertTIME;
	public: unsigned long m_dwUpdateTIME;
	public: int m_iObjectIDX;
	public: int m_iDamage;
};

struct tagEVENTPOS   { 
	public: short m_nZoneNO;
	public: CVec2 m_Position;
	public: CStrVAR m_Name;
	public : tagEVENTPOS();
	public : virtual ~tagEVENTPOS();
};
struct tagSkillAbility   { 
	union {
		short m_nSkillINDEX[0x78];
		short m_nPageIndex[0x4][0x1E];
	};
	public : void Init();
};

struct tagTradeITEM   { 
	public: short m_nInvIDX;
	public: tagITEM m_Item;
};

struct tagWishLIST   { 
public: 
  tagBaseITEM m_WishITEM[0x1E];
  char Padding;
  void Init();
  bool Set(unsigned char btSlotNO, tagBaseITEM& sITEM);
};

struct tagZoneTRIGGER   { 
	public: unsigned long m_TriggerHASH;
	public: short m_nTeamNO;
};

struct tagObjVAR   { 
	union {
		struct {
			public: unsigned long m_HashNextTrigger;
			public: int m_iNextCheckTIME;
			public: int m_iPassTIME;
			union {
			  short m_nEventSTATUS;
			  short m_nAI_VAR[0x14];
			};
		};
		public: unsigned char m_pVAR[0x1];
	};
};


enum eING_TYPE {
	ING_NULL=0,

	ING_PROC = 1,
	ING_INC_HP = ING_PROC,				// 처리 : hp 변화
	ING_INC_MP,							// 처리 : mp 변화
	ING_POISONED,						// 처리 : 중독

	ING_INC_MAX_HP=4,					// 유지 : 최대 hp
	ING_INC_MAX_MP,						// 유지 : 최대 mp

	ING_CHECK_START = 6,

	ING_INC_MOV_SPD=ING_CHECK_START,	// 유지 : 이속/공속
	ING_DEC_MOV_SPD,					// 유지 : 이속/공속
	ING_INC_ATK_SPD=8,
	ING_DEC_ATK_SPD,
	ING_INC_APOWER=10,					// 유지 : 공격력
	ING_DEC_APOWER,
	ING_INC_DPOWER=12,					// 유지 : 방어력
	ING_DEC_DPOWER,	
	ING_INC_RES=14,						// 유지 : 항마력
	ING_DEC_RES,
	ING_INC_HIT=16,						// 유지 : 명중
	ING_DEC_HIT,
	ING_INC_CRITICAL=18,				// 유지 : 크리티컬
	ING_DEC_CRITICAL,
	ING_INC_AVOID=20,					// 유지 : 회피력 
	ING_DEC_AVOID,
	ING_DUMB=22,						// 유지 : 벙어리 : skill stb 5번 컬럼이 7~14인 스킬 사용 못함.
	ING_SLEEP,							// 유지 : 수면 : 명령 불능 상태로.. 공격 받으면 풀림
	ING_FAINTING,						// 유지 : 기절 : 수면과 같으나 공격 받아도 안풀림
	ING_DISGUISE,						// 유지 : 위장 : 
	ING_TRANSPARENT,					// 유지 : 투명 :
	ING_SHIELD_DAMAGE=27,				// 유지 : 방패 데미지
	ING_DUMMY_DAMAGE=28,				// 유지 : 추가 데미지

	ING_CHECK_END = ING_DUMMY_DAMAGE,

	ING_DEC_LIFE_TIME=29,				// 처리 : 소환된 케릭의 생명 시간...	추가: 2004. 4. 6 

	ING_CLEAR_GOOD,						// 즉각 : 유리 상태 해지
	ING_CLEAR_BAD,						// 즉각 : 불리 상태 해지
	ING_CLEAR_ALL,						// 즉각 : 모든 상태 해지
	ING_CLEAR_INVISIBLE,				// 즉각 : 투명상태 해지(ING_DISGUISE,ING_TRANSPARENT) 

	ING_TAUNT,							// 유지 : 타운트
	ING_REVIVE,							// 유지 : 부활

	ING_MAX_STATUS
} ;

#define	FLAG_ING_HP					0x00000001
#define	FLAG_ING_MP					0x00000002
#define	FLAG_ING_POISONED			0x00000004
#define	FLAG_ING_MAX_HP				0x00000010
#define	FLAG_ING_MAX_MP				0x00000020
#define	FLAG_ING_INC_MOV_SPEED		0x00000040
#define	FLAG_ING_DEC_MOV_SPEED		0x00000080
#define	FLAG_ING_INC_ATK_SPEED		0x00000100
#define	FLAG_ING_DEC_ATK_SPEED		0x00000200
#define	FLAG_ING_INC_APOWER			0x00000400
#define	FLAG_ING_DEC_APOWER			0x00000800
#define	FLAG_ING_INC_DPOWER			0x00001000
#define	FLAG_ING_DEC_DPOWER			0x00002000
#define	FLAG_ING_INC_RES			0x00004000
#define	FLAG_ING_DEC_RES			0x00008000
#define	FLAG_ING_INC_HIT			0x00010000
#define FLAG_ING_DEC_HIT			0x00020000
#define	FLAG_ING_INC_CRITICAL		0x00040000
#define	FLAG_ING_DEC_CRITICAL		0x00080000	
#define	FLAG_ING_INC_AVOID			0x00100000
#define	FLAG_ING_DEC_AVOID			0x00200000
#define	FLAG_ING_DUMB				0x00400000	
#define	FLAG_ING_SLEEP				0x00800000
#define	FLAG_ING_FAINTING			0x01000000
#define	FLAG_ING_DISGUISE			0x02000000
#define	FLAG_ING_TRANSPARENT		0x04000000
#define	FLAG_ING_SHIELD_DAMAGE		0x08000000
#define	FLAG_ING_DUMMY_DAMAGE		0x10000000
#define	FLAG_ING_DEC_LIFE_TIME		0x20000000		/// 소환된 케릭으로 초당 HP감소..
#define	FLAG_ING_REVIVE				0x40000000		/// 부활...
#define	FLAG_ING_INVINCIBLE			0x80000000		/// 타운트 스킬 설정됨

#define	FLAG_SUB_HIDE				0x00000001		// GM Hide기능 : 이 플레그 설정인 케릭터는 보여주지 않는다.
#define	FLAG_SUB_STORE_MODE			0x00000002		/// 개인 상점 중이다... 명령 불가, 소모 아이템 사용가능
#define	FLAG_SUB_INTRO_CHAT			0x00000004		// 소개글

struct tPOINTF   { 
	public: float x;
	public: float y;
};

struct tagECONOMY {
	union {
		struct {
			DWORD	m_dwTown_COUNTER;					

			short	m_nTown_POP_BASE;			
			short	m_nTown_DEV_BASE;			
			short	m_nTown_CONSUM[ 11 ];	

			short	m_nTownDEV;				
			int		m_iTownPOP;							
			int		m_iTownITEM[ 11 ];		

			DWORD	m_dwCheckTIME;
			union {
				struct {
					BYTE	m_btSave_TOWN_RATE;
					BYTE	m_btSave_ItemRATE[ 11 ];
					short	m_nSave_WorldPROD;
					short	m_nSave_WorldRATE;
				} ;
				BYTE	m_btSave_DATA[ 16 ];
			} ;

			DWORD	m_dwUpdateTIME;
			union {
				struct {
					BYTE	m_btTOWN_RATE;		
					BYTE	m_btItemRATE[ 11 ];	
					short	m_nCur_WorldPROD;
					short	m_nCur_WorldRATE;
				} ;
				BYTE	m_btCur_DATA[ 16 ];
			} ;
		} ;

		BYTE	m_pEconomy[ 1 ];
	} ;
} ;

struct t_PACKETHEADER   { 
public:
	union {
		struct {
			short m_nSize;
			unsigned short m_wType;
			unsigned short m_wReserved;
		};
		unsigned char m_pDATA[0x1];
	};
};

struct t_PACKET   { 
	union {
		public: t_PACKETHEADER m_HEADER;
		public: unsigned char Buffer[0x1];
	};
};


struct tagCLAN_CMD   { 
public: 
  unsigned char m_btCMD;
  int m_iSocketIDX;
  t_PACKET* m_pPacket;
  CStrVAR m_CharNAME;
  tagCLAN_CMD();
  ~tagCLAN_CMD();
};

struct tagQueryDATA   { 
  public: 
	int m_iTAG;
	CStrVAR m_Name;
	int m_iDataLEN;
	union {
		unsigned char * m_pDATA;
		t_PACKETHEADER * m_pPacket;
	};
	tagQueryDATA();
	~tagQueryDATA();
};
#endif