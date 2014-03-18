#ifndef CODEHOOK_H
#define CODEHOOK_H

#include <windows.h>

class CodeHook {
public:
	static void WriteCode(unsigned char* location, unsigned char* data, int length){
		DWORD oldProtect;
		VirtualProtect(location, length + 10, PAGE_EXECUTE_READWRITE, &oldProtect);
		for(int i = 0; i < length; ++i)
			location[i] = data[i];
		VirtualProtect(location, length + 10, oldProtect, &oldProtect);
	}

	static void NOP(unsigned char* code, int nops){
		DWORD oldProtect;
		VirtualProtect(code, nops, PAGE_EXECUTE_READWRITE, &oldProtect);
		memset(code, 0x90, nops);
		VirtualProtect(code, nops, oldProtect, &oldProtect);
	}

	static void ApplyJmpHook(unsigned char* code, unsigned char* location, int nops = 0){
		DWORD oldProtect;
		VirtualProtect(code, 5 + nops, PAGE_EXECUTE_READWRITE, &oldProtect);
		code[0] = 0xE9;
		*reinterpret_cast<int*>(code+1) = (int)location - ((int)code + 5);
		if(nops > 0) memset(code + 5, 0x90, nops);
		VirtualProtect(code, 5 + nops, oldProtect, &oldProtect);
	}

	static void ApplyJmpForwardHook(unsigned char* code, unsigned char* location, unsigned char* forwardFunc, int nops = 0){
		DWORD oldProtect;
		VirtualProtect(code, 10 + nops, PAGE_EXECUTE_READWRITE, &oldProtect);
		code[0] = 0xB8;
		*reinterpret_cast<int*>(code+1) = (int)forwardFunc;
		code[5] = 0xE9;
		*reinterpret_cast<int*>(code+6) = (int)location - ((int)code + 10);
		if(nops > 0) memset(code + 10, 0x90, nops);
		VirtualProtect(code, 10 + nops, oldProtect, &oldProtect);
	}

private:
};

#endif