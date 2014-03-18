#include "main.h"
#include "Network.h"
#include "Controls.h"
#include "ClanMember.h"

void _stdcall SetMyContribution(int contribution){
	_asm {
		PUSH EAX
		MOV EAX, contribution
		MOV DWORD PTR DS:[0x00696C80], EAX
		POP EAX
	}
}

void SetContribution(char* characterName, int points){
	if(CZListBox* listBox = (CZListBox*)ControlInPane(DLG_TYPE_CLAN, 20, 0, 36)){
		CGameOBJ* self = CObjMGR::GetSelf();

		for(int i = 0 ; i < listBox->GetSize(); ++i){
			if(CClanMemberItem* item = (CClanMemberItem*)listBox->GetItem(i)){
				if(!_strcmpi(item->GetName(), characterName)){
					item->mClanPoint += points;

					if(!_strcmpi(self->GetName(), characterName))
						SetMyContribution(item->mClanPoint);

					break;
				}
			}
		}
	}
}