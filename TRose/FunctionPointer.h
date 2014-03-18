#ifndef FPOINTERS_H
#define FPOINTERS_H

#define PTRFUNC_A0(addr, calltype, ret, name) \
	static __declspec(naked) ret calltype name(){ static char* addrz = (char*)addr; _asm JMP addrz };

#define PTRFUNC_A1(addr, calltype, ret, name, a1) \
	static __declspec(naked) ret calltype name(a1){ static char* addrz = (char*)addr; _asm JMP addrz };

#define PTRFUNC_A2(addr, calltype, ret, name, a1, a2) \
	static __declspec(naked) ret calltype name(a1, a2){ static char* addrz = (char*)addr; _asm JMP addrz };

#define PTRFUNC_A3(addr, calltype, ret, name, a1, a2, a3) \
	static __declspec(naked) ret calltype name(a1, a2, a3){ static char* addrz = (char*)addr; _asm JMP addrz };

#define PTRFUNC_A4(addr, calltype, ret, name, a1, a2, a3, a4) \
	static __declspec(naked) ret calltype name(a1, a2, a3, a4){ static char* addrz = (char*)addr; _asm JMP addrz };

#define PTRFUNC_A5(addr, calltype, ret, name, a1, a2, a3, a4, a5) \
	static __declspec(naked) ret calltype name(a1, a2, a3, a4, a5){ static char* addrz = (char*)addr; _asm JMP addrz };

#define PTRFUNC_A6(addr, calltype, ret, name, a1, a2, a3, a4, a5, a6) \
	static __declspec(naked) ret calltype name(a1, a2, a3, a4, a5, a6){ static char* addrz = (char*)addr; _asm JMP addrz };

#endif
