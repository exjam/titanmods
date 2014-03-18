#ifndef ICONSKILL_H
#define ICONSKILL_H

class CIconSkill {
public:
	short GetIndex(){
		return *(short*)(((char*)this) + 0x90);
	}
};

#endif
