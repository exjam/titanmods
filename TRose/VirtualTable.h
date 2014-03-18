#ifndef VTABLE_H
#define VTABLE_H

typedef void* VTABLEFUNC;

template <class T, class RT> _declspec(naked) RT __stdcall CallVTABLE(VTABLEFUNC func, T* self){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class P1> _declspec(naked) RT __stdcall CallVTABLE(VTABLEFUNC func, T* self, P1 param1){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class P1, class P2> _declspec(naked) RT __stdcall CallVTABLE(VTABLEFUNC func, T* self, P1 param1, P2 param2){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class P1, class P2, class P3> _declspec(naked) RT __stdcall CallVTABLE(VTABLEFUNC func, T* self, P1 param1, P2 param2, P3 param3){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class P1, class P2, class P3, class P4> _declspec(naked) RT __stdcall CallVTABLE(VTABLEFUNC func, T* self, P1 param1, P2 param2, P3 param3, P4 param4){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <class T, class RT, class P1, class P2, class P3, class P4, class P5> _declspec(naked) RT __stdcall CallVTABLE(VTABLEFUNC func, T* self, P1 param1, P2 param2, P3 param3, P4 param4, P5 param5){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

#endif
