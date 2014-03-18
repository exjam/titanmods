#include "main.h"

#include <wininet.h>
#include <exception>
#include <dbghelp.h>

#include <TRose\CObjMGR.h>
#include <TRose\CGameOBJ.h>
#include <TRose\Packet.h>
#include <ExLIB\List.hpp>
#include <ExLIB\String.hpp>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "dbghelp.lib")

extern Packet* gRecvPacket;

typedef List<String> StringList;

struct LoadedModule {
	String mName;
	unsigned int mBase;
	unsigned int mSize;
};

BOOL CALLBACK AddLoadedModule(PCSTR ModuleName, ULONG ModuleBase, ULONG ModuleSize, PVOID UserContext){
	LoadedModule* cur = new LoadedModule();
	cur->mName = ModuleName;
	cur->mBase = ModuleBase;
	cur->mSize = ModuleSize;
	List<LoadedModule*>* modules = (List<LoadedModule*>*)UserContext;
	modules->push_back(cur);
	return TRUE;
}

String GetModuleName(unsigned int address, List<LoadedModule*>* modules){
	for(List<LoadedModule*>::Iterator itr = modules->begin(); itr != modules->end(); ++itr){
		LoadedModule* cur = *itr;
		if(address < cur->mBase) continue;
		if(address > cur->mBase + cur->mSize) continue;
		return cur->mName;
	}

	return String();
}

#define MAX_CALL_STACK 5

void GetCallStack(_EXCEPTION_POINTERS* pException, List<LoadedModule*>* modules, StringList& headers){
	typedef struct STACK {
		STACK* Ebp;
		PBYTE Ret_Addr;
		DWORD Param[0];
	} STACK, *PSTACK;

	STACK Stack = {0, 0};
	PSTACK Ebp;
	Stack.Ebp = (PSTACK)pException->ContextRecord->Ebp;
	Stack.Ret_Addr = (PBYTE)pException->ExceptionRecord->ExceptionAddress;
	Ebp = &Stack;

	for(unsigned int i = 0; (i < MAX_CALL_STACK && !IsBadReadPtr(Ebp, sizeof(PSTACK)) && !IsBadCodePtr(FARPROC(Ebp->Ret_Addr))); ++i, Ebp = Ebp->Ebp){
		unsigned int addr = (unsigned int)Ebp->Ret_Addr;
		headers.push_back(String("Call-Stack-%1: %2 %3").arg(i).arg(GetModuleName(addr, modules)).arg(addr, 16, true, 8));
	}
}

