#ifndef TGAMESERVER_H
#define TGAMESERVER_H

class C1BITARRAY;
class CAI_OBJ;
class CZoneLIST;
class CZoneSECTOR;
class CZoneTHREAD;
class CCharDATA;
class CClientSOCKET;
class CClanUSER;
class CClan;
class CGameOBJ;
class CGuild;
class classUSER;
class classEVENT;
class classPACKET;
class CLIB_GameSRV;
class CObjCHAR;
class CObjAI;
class CObjAVT;
class CObjVAR;
class CObjNPC;
class CObjMOB;
class CObjMNG;
class CObjSUMMON;
class CObjTARGET;
class CObjEVENT;
class CObjITEM;
class CParty;
class CPartyBUFF;
class CRegenPOINT;
class CThreadGUILD;
class CUserLIST;
class GS_CThreadLOG;
class GS_CThreadSQL;
class iocpSOCKET;
class CQuestTRIGGER;
class CUserDATA;
class CQuestDATA;
class STBDATA;

#pragma warning(disable : 4251)

template <class T, class RT> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class A1> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class A1, class A2> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class A1, class A2, class A3> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class A1, class A2, class A3, class A4> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class A1, class A2, class A3, class A4, class A5> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class A1, class A2, class A3, class A4, class A5, class A6> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class A1, class A2, class A3, class A4, class A5, class A6, class A7> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9, A10 arg10){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9, A10 arg10, A11 arg11){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9, A10 arg10, A11 arg11, A12 arg12){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9, A10 arg10, A11 arg11, A12 arg12, A13 arg13){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <unsigned int tfunc, class RT> _declspec(naked) RT CallStaticFunction(){
	static unsigned int func = tfunc;
	_asm {
		JMP func
	}
}


template <int tfunc, class RT, class A1> _declspec(naked) RT CallStaticFunction(A1 arg1){
	static unsigned int func = tfunc;
	_asm {
		JMP func
	}
}

template <int tfunc, class RT, class A1, class A2> _declspec(naked) RT CallStaticFunction(A1 arg1, A2 arg2){
	static unsigned int func = tfunc;
	_asm {
		JMP func
	}
}

template <int tfunc, class RT, class A1, class A2, class A3> _declspec(naked) RT CallStaticFunction(A1 arg1, A2 arg2, A3 arg3){
	static unsigned int func = tfunc;
	_asm {
		JMP func
	}
}

template <int tfunc, class RT, class A1, class A2, class A3, class A4> _declspec(naked) RT CallStaticFunction(A1 arg1, A2 arg2, A3 arg3, A4 arg4){
	static unsigned int func = tfunc;
	_asm {
		JMP func
	}
}

template <int tfunc, class RT, class A1, class A2, class A3, class A4, class A5> _declspec(naked) RT CallStaticFunction(A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5){
	static unsigned int func = tfunc;
	_asm {
		JMP func
	}
}

#include <windows.h>
#include <list>
#include <string>

#ifdef TGAMESERVER_EXPORTS

# define TGAMESERVER_API __declspec(dllexport)

#else
# define TGAMESERVER_API 

#endif

#include <Inaddr.h>
//#include <Winsock2.h>

#include "..\Shared\DataTYPE.hpp"
#include "tagStructs.h"
#include "globals.h"

#endif


/*
Hmm...

	static CUserList* Instance(){
		return *reinterpret_cast<CUserList**>(0x100CBA1C);
	}

	PublicSymbol: [000CB8B4][0003:000028B4] ?g_pPartyBUFF@@3PAVCPartyBUFF@@A(class CPartyBUFF * g_pPartyBUFF);

Data: [100CBA54][0003:00002A54] CZoneLIST::m_pCZoneLIST
Data: [100CB418][0003:00002418] CLOG::m_StrBUFF
Data: [100CB834][0003:00002834] CPoolRECVIO::m_pCPoolRECVIO
Data: [100CB838][0003:00002838] CPoolSENDIO::m_pCPoolSENDIO
Data: [100CB830][0003:00002830] CPoolPACKET::m_pCPoolPACKET
Data: [100CBA50][0003:00002A50] CCharDatLIST::m_pCCharDatLIST

Data: [100CBA24][0003:00002A24] g_pObjMGR		X
Data: [100CC00C][0003:0000300C] g_SkillList
Data: [100CBA28][0003:00002A28] g_pSockLSV
Data: [100CB8C0][0003:000028C0] g_pZoneLIST	
Data: [100CC040][0003:00003040] g_QuestList
Data: [100CBA1C][0003:00002A1C] g_pUserLIST		X
Data: [100CBCC8][0003:00002CC8] g_ChatGMLOG

Data: [100CBA30][0003:00002A30] g_pThreadSQL
Data: [100CBA34][0003:00002A34] g_pThreadLOG
Data: [100CBA40][0003:00002A40] g_pThreadMALL

Data: [100CBF54][0003:00002F54] g_TblGEMITEM
Data: [100CBC34][0003:00002C34] g_TblNATUAL
Data: [100CBB5C][0003:00002B5C] g_TblGAUNTLET
Data: [100CBDEC][0003:00002DEC] g_TblWEAPON
Data: [100CBE7C][0003:00002E7C] g_TblDropITEM
Data: [100CB8C8][0003:000028C8] g_pTblSTBs
Data: [100CBD5C][0003:00002D5C] g_TblBOOTS
Data: [100CBB80][0003:00002B80] g_TblAniTYPE
Data: [100CBD38][0003:00002D38] g_TblNPC
Data: [100CBAEC][0003:00002AEC] g_TblBreak
Data: [100CBFE8][0003:00002FE8] g_PatITEM
Data: [100CBF78][0003:00002F78] g_MotionFILE
Data: [100CABF8][0003:00001BF8] g_FuncCOND
Data: [100CBA5C][0003:00002A5C] g_TblUPGRADE
Data: [100CA6E8][0003:000016E8] g_fpQstCOND
Data: [100CBDA4][0003:00002DA4] g_TblARMOR
Data: [100CBF30][0003:00002F30] g_TblSkillPoint
Data: [100CBE58][0003:00002E58] g_TblUnion
Data: [100CBA80][0003:00002A80] g_TblSUBWPN
Data: [100CBE10][0003:00002E10] g_TblUSEITEM
Data: [100CBE34][0003:00002E34] g_TblFACEITEM
Data: [100CBEC4][0003:00002EC4] g_TblQUESTITEM
Data: [100CBBC8][0003:00002BC8] g_TblHELMET
Data: [100CBC7C][0003:00002C7C] g_TblJEWELITEM
Data: [100CBBEC][0003:00002BEC] g_TblAVATAR
*/
