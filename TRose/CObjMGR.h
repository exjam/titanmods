#ifndef CObjMGR_H
#define CObjMGR_H

#include "CGameOBJ.h"

#include "Shared/Templates.hpp"

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

class CGameOBJ;
class CObjCHAR;

class CObjMGR {
public:
	char*	m_pFindNODE;	// classDLLNODE< int >*
	int		m_iEmptySlotNo;	
	short	m_nServer2ClientOBJ[ 0x0FFFF ];
	unsigned short	m_wClient2ServerOBJ[ 4096 ];
	int		m_iObjectCNT[ OBJ_MAX_TYPE ];
	int		m_iTotalObjCNT;

	CObjCHAR* Get_CharOBJ(int nClientObjectIndex, bool CheckHP) { 
		return CallMemberFunction<CObjMGR, CObjCHAR*, int, bool>(0x004778E0, this, nClientObjectIndex, CheckHP); 
	}
	CGameOBJ* Get_OBJECT(int iObjectIndex, t_ObjTAG ObjTYPE=OBJ_NULL) { 
		return CallMemberFunction<CObjMGR, CGameOBJ*, int, t_ObjTAG>(0x00477890, this, iObjectIndex, ObjTYPE); 
	}
	int Add_GndTREE( short nObjID, D3DVECTOR *Position, D3DXQUATERNION *Rotate, D3DVECTOR *Scale ){
		return CallMemberFunction<CObjMGR, int, short, D3DVECTOR*, D3DXQUATERNION*, D3DVECTOR*>(0x004794C0, this, nObjID, Position, Rotate, Scale); 
	}
	int Add_GndCNST( short nObjID, D3DVECTOR *Position, D3DXQUATERNION *Rotate, D3DVECTOR *Scale ){
		return CallMemberFunction<CObjMGR, int, short, D3DVECTOR*, D3DXQUATERNION*, D3DVECTOR*>(0x004795F0, this, nObjID, Position, Rotate, Scale); 
	}
	int Add_FixedEvent( int iEventID, short nObjID, 
								   const char* pTriggerName,
								   const char* pScriptName,
								   D3DVECTOR *Position, D3DXQUATERNION *Rotate, D3DVECTOR *Scale ) {
		return CallMemberFunction<CObjMGR, int, int, short, const char*, const char*, D3DVECTOR*, D3DXQUATERNION*, D3DVECTOR*>(0x00479D60, this, iEventID, nObjID, pTriggerName, pScriptName, Position, Rotate, Scale); 
	}

	int	Get_ClientObjectIndex (int wServerObjectIndex)	{	return m_nServer2ClientOBJ[ wServerObjectIndex & 0xFFFF ];	}
	int	Get_ServerObjectIndex (int nClientObjectIndex)	{	return m_wClient2ServerOBJ[ nClientObjectIndex & 0xFFFF ];	}

	
	CObjCHAR* Get_ClientCharOBJ (int wServerObjectIndex, bool bCheckHP)
	{
		return this->Get_CharOBJ( (this->Get_ClientObjectIndex(wServerObjectIndex)), bCheckHP );
	}

	CGameOBJ* Get_ClientOBJECT  (int wServerObjectIndex, t_ObjTAG ObjTYPE=OBJ_NULL)
	{
		return this->Get_OBJECT( this->Get_ClientObjectIndex(wServerObjectIndex), ObjTYPE);
	}

	CGameOBJ* GetEventOBJ  (int wIndex) {
		return CallMemberFunction<CObjMGR, CGameOBJ*, int>(0x004789B0, this, wIndex);
	}

	void Del_ObjectByIDX  (short wIndex) {
		return CallMemberFunction<CObjMGR, void, short>(0x0047A4F0, this, wIndex);
	}

	void Del_Object  (CGameOBJ* pObject) {
		return CallMemberFunction<CObjMGR, void, CGameOBJ*>(0x0047A120, this, pObject);
	}

	static inline CGameOBJ* GetSelf(){
		return *((CGameOBJ**)0x6936A8);
	}

	static CObjMGR* Instance(){
		return *reinterpret_cast<CObjMGR**>(0x00695B44);
	}

};

#endif

/*
	short	Get_ClientObjectIndex (WORD  wServerObjectIndex)	{	return m_nServer2ClientOBJ[ wServerObjectIndex ];	}
	WORD	Get_ServerObjectIndex (short nClientObjectIndex)	{	return m_wClient2ServerOBJ[ nClientObjectIndex ];	}

	this->Get_CharOBJ( this->Get_ClientObjectIndex(wServerObjectIndex), bCheckHP );
	}
*/