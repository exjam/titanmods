#ifndef TEMPLATES_H
#define TEMPLATES_H

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

template <class RT> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <class RT, class A1> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <class RT, class A1, class A2> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <class RT, class A1, class A2, class A3> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <class RT, class A1, class A2, class A3, class A4> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <class RT, class A1, class A2, class A3, class A4, class A5> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <class RT, class A1, class A2, class A3, class A4, class A5, class A6> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <class RT, class A1, class A2, class A3, class A4, class A5, class A6, class A7> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <class RT, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <class RT, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <class RT, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9, A10 arg10){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <class RT, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9, A10 arg10, A11 arg11){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <class RT, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9, A10 arg10, A11 arg11, A12 arg12){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}

#endif