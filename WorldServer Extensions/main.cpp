#include <windows.h>
#include "main.hpp"
#include "..\Shared\RunOnLoad.hpp"
#include "..\Shared\Console.hpp"
#include <ExLIB\Directory.hpp>
#include <iostream>

BOOL WINAPI TrapCtrlHandler( DWORD dwCtrlType )
{
	switch( dwCtrlType )
	{
	case CTRL_C_EVENT:
	case CTRL_CLOSE_EVENT:
	case CTRL_BREAK_EVENT:
		Log(MSG_WARNING,"Never use the console to shutdown!");
		break;
	default:
		return FALSE;
	}
	return TRUE;
} 

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved){
	switch(dwReason){
		case DLL_PROCESS_ATTACH:
		{
			CreateConsole();
			SetConsoleCtrlHandler( TrapCtrlHandler, TRUE );

			RunList::Instance().RunFunctions();
			HookList::Instance().ApplyHooks();
			WriteList::Instance().ApplyWrites();

			Log(MSG_INFO, "TitanWorld Injected.");
			return TRUE;
		}

		case DLL_PROCESS_DETACH:
			return TRUE;
	};

	return TRUE;
}