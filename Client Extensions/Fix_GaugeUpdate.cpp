#include "main.h"

float gFloatValue = 0.0f;// This float value is used as a static iValue. 
						// It's casted to an int but still updates the progress according to the time which has passed.

int _stdcall GaugeUpdate(int autoIncrementValue, int value, DWORD updateSpace){
	if(value != (int)gFloatValue)
		gFloatValue = 0.0f;

	gFloatValue += ((float)autoIncrementValue * (float)updateSpace / 1000.0f);
	return (int)gFloatValue;
}

static _declspec(naked) void ASMGaugeUpdate(){
	static int retAddr = 0x004C9C68;
	_asm {	
		PUSH ECX
		PUSH EDX // dwUpdateSpace
		PUSH EDI // m_iValue
		MOV EAX, DWORD PTR DS:[ECX+0x2C] // m_iAutoIncrementValue
		PUSH EAX
		CALL GaugeUpdate
		POP ECX
		MOV ESI,DWORD PTR DS:[ECX+0x30] // m_iAutoIncrementMaxValue
		JMP retAddr
	};
}

HookOnLoad(0x004C9C57, ASMGaugeUpdate, 12);