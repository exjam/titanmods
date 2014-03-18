#ifndef IT_MGR_H
#define IT_MGR_H

#include <Shared/Templates.hpp>

class CTCommand;
class CTDialog;

static enum {
	CHAT_TYPE_ALL,
	CHAT_TYPE_SHOUT,
	CHAT_TYPE_PARTY,
	CHAT_TYPE_WHISPER,
	CHAT_TYPE_NOTICE,
	CHAT_TYPE_SYSTEM,
	CHAT_TYPE_ERROR,
	CHAT_TYPE_QUEST,
	CHAT_TYPE_QUESTREWARD,
	CHAT_TYPE_CLAN,
	CHAT_TYPE_TRADE,
	CHAT_TYPE_ALLIED,
	CHAT_TYPE_FRIEND,
	CHAT_TYPE_MAX,
};

static enum{
	DLG_TYPE_NONE			= 0,
	DLG_TYPE_MENU,			//1
	DLG_TYPE_CHAT,			//2
	DLG_TYPE_DIALOG,		//3
	DLG_TYPE_MAKE,			//4
	DLG_TYPE_COMMUNITY,		//5
	DLG_TYPE_STORE,			//6
	DLG_TYPE_DEAL,			//7
	DLG_TYPE_QUICKBAR,		//8
	DLG_TYPE_CHAR,			//9
	DLG_TYPE_MINIMAP,		//10
	DLG_TYPE_PARTYOPTION,	//11
	DLG_TYPE_RESTART,		//12
	DLG_TYPE_SYSTEM,		//13
	DLG_TYPE_QUEST,			//14
	DLG_TYPE_EXCHANGE,		//15
	DLG_TYPE_SKILL,			//16
	DLG_TYPE_SYSTEMMSG,		//17
	DLG_TYPE_N_INPUT,		//18
	DLG_TYPE_MSGBOX,		//19
	DLG_TYPE_OPTION,		//20
	DLG_TYPE_TARGET_MENU,	///21
	DLG_TYPE_PARTY,			///22
	DLG_TYPE_BANK,			///23
	DLG_TYPE_HELP,			///24
	DLG_TYPE_INFO,			///25
	DLG_TYPE_MEMO,			///26
	DLG_TYPE_ITEM,			///27
	DLG_TYPE_PRIVATESTORE,	///28
	DLG_TYPE_AVATARSTORE,	///29
	DLG_TYPE_GOODS,			///30
	DLG_TYPE_ADDFRIEND,		///31
	DLG_TYPE_PRIVATECHAT,	///32
	DLG_TYPE_CHATROOM,		///33
	DLG_TYPE_MEMOVIEW,		///34
	DLG_TYPE_SEPARATE,		///35
	DLG_TYPE_UPGRADE,		///36
	DLG_TYPE_CLAN,			///37
	DLG_TYPE_CLAN_ORGANIZE, ///38
	DLG_TYPE_CLAN_NOTICE,	///39
	DLG_TYPE_CHATFILTER,	///40
	DLG_TYPE_MSGBOX_SPECIAL,///41
	DLG_TYPE_SELECTEVENT,	///42
	DLG_TYPE_EVENTDIALOG,	///43
	DLG_TYPE_NOTIFY,		///44
	DLG_TYPE_SKILLTREE,		///45
	DLG_TYPE_DELIVERYSTORE,	///46
	DLG_TYPE_INPUTNAME,		///47
	DLG_TYPE_BANKWINDOW,	///48
	DLG_TYPE_MAX,			///49
	DLG_TYPE_ACHIEVEMENTS = 100,	///50
	DLG_TYPE_SKILLBAR2 = 101,		///51
	DLG_TYPE_PVP = 102,
	DLG_TYPE_PVPINSTANCE = 103, ///52
	DLG_TYPE_DUELINVITE = 104,
	DLG_TYPE_APPEARANCE = 105,
};

class MsgBox {
public:
	enum {
		BT_OK = 1,
		BT_CANCEL = 2,
		BT_OKCANCEL = 3,
	};
};
class CMsgBox;

class IT_MGR {
public:
	CTDialog* FindDlg( DWORD dwDlgType ){  
		return CallMemberFunction<IT_MGR, CTDialog*, DWORD>(0x0048D820, this, dwDlgType);  
	}
	void AppendChatMsg(const char* text, int type, unsigned int colour = 0){  
		return CallMemberFunction<IT_MGR, void, const char*, int, unsigned int>(0x0048D890, this, text, type, colour);  
	}
	void OpenMsgBox(char* text, int buttonType, int modal, int invokerDlg, CTCommand* commandOK, CTCommand* commandCancel, int msgType){  
		return CallMemberFunction<IT_MGR, void, char*, int, int, int, CTCommand*, CTCommand*, int>(0x0048F320, this, text, buttonType, modal, invokerDlg, commandOK, commandCancel, msgType);  
	}
	void AppendDlg(short type, CTDialog* dialog, int id = 0){  
		return CallMemberFunction<IT_MGR, void, short, CTDialog*, int>(0x0048F9D0, this, type, dialog, id);  
	}
	void AddDialogIcon(int type ){  
		return CallMemberFunction<IT_MGR, void, int>(0x0048FCF0, this, type);  
	}
	void OpenDialog( int iDlgType, bool bToggle = true, int iPosX = -1, int iPosY = -1 ){  
		return CallMemberFunction<IT_MGR, void, int, bool, int, int>(0x0048FC00, this, iDlgType, bToggle, iPosX, iPosY);  
	}

	CMsgBox* FindMsgBox( int iMsgType ) {
		return CallMemberFunction<IT_MGR, CMsgBox*, int>(0x0048DD40, this, iMsgType); 
	}

	static IT_MGR* Instance(){
		return reinterpret_cast<IT_MGR*>(0x697AD0);
	}
};

#endif
