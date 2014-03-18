#ifndef ACHIEVEMENT_LIST
#define ACHIEVEMENT_LIST

#define TIXML_USE_TICPP
#include <tinyxml.h>
#include <ticpp.h>
#include <ExLIB\Array.hpp>
#include <ExLIB\String.hpp>
#include "..\Shared\Console.hpp"

#ifdef VER_CLIENT
# include "TriggerVFS\TriggerVFS.h"
#endif

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef unsigned long       dword;
typedef unsigned char       byte;
typedef unsigned short      word;

void CreateKey(char* filepath, byte* oKey);

class Achievement {
public:
	class Condition {
	public:
		enum Type {
			AC_STAT,
			AC_SKILL,
			AC_KILL,

			AC_ITEM,
			AC_FLAG,
			AC_GRADE,
			AC_RANK,
			AC_FUNDS,
			AC_TRIGGER,

			AC_INVALID,
		};

		enum Op {
			OP_EQ,
			OP_NE,
			OP_GT,
			OP_GE,
			OP_LT,
			OP_LE,

			OP_INVALID,
		};

	public:
		Condition()
			: mType(AC_INVALID), mOp(OP_INVALID), mValType(0), mValCount(0), mValID(0)
		{
		}

		~Condition(){}

		Type mType;
		Op mOp;
		int mValType;
		int mValCount;
		int mValID;
	};

public:
	Achievement()
		: mID(-1), mIcon(0), mUnkIcon(0), mRequire(1), mHideIfUnachieved(false)
	{
	}

	~Achievement(){
		mConditions.DeleteValues();
	}

	int mID;
	String mName;
	String mDescription;
	String mUnkName;
	String mUnkDescription;
	int mIcon;
	int mUnkIcon;
	int mRequire;
	bool mHideIfUnachieved;

#ifdef VER_CLIENT
	class CTListItemAchievement* mListItem;
#endif

	Array<Condition*> mConditions;
};

class AchievementList {
public:
	AchievementList(){}
	~AchievementList(){
		mGeneral.DeleteValues();
		mQuests.DeleteValues();
		mEvents.DeleteValues();
		mClan.DeleteValues();
		mMonster.DeleteValues();
		mPvp.DeleteValues();
		mAll.Clear();
	}

	bool LoadXML(const char* path){
		try {
#ifdef VER_CLIENT
			FILEHANDLE vfsHandle = OpenVFS("data.idx", "mr");
			FILEHANDLE fh = VOpenFile(path, vfsHandle);

			if(!fh) return false;
			vfseek(fh, 0, SEEK_END);
			long fileSize = vftell(fh);
			vfseek(fh, 0, SEEK_SET);
			byte* fileData = new byte[fileSize+1];
			vfread(fileData, 1, fileSize, fh);
			VCloseFile(fh);
			
			TiXmlDocument* doc = new TiXmlDocument();
			doc->Parse((const char*)fileData);

			ReadSection(doc, "general", &mGeneral);
			ReadSection(doc, "quest", &mQuests);
			ReadSection(doc, "event", &mEvents);
			ReadSection(doc, "clan", &mClan);
			ReadSection(doc, "monster", &mMonster);
			ReadSection(doc, "pvp", &mPvp);

#else

			TiXmlDocument doc(path);
			if(!doc.LoadFile()){
				Log(MSG_INFO, "Failed to open achievements.xml!");
				return false;
			}
			
			ReadSection(&doc, "general", &mGeneral);
			ReadSection(&doc, "quest", &mQuests);
			ReadSection(&doc, "event", &mEvents);
			ReadSection(&doc, "clan", &mClan);
			ReadSection(&doc, "monster", &mMonster);
			ReadSection(&doc, "pvp", &mPvp);

#endif
		}catch(ticpp::Exception& /*ex*/){
			return false;
		}

		return true;
	}

