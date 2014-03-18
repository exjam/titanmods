#include "main.h"
#include "Controls.h"
/*
std::vector<char*> ignoreList;

bool IgnoreFindCharacter(char* name){
	for(std::vector<char*>::const_iterator itr = ignoreList.begin(); itr != ignoreList.end(); ++itr){
		if(_strcmpi(*itr, name) == 0)
			return true;
	}
	return false;
}

void DisplayIgnoreList(){
	IT_MGR::Instance()->AppendChatMsg("Ignore> List", 4);
	for(std::vector<char*>::const_iterator itr = ignoreList.begin(); itr != ignoreList.end(); ++itr)
		IT_MGR::Instance()->AppendChatMsg(*itr, 4);
}

void AddIgnore(char* name){
	if(name == NULL) return;
	if(IgnoreFindCharacter(name)) return;

	ignoreList.push_back(_strdup(name));
}

void RemoveIgnore(char* name){
	if(name == NULL) return;

	for(std::vector<char*>::const_iterator itr = ignoreList.begin(); itr != ignoreList.end(); ++itr){
		if(_strcmpi(*itr, name)) continue;

		delete [] *itr;
		ignoreList.erase(itr);
		return;
	}
}

void HandleIgnoreCommand(char* arguments){
	if(arguments == NULL){
		IT_MGR::Instance()->AppendChatMsg("Ignore> /ignore add <player>", 4);
		IT_MGR::Instance()->AppendChatMsg("Ignore> /ignore remove <player>", 4);
		IT_MGR::Instance()->AppendChatMsg("Ignore> /ignore list", 4);
		return;
	}

	char* command = arguments;
	char* value = strchr(arguments, ' ');if(value != NULL){ *value = 0; ++value; }

	if(_strcmpi(command, "list") == 0)
		DisplayIgnoreList();
	else if(_strcmpi(command, "add") == 0)
		AddIgnore(value);
	else if(_strcmpi(command, "remove") == 0)
		RemoveIgnore(value);
}
*/