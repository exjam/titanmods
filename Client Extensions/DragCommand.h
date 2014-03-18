#ifndef DRAGCMD_H
#define DRAGCMD_H

#include "Controls.h"

class CTCmdMoveIconInQuickBar : public CTCommand {
public:
	CTCmdMoveIconInQuickBar(void){};
	virtual ~CTCmdMoveIconInQuickBar(void){};
	virtual bool Exec(CTObject* object);
};

class CTCmdDragInven2SkillBar2 : public CTCommand {
public:
	CTCmdDragInven2SkillBar2(void){};
	virtual ~CTCmdDragInven2SkillBar2(void){};
	virtual bool Exec(CTObject* object);
};

class CTCmdDragItemFromQuickBar : public CTCommand {
public:
	CTCmdDragItemFromQuickBar(void){};
	virtual ~CTCmdDragItemFromQuickBar(void){};
	virtual bool Exec(CTObject* object);
};

class CTCmdDragSkill2SkillBar2 : public CTCommand {
public:
	CTCmdDragSkill2SkillBar2(void){};
	virtual ~CTCmdDragSkill2SkillBar2(void){};
	virtual bool Exec(CTObject* object);
};

class CTCmdMoveIconToQuickBar1 : public CTCommand {
public:
	CTCmdMoveIconToQuickBar1(void){};
	virtual ~CTCmdMoveIconToQuickBar1(void){};
	virtual bool Exec(CTObject* object);
};

#endif