LONG WINAPI UnhandledExceptionHandler(_EXCEPTION_POINTERS *ExceptionInfo){
	List<LoadedModule*> LoadedModules;
	EnumerateLoadedModules(GetCurrentProcess(), (PENUMLOADED_MODULES_CALLBACK)AddLoadedModule, &LoadedModules);

	StringList HeaderList;
	
	if(ExceptionInfo->ContextRecord->ContextFlags & CONTEXT_INTEGER){
		PCONTEXT reg = ExceptionInfo->ContextRecord;
		HeaderList.push_back(String("Register-EAX: %1").arg(reg->Eax, 16, true, 8));
		HeaderList.push_back(String("Register-ECX: %1").arg(reg->Ecx, 16, true, 8));
		HeaderList.push_back(String("Register-EDX: %1").arg(reg->Edx, 16, true, 8));
		HeaderList.push_back(String("Register-EBX: %1").arg(reg->Ebx, 16, true, 8));
		HeaderList.push_back(String("Register-EDI: %1").arg(reg->Edi, 16, true, 8));
		HeaderList.push_back(String("Register-ESI: %1").arg(reg->Esi, 16, true, 8));
	}

	if(ExceptionInfo->ContextRecord->ContextFlags & CONTEXT_CONTROL){
		PCONTEXT reg = ExceptionInfo->ContextRecord;
		HeaderList.push_back(String("Register-EBP: %1").arg(reg->Edi, 16, true, 8));
		HeaderList.push_back(String("Register-ESP: %1").arg(reg->Esi, 16, true, 8));
	}

	HeaderList.push_back(String("Exception-Address: %1").arg((unsigned int)ExceptionInfo->ExceptionRecord->ExceptionAddress, 16, true, 8));
	HeaderList.push_back(String("Exception-Flags: %1").arg((unsigned int)ExceptionInfo->ExceptionRecord->ExceptionFlags, 16, true, 8));
	HeaderList.push_back(String("Exception-Code: %1").arg((unsigned int)ExceptionInfo->ExceptionRecord->ExceptionCode, 16, true, 8));
	
	CGameOBJ* self = CObjMGR::GetSelf();
	const char* name = (self)?self->GetName():"No Character";
	HeaderList.push_back(String("Character: %1").arg(name));
	String module = "Unknown";

	unsigned int codeAddress = (unsigned int)((char*)ExceptionInfo->ExceptionRecord->ExceptionAddress);
	module = GetModuleName(codeAddress, &LoadedModules);
	HeaderList.push_back(String("Module: %1").arg(module));

	unsigned char* codePtr = (unsigned char*)ExceptionInfo->ExceptionRecord->ExceptionAddress;
	//if(IsBadReadPtr(codePtr - 20, 40) || !IsBadCodePtr(FARPROC(codePtr))){
	String code = String("Code-Data: Version: %1 ").arg(gVersion);
	if(CTERRAIN::Instance()) {
		code += String("Zone: %1 ").arg(CTERRAIN::Instance()->m_nZoneNO);
	}
	if(gRecvPacket) {
		code += String("RecvPacket: %1").arg(gRecvPacket->Command(), 16);
	}
	/*}else{
		for(int i = -20; i < 20; ++i)
			code += String::Create("%02X", codePtr[i]);
	}*/

	HeaderList.push_back(code);

    OSVERSIONINFO osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&osvi);
	HeaderList.push_back(String("Windows: %1.%2").arg((unsigned int)osvi.dwMajorVersion).arg((unsigned int)osvi.dwMinorVersion));

	GetCallStack(ExceptionInfo, &LoadedModules, HeaderList);

	unsigned int bufLen = 100;
	for(StringList::Iterator itr = HeaderList.begin(); itr != HeaderList.end(); ++itr)
		bufLen += strlen(*itr) + 3;

	char* theHeaders = new char[bufLen];
	theHeaders[0] = 0;
	for(StringList::Iterator itr = HeaderList.begin(); itr != HeaderList.end(); ++itr){
		strcat_s(theHeaders, bufLen, *itr);
		strcat_s(theHeaders, bufLen, ";\r\n");
	}

	if(MessageBoxA(NULL, "Would you like to submit this error to the titanROSE team?", "An error has occured.", MB_ICONERROR | MB_YESNO) == IDYES){
		HINTERNET theInternet = InternetOpenA("titanROSE.Client", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
		HINTERNET theConnection = InternetConnectA(theInternet, "crash.titanrose.com", INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, NULL);
		HINTERNET theRequest = HttpOpenRequestA(theConnection, "GET", NULL, NULL, "trose.exe", NULL, INTERNET_FLAG_PRAGMA_NOCACHE |INTERNET_FLAG_RELOAD, NULL);
		HttpAddRequestHeadersA(theRequest, theHeaders, -1, HTTP_ADDREQ_FLAG_ADD);
		BOOL theResult = HttpSendRequestA(theRequest, NULL, 0, NULL, 0);
		if(theResult == TRUE){
			MessageBoxA(NULL, "Your error report was successfully uploaded, thank you.", "Error Report Submitted", MB_OK | MB_ICONASTERISK);
		}else{
			strcat_s(theHeaders, bufLen, "\r\nThere was an error submitting your error report, please post this message box on the forums.");
			MessageBoxA(NULL, theHeaders, "Error submitting Error Report", MB_OK);
		}
	}

	LoadedModules.delete_values();
	delete [] theHeaders;

	return EXCEPTION_EXECUTE_HANDLER;
}

void __stdcall InitCrashHandler(){
	Code::JmpHook(0x439AF0, UnhandledExceptionHandler, 0);
}

RunOnLoad(InitCrashHandler);