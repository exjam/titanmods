#include "main.h"

void __declspec(naked) ASMPointShop(){
	static int rPointShop = 0x10087778;
	static int rOtherShop = 0x1008775A;

	_asm {
		MOVZX ESI,BYTE PTR SS:[EBP-0x9]	// NPC Union
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		CMP ESI, 0x07
		JE lblPointShop
		JMP rOtherShop
lblPointShop:
		JMP rPointShop
	};
}

HookOnLoad(0x10087753, ASMPointShop, 2);

void _stdcall SetItemSTAT(tagITEM& item, int unionid){
	static int statExcludeUnion[] = { 1, 2, 9, 10, 18, 19, 26, 47, 57, 58, 75, 86, 87, 112, 113, 136, 140, 150, 151, 153, 160, 161, 162, 163, 165, 168, 172, 174, 184, 185, 186, 187, 188, 189, 191, 192, 193, 201, 203, 209, 210, 211, 212, 213, 216, 218, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 231, 232, 235, 237, 238, 239, 241, 242, 243, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 260, 262, 263, 264, 265, 267, 268, 269, 270, 271, 272, 274, 276, 277, 278, 279, 281, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300 };
	static int statExcludePvp[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 42, 45, 46, 57, 58, 65, 71, 86, 87, 88, 90, 112, 113, 137, 139, 144, 150, 151, 171, 173, 184, 185, 202, 212, 213, 217, 219, 236, 245, 246, 259, 261, 272, 275, 277, 279, 280, 282, 286, 288, 292, 294, 295, 297, 298, 299, 300 };
	if(!unionid) return;

	unsigned int exclude;
	int* lstExclude;
	if(unionid == 7){
		exclude = sizeof(statExcludeUnion) / sizeof(statExcludeUnion[0]);
		lstExclude = statExcludeUnion;
	}else{
		exclude = sizeof(statExcludePvp) / sizeof(statExcludePvp[0]);
		lstExclude = statExcludePvp;
	}

	if(item.GetTYPE() >= 1 && item.GetTYPE() <= 6){
		bool ok = false;
		while(!ok){
			item.m_nGEM_OP = (rand() % 300) + 1;

			ok = true;
			for(unsigned int i = 0; i < exclude; ++i){
				if(lstExclude[i] != item.m_nGEM_OP) continue;
				ok = false;
				break;
			}
		}

		item.m_bIsAppraisal = 0;
	}else if(item.GetTYPE() >= 8 && item.GetTYPE() <= 9){
		item.m_bHasSocket = 1;
		item.m_bIsAppraisal = 1;
	} 

	int duraRange = 0;
	if(item.GetTYPE() >= 1 && item.GetTYPE() <= 6)
		duraRange = 15;
	else if(item.GetTYPE() >= 8 && item.GetTYPE() <= 9)
		duraRange = 20;

	if(duraRange){
		int dura = item.m_cDurability;
		int randDura = (rand() % ((duraRange * 2) + 1)) - duraRange;

		dura += (short)((float(dura) / 100.0f) * float(randDura));
		if(dura < 0) dura = 0;

		item.m_cDurability = dura;
	}
}

void __declspec(naked) ASMStatsOnShop(){
	static int jUNION = 0x10087DEF;
	static int jNotUNION = 0x10087E47;
	static int SetSerial = 0x1000AD00;

	_asm {
		MOVZX EAX,BYTE PTR SS:[EBP-0x9]
		PUSH EAX
		LEA EDX,DWORD PTR SS:[EBP-0x54]
		PUSH EDX
		CALL SetItemSTAT

		LEA EDX,DWORD PTR SS:[EBP-0x54]
		PUSH EDX
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		CALL SetSerial

		MOVZX EAX,BYTE PTR SS:[EBP-0x9]
		TEST EAX, EAX
		JE lblNotUNION

		JMP jUNION
lblNotUNION:
		JMP jNotUNION
	};
}

HookOnLoad(0x10087DDB, ASMStatsOnShop, 2);
