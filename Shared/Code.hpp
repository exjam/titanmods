#ifndef CODE_H
#define CODE_H

#include <windows.h>

class Code {
public:
	static void NOP(unsigned char* code, int nops){
		DWORD oldProtect;
		VirtualProtect(code, nops, PAGE_EXECUTE_READWRITE, &oldProtect);
		memset(code, 0x90, nops);
		VirtualProtect(code, nops, oldProtect, &oldProtect);
	}

	template <class T> static void JmpHook(int location, T cfunc, int nops = 0){
		DWORD oldProtect;
		unsigned char* code = (unsigned char*)location;
		VirtualProtect(code, 5 + nops, PAGE_EXECUTE_READWRITE, &oldProtect);
		code[0] = 0xE9;
		*reinterpret_cast<int*>(code+1) = (int)cfunc - ((int)code + 5);
		if(nops > 0) memset(code + 5, 0x90, nops);
		VirtualProtect(code, 5 + nops, oldProtect, &oldProtect);
	}

	static void Write(int location, unsigned char* data, int length){
		DWORD oldProtect;
		unsigned char* code = (unsigned char*)location;
		VirtualProtect(code, length, PAGE_EXECUTE_READWRITE, &oldProtect);
		for(int i = 0; i < length; ++i)
			code[i] = data[i];
		VirtualProtect(code, length, oldProtect, &oldProtect);
	}

	template<class T> static void Write(int location, T data){
		DWORD oldProtect;
		unsigned char* code = (unsigned char*)location;
		VirtualProtect(code, sizeof(T), PAGE_EXECUTE_READWRITE, &oldProtect);
		*((T*)code) = data;
		VirtualProtect(code, sizeof(T), oldProtect, &oldProtect);
	}
};

#endif
