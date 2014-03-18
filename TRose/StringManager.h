#ifndef STRINGMANAGER_H
#define STRINGMANAGER_H

class StringManager {
public:
	const char* GetString(int index){  
		return CallMemberFunction<StringManager, const char*, int>(0x0044B400, this, index);  
	}
	const char* GetClanStr(int index){
		return CallMemberFunction<StringManager, const char*, int>(0x0044B4B0, this, index); 
	}
	const char* GetPlanetName(int index){ 
		return CallMemberFunction<StringManager, const char*, int>(0x0044B560, this, index); 
	}
	const char* GetClassName(int index){ 
		return CallMemberFunction<StringManager, const char*, int>(0x0044B610, this, index); 
	}
	const char* GetSkillType(int index){ 
		return CallMemberFunction<StringManager, const char*, int>(0x0044B6C0, this, index); 
	}
	const char* GetSkillTarget(int index){ 
		return CallMemberFunction<StringManager, const char*, int>(0x0044B770, this, index); 
	}
	const char* GetItemType(int index){ 
		return CallMemberFunction<StringManager, const char*, int>(0x0044B820, this, index); 
	}
	const char* GetAbilityName(int index){
		return CallMemberFunction<StringManager, const char*, int>(0x0044B8D0, this, index); 
	}
	const char* GetNPCName(int index){ 
		return CallMemberFunction<StringManager, const char*, int>(0x0044CB50, this, index); 
	}
	const char* GetItemName(int type, int id){ 
		return CallMemberFunction<StringManager, const char*, int, int>(0x0044CAA0, this, type, id); 
	}
	const char* GetZoneName(int index){ 
		return CallMemberFunction<StringManager, const char*, int>(0x0044BD90, this, index); 
	}

	static StringManager* Instance(){
		return *reinterpret_cast<StringManager**>(0x69397C);
	}
};

#endif
