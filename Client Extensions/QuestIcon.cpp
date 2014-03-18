#include "main.h"
#include <TRose\DrawImpl.h>
#include <TRose\QuestFunctions.h>
#include "TRose\CodeHook.h"
#include "TriggerVFS\TriggerVFS.h"
#include "Controls.h"

byte gNPCIcon[1024];

struct Condition {
	int mFunction;
	char* mArgument;
	int mComparison;
	int mResult;
};

struct Icon {
	int mValue;
	std::vector<Condition*> mConditions;
};

struct Npc {
	int mIndex;
	std::vector<Icon*> mIcons;
};

std::vector<Npc*> mNpcList;

enum {
	ARG_INT,
	ARG_STRING,
	UNK_TYPE,
} ARG_TYPES;

enum {
	SC_QF_findQuest,
	SC_QF_checkQuestCondition,
	FUNC_UNKNOWN,
} SCRIPT_QUEST_FUNCTIONS;

int argtype[] = { ARG_INT, ARG_STRING, UNK_TYPE };

enum {
	E,
	NE,
	G,
	L,
	GE,
	LE,
	COMP_UNKNOWN,
} SCRIPT_OPERATORS;


void __stdcall DrawNPCNameHax(float x, float y, float z, int npcid){
	if((npcid < 1000) || (npcid > 2024)) return;
	if(!gNPCIcon[npcid - 1000]) return;
	if(!gOptions.mQuestIconEnable) return;
	if(int(x) < 72) x = 72;
	if(int(x) < 62) y = 62;
	DrawImpl::Instance()->Draw3D(x - 72, y - 62, z, IMAGE_RES_UI, gQuesticonGUI + gNPCIcon[npcid - 1000], COLOUR_WHITE);
}

void _declspec(naked) ASMDrawNPCNameHax(){
	static int npcnameret = 0x004884F1;
	_asm {
		MOV DWORD PTR SS:[ESP+0xB8], EDI
		MOV EDX, ESP
		PUSH EDX
		PUSH EAX
		MOV EAX, [EDX+0xF8]
		MOVSX EAX, WORD PTR DS:[EAX+0x164]
		PUSH EAX
		MOV EAX, [EDX+0xF4]
		PUSH EAX
		MOV EAX, [EDX+0xF0]
		PUSH EAX
		MOV EAX, [EDX+0xEC]
		PUSH EAX
		CALL DrawNPCNameHax
		POP EAX
		POP EDX
		MOV ECX, EAX
		JMP npcnameret
	}
}

bool CompareValues(int val1, int val2, int op){
	switch(op){
		case E:
			return val1 == val2;
		case NE:
			return val1 != val2;
		case G:
			return val1 > val2;
		case GE:
			return val1 >= val2;
		case L:
			return val1 < val2;
		case LE:
			return val1 <= val2;
	};
	return false;
}

void RunQuestIconScript(){
	for(std::vector<Npc*>::const_iterator nitr = mNpcList.begin(); nitr != mNpcList.end(); ++nitr){
		Npc* curnpc = *nitr;
		gNPCIcon[curnpc->mIndex - 1000] = 0;
		for(std::vector<Icon*>::const_iterator itr = curnpc->mIcons.begin(); itr != curnpc->mIcons.end(); ++itr){
			bool HasFail = false;
			Icon* curicon = *itr;
			for(std::vector<Condition*>::const_iterator citr = curicon->mConditions.begin(); citr != curicon->mConditions.end(); ++citr){
				Condition* curcond = *citr;
				if(curcond->mFunction == SC_QF_findQuest){
					int val = QF_findQuest((int)curcond->mArgument);
					if(!CompareValues(val, curcond->mResult, curcond->mComparison)){
						HasFail = true;
						break;
					}
				}else if(curcond->mFunction == SC_QF_checkQuestCondition){
					int val = QF_checkQuestCondition(curcond->mArgument);
					if(!CompareValues(val, curcond->mResult, curcond->mComparison)){
						HasFail = true;
						break;
					}
				}
			}
			if(!HasFail){
				gNPCIcon[curnpc->mIndex - 1000] = curicon->mValue;
				break;
			}
		}
	}
}

HookOnLoad(0x004884EA, ASMDrawNPCNameHax, 2);

void LoadQuestIconScript(char* path){
	memset(gNPCIcon, 0, 1024);

	FILEHANDLE vfsHandle = OpenVFS("data.idx", "mr");
	FILEHANDLE fh = VOpenFile(path, vfsHandle);

	if(!fh) return;
	int npcs;
	vfread(&npcs, 4, 1, fh);
	for(int i = 0; i < npcs; ++i){
		Npc* curnpc = new Npc();
		vfread(&curnpc->mIndex, 4, 1, fh);
		int icons;
		vfread(&icons, 4, 1, fh);
		for(int j = 0; j < icons; ++j){
			Icon* curicon = new Icon();
			vfread(&curicon->mValue, 4, 1, fh);
			int conditions;
			vfread(&conditions, 4, 1, fh);
			for(int k = 0; k < conditions; ++k){
				Condition* curcond = new Condition();
				vfread(&curcond->mFunction, 4, 1, fh);
				vfread(&curcond->mComparison, 4, 1, fh);
				vfread(&curcond->mResult, 4, 1, fh);
				if(argtype[curcond->mFunction] == ARG_INT){
					vfread(&curcond->mArgument, 4, 1, fh);
				}else if(argtype[curcond->mFunction] == ARG_STRING){
					int len;
					vfread(&len, 4, 1, fh);
					curcond->mArgument = new char[len+1];
					vfread(curcond->mArgument, 1, len, fh);
					curcond->mArgument[len] = 0;
				}
				curicon->mConditions.push_back(curcond);
			}
			curnpc->mIcons.push_back(curicon);
		}
		mNpcList.push_back(curnpc);
	}
	VCloseFile(fh);
}
