#ifndef CGameOBJ_H
#define CGameOBJ_H

//#include <d3d9types.h>
#include <d3dx9math.h>

#include "VirtualTable.h"
#include <Shared\Templates.hpp>
#include <Shared\DataTYPE.hpp>

class CGameOBJ;

typedef unsigned int HNODE;

#define ZCALL __cdecl
#define TCALL __stdcall
#define CCALL __thiscall
#define HOOKF __stdcall

#define AIObjCast(obj, dlgClass) ((dlgClass*)(((unsigned char*)obj) + 0x20))

#define UCast54C(entity) ((CGameOBJ*)(((unsigned char*)entity) + 0x54c))

#pragma pack (push, 1)

struct tagBaseITEM {
	union {

		struct {
				struct {
					unsigned short m_cType : 5;		
					unsigned short m_nItemNo : 10;  // 5 + 10 + 1 = 16 bits = 2 bytes
					unsigned short m_bCreated : 1;

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
				unsigned short m_wHeader : 16;	
				unsigned int m_dwBody : 32;		
		};

		unsigned long m_dwITEM;
	};
};

#pragma pack (pop)

struct CGameOBJ_VTable1 {
	unsigned char unk1[0x14];
	VTABLEFUNC InsertToScene;
	VTABLEFUNC RemoveFromScene;
	VTABLEFUNC GetType;
	VTABLEFUNC GetName;
	unsigned char unk2[0x38 - 0x24];
	VTABLEFUNC GetCha;
	unsigned char unk3[0x4];
	VTABLEFUNC GetSen;
	unsigned char unk4[0xC8 - 0x44];
	VTABLEFUNC GetCon;
	unsigned char unk7[0x108 - 0xCC];
	VTABLEFUNC GetMaxHP;
	unsigned char unk5[0x1F4 - 0x10C];
	VTABLEFUNC GetInt;
	unsigned char unk6[0x210 - 0x1F8];
	VTABLEFUNC GetScreenPosition;
	unsigned char unk8[0x21C - 0x214];
	VTABLEFUNC Update;
};

//004646C0   0FBF81 44010000  MOVSX EAX,WORD PTR DS:[ECX+144]



struct CAI_OBJ_VTable {
	unsigned char unk1[0x1C];
	// Not sure about these
	/*VTABLEFUNC GetCurXPOS;
	VTABLEFUNC GetCurYPOS;
	VTABLEFUNC GetCurZPOS;
	VTABLEFUNC GetBornXPOS;
	VTABLEFUNC GetBornYPOS;
	VTABLEFUNC GetTAG;
	VTABLEFUNC GetPercentHP;*/
	// ---
	VTABLEFUNC GetHP;		// 1C
	VTABLEFUNC GetCharNO;	// 20
	VTABLEFUNC GetLevel;	// 24
	VTABLEFUNC GetAttack;	// 28
	VTABLEFUNC GetDefence;	// 2C
	VTABLEFUNC GetMagicDefence; // 30
	VTABLEFUNC GetHitRate;		// 34
	VTABLEFUNC GetCharm;		// 38
	VTABLEFUNC GetDodge;		// 3C
	VTABLEFUNC GetSen;			// 40
	VTABLEFUNC GetGiveEXP;		// 44
	VTABLEFUNC GetCrit;			// 48
	unsigned char unk2[0x9C - 0x4C];
	VTABLEFUNC GetTeam;
};

struct CObjTARGET_VTable {
	VTABLEFUNC Set_TargetIDX;
};

struct CObjAI_VTable {

};

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

/*
 ~CObjAI

004DDE80   $ C701 E8956300  MOV DWORD PTR DS:[ECX],TRose.006395E8		// CGameOBJ
004DDE86   . C741 20 389563>MOV DWORD PTR DS:[ECX+20],TRose.00639538	// AI_OBJ
004DDE8D   . C741 2C 349563>MOV DWORD PTR DS:[ECX+2C],TRose.00639534	// CObjTarget
004DDE94   .^E9 F74AF8FF    JMP TRose.00462990


*/

class CGameOBJ {
public:
	CGameOBJ_VTable1* vtable;					// 0x0 CGameOBJ
	bool					m_bIsVisible;		// 0x4
	NewData*				m_Special;			// 0x8
	Vec3					m_PosCUR;			// 0xC
	unsigned short			m_nIndex;			// 0x18
	char*					m_pListNODE;		// 0x1C

	union {
		struct {
			CAI_OBJ_VTable* vtable2;					// 0x20	CAI_OBJ
			unsigned long			m_ulAICheckTIME[ 2 ];		// 0x24
			
			CObjTARGET_VTable* vtable3;					// 0x2C	CObjTARGET
			int	m_iServerTarget;						// 0x30
		};
		struct {
			HNODE					m_hMorpher;
			short					m_nMorphIDX;
		};
	};


	bool GetHasFlag() {
		if (!m_Special) return false;
		bool Flag = m_Special->mCtfFlag ? true : false;
		return Flag;
	}

	int GetGameTeam() {
		if (!m_Special) return 0;
		int Team = m_Special->mGameTeam;
		return Team;
	}

	int GetRank() {
		if (!m_Special) return 0;
		int Rank = m_Special->mPvPRank;
		return Rank;
	}

	int GetDuelEnemy() {
		if (!m_Special) return 0;
		int IDX = m_Special->mDuelEnemy;
		return IDX;
	}

	const char* GetName(){
		return CallVTABLE<CGameOBJ, char*>(vtable->GetName, this);
	}

	int GetMaxHP(){
		return CallVTABLE<CGameOBJ, int>(vtable->GetMaxHP, this);
	}

	int GetTYPE(){
		return CallVTABLE<CGameOBJ, int>(vtable->GetType, this);
	}

	void InsertToScene(){
		return CallVTABLE<CGameOBJ, void>(vtable->InsertToScene, this);
	}

	void RemoveFromScene(bool bRemoveEFFECT=true){
		return CallVTABLE<CGameOBJ, void, bool>(vtable->RemoveFromScene, this, bRemoveEFFECT);
	}

	bool Update(bool Bones){
		return CallVTABLE<CGameOBJ, bool, bool>(this->vtable->Update, this, Bones);
	}

	int GetCharNO(){
		return CallVTABLE<CGameOBJ, int>(vtable2->GetCharNO, AIObjCast(this, CGameOBJ));
	}	
	
	int GetTeam(){
		return CallVTABLE<CGameOBJ, int>(vtable2->GetTeam, AIObjCast(this, CGameOBJ));
	}

	short GetLevel(){
		return CallVTABLE<CGameOBJ, short>(this->vtable2->GetLevel, AIObjCast(this, CGameOBJ));
	}

	bool IsPersonalStoreMode(){
		return CallMemberFunction<CGameOBJ, bool>(0x00467DA0, this);
	}

	int GetHP(){
		return CallVTABLE<CGameOBJ, int>(this->vtable2->GetHP, AIObjCast(this, CGameOBJ));
	}

	inline tagPartITEM* GetCartParts(){
		return reinterpret_cast<tagPartITEM*>(reinterpret_cast<unsigned char*>(this)+0x52C);
	}

	unsigned int GetStatusFlags(){
		return *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this)+0x1D4);
	}

	void SetPartItem(int xPart, int xID) {
		return CallMemberFunction<CGameOBJ, void, int, int>(0x00469020, this, xPart, xID);
	}

	int GetStat(int statid){	// CUserDATA::Get_AbilityValue
		return CallMemberFunction<CGameOBJ, int, int>(0x004E20D0, (UCast54C(this)), statid);
	}

	void SetPartTagItem(int PartID, tagPartITEM pItem) {
		__asm {
			MOV EDX, pItem
			MOV EAX, PartID
			MOV DWORD PTR DS:[ECX+EAX*4+0x494],EDX
		};
	}
};

#endif

