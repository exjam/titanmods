#include "main.h"
#include <sys/stat.h>
#include <shellapi.h>

bool FileExists(char* filename){
  struct stat fileInfo;
  return stat(filename, &fileInfo) == 0;
}

void _stdcall CheckAdapter(){
	if(!FileExists("sysadpt.dat")){
		ShellExecute(NULL, NULL, "TriggerDetect.exe", NULL, NULL, NULL);
		exit(0);
	}
}

RunOnLoad(CheckAdapter);