	bool ReadSection(TiXmlDocument* doc, const char* section, Array<Achievement*>* list){
		try {
			TiXmlElement* root = doc->FirstChild(section)->ToElement();
			int unkIcon = 1;
			root->Attribute("unkicon", &unkIcon);

			TiXmlElement* cur = root->FirstChildElement("achieve");
			while(cur){
				Achievement* ach = new Achievement();
				cur->Attribute("id", &ach->mID);
				ach->mName = cur->Attribute("name");
				ach->mDescription = cur->Attribute("description");
				ach->mUnkName = cur->Attribute("unkname");
				ach->mUnkDescription = cur->Attribute("unkdesc");
				cur->Attribute("icon", &ach->mIcon);
				ach->mUnkIcon = unkIcon;
				cur->Attribute("hide", (int*)&ach->mHideIfUnachieved);

				TiXmlElement* econd = cur->FirstChildElement();
				while(econd){
					Achievement::Condition* cond = new Achievement::Condition();
					ach->mConditions.PushBack(cond);

					const char* type = econd->Value();
					if(!_strcmpi(type, "stat"))				cond->mType = Achievement::Condition::AC_STAT;
					else if(!_strcmpi(type, "skill")) cond->mType = Achievement::Condition::AC_SKILL;
					else if(!_strcmpi(type, "kill"))	cond->mType = Achievement::Condition::AC_KILL;
					else if(!_strcmpi(type, "item"))	cond->mType = Achievement::Condition::AC_ITEM;
					else if(!_strcmpi(type, "flag"))	cond->mType = Achievement::Condition::AC_FLAG;
					else if(!_strcmpi(type, "grade")) cond->mType = Achievement::Condition::AC_GRADE;
					else if(!_strcmpi(type, "rank"))	cond->mType = Achievement::Condition::AC_RANK;
					else if(!_strcmpi(type, "funds")) cond->mType = Achievement::Condition::AC_FUNDS;
					else if(!_strcmpi(type, "trigger")) cond->mType = Achievement::Condition::AC_TRIGGER;
					else cond->mType = Achievement::Condition::AC_INVALID;

					const char* op = econd->Attribute("operator");
					if(op){
						if(!_strcmpi(op, "=="))				cond->mOp = Achievement::Condition::OP_EQ;
						else if(!_strcmpi(op, "!="))	cond->mOp = Achievement::Condition::OP_NE;
						else if(!_strcmpi(op, ">"))		cond->mOp = Achievement::Condition::OP_GT;
						else if(!_strcmpi(op, ">="))	cond->mOp = Achievement::Condition::OP_GE;
						else if(!_strcmpi(op, "<"))		cond->mOp = Achievement::Condition::OP_LT;
						else if(!_strcmpi(op, "<="))	cond->mOp = Achievement::Condition::OP_LE;
					}else{
						cond->mOp = Achievement::Condition::OP_INVALID;
					}

					econd->Attribute("type", &cond->mValType);
					econd->Attribute("count", &cond->mValCount);
					if(cond->mType != Achievement::Condition::AC_TRIGGER)
						econd->Attribute("id", &cond->mValID);
					else{
						const char* trigger = econd->Attribute("id");
						if(trigger)
							cond->mValID = StrToHashKey(trigger);
						else
							cond->mValID = 0;
					}

					econd = econd->NextSiblingElement();
				}
				
				const char* require = cur->Attribute("require");
				ach->mRequire = (require)?atoi(require):ach->mConditions.Size();

				list->PushBack(ach);
				mAll.PushBack(ach);
				cur = cur->NextSiblingElement("achieve");
			}

		}catch(ticpp::Exception& /*ex*/){
			return false;
		}

		return true;
	}

	Achievement* GetByID(int id){
		for(unsigned int i = 0; i < mAll.Size(); ++i)
			if(mAll[i]->mID == id)
				return mAll[i];

		return NULL;
	}
	
public:
	Array<Achievement*> mGeneral;
	Array<Achievement*> mQuests;
	Array<Achievement*> mEvents;
	Array<Achievement*> mClan;
	Array<Achievement*> mMonster;
	Array<Achievement*> mPvp;

	Array<Achievement*> mAll;
};

#endif