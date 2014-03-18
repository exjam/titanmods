#ifndef GAME_H
#define GAME_H

#include <Shared/Templates.hpp>
typedef unsigned int HNODE;

class CStrVAR {
private :
	char   *m_pStaticStr;
	WORD	m_wStaticStrLen;
	char   *m_pStr;
	WORD	m_wStrLen;
};

typedef struct Vec2 {
    float x;
    float y;
} Vec2;


enum
{
	FONT_NORMAL	= 0,
	FONT_LARGE,
	FONT_SMALL,
	FONT_NORMAL_BOLD,
	FONT_LARGE_BOLD,
	FONT_SMALL_BOLD,
	FONT_OUTLINE_18,
	FONT_OUTLINE_14,
	FONT_NORMAL_OUTLINE,
	FONT_OUTLINE_18_BOLD,
	FONT_OUTLINE_14_BOLD,
	FONT_OUTLINE_24_BOLD,
	FONT_OUTLINE_16_BOLD,
	FONT_OUTLINE_11_BOLD,
	MAX_FONT,
};

enum {
	FONT_POS_TOP = 0x0,
	FONT_POS_LEFT = 0x0,
	FONT_POS_CENTER = 0x1,
	FONT_POS_RIGHT = 0x2,
	FONT_POS_VCENTER = 0x4,
	FONT_POS_BOTTOM = 0x8,
};

enum
{
	PVP_CANT = 0,
	PVP_PERMITION_ALL = 1,
	PVP_NON_PARTY_ALL = 2,
	PVP_AGIT = 11,
};

class CGameDATA 
{
public:
	static CGameDATA* Instance(){
		return *reinterpret_cast<CGameDATA**>(0x693504);
	}

	bool				m_bWireMode;
	bool				m_bDrawBoundingVolume;
	HNODE				m_hShader_nolit_skin;
	HNODE				m_hShader_nolit;
	HNODE				m_hShader_terrain;
	HNODE				m_hShader_terrain_Rough;
	HNODE				m_hShader_lightmap;
	HNODE				m_hShader_ocean;
	HNODE				m_hShader_specular;
	HNODE				m_hShader_specular_skin;
	HNODE				m_hShader_lit_skin;
	HNODE				m_hShader_lit;
	HNODE				m_hShader_sky;
	bool				m_bNoUI;
	bool				m_bNoWeight;
	bool				m_bFilmingMode;
	bool				m_bShowCursor;
	bool				m_bShowDropItemInfo;
	int					m_iPvPState;			
	SYSTEMTIME			m_SystemTime;
	bool				m_bDisplayDebugInfo;
	float				m_fTestVal;
	bool				m_bDirectLogin;
	bool				m_bForOpenTestServer;
	int					m_iTemp;
	bool				m_bCheckDupRUN;			/// 중복실행 방지...
	HNODE				m_hLight;
	HNODE				m_hCharacterLight;
//	HNODE				m_hCharacterLight2;
	CStrVAR				m_TrailTexture;
	HNODE				m_hFONT[ 14 ];
};

#define GameDATA (CGameDATA::Instance())


class CUserInputState
{
public:
	int			m_iCurrentActiveSkillSlot; // Should be AFTER m_iCurrentTarget but m_iCurrentTarget is at 0x14 (20)

	int			m_iCommandType;
	int			m_iCommand;
	int			m_iMouseState;
	int			m_iCurrentTargetType;
	int			m_iCurrentTarget;

	static CUserInputState* Instance(){
		return **reinterpret_cast<CUserInputState***>(0x693858);
	}
};

class CGame {
public:
	static CGame* Instance(){
		return reinterpret_cast<CGame*>(0x693BF0);
	}

	void __inline GetMousePos(POINT &ptMouse){
		ptMouse.x = *(LONG*)(((char*)this)+0xA90);
		ptMouse.y = *(LONG*)(((char*)this)+0xA94);
	}

	int GetRight() { return CallMemberFunction<CGame, int>(0x0041C330, this); }
};

#endif
