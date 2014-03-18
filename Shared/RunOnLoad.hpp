#ifndef RunOnLoad

#include "Code.hpp"
#include "../Shared/Console.hpp"

#include <ExLIB/List.hpp>

typedef void (__stdcall *PF_SVOIDVOID)(void);
typedef void (__cdecl *PF_CVOIDVOID)(void);

class RunList {
public:
	RunList(){}
	~RunList(){}

	static RunList& Instance(){
		static RunList self;
		return self;
	}

	void AddFunction(PF_SVOIDVOID func, char* name){
		mFunctions.push_back(RunFunc(func, name));
	}

	void RunFunctions(){
		for(auto itr = mFunctions.begin(); itr != mFunctions.end(); ++itr){
			PF_SVOIDVOID func = (*itr).mFunction;
			(*func)();
		}
	}

	struct RunFunc {
		RunFunc(PF_SVOIDVOID func, char* name) : mFunction(func), mName(name) {}

		PF_SVOIDVOID mFunction;
		char* mName;
	};

	List<RunFunc> mFunctions;
};

class HookList {
public:
	struct Hook {
		int mAddress;
		PF_CVOIDVOID mFunction;
		int mNOPS;
		char* mName;
	};

public:
	HookList(){}
	~HookList(){}

	static HookList& Instance(){
		static HookList self;
		return self;
	}

	void AddHook(int addr, PF_CVOIDVOID func, int nops, char* name){
		Hook* hook = new Hook();
		hook->mAddress = addr;
		hook->mFunction = func;
		hook->mNOPS = nops;
		hook->mName = name;
		mHooks.push_back(hook);
	}

	void ApplyHooks(){
		for(List<Hook*>::Iterator itr = mHooks.begin(); itr != mHooks.end(); ++itr){
			Hook* hook = *itr;
			Code::JmpHook(hook->mAddress, hook->mFunction, hook->mNOPS);
		}
	}

	List<Hook*> mHooks;
};

class WriteList {
public:
	struct Write {
		int mAddress;
		unsigned char* mData;
		int mLength;
	};

public:
	WriteList(){}
	~WriteList(){}

	static WriteList& Instance(){
		static WriteList self;
		return self;
	}

	void AddHook(int addr, unsigned char* data, int length){
		Write* write = new Write();
		write->mAddress = addr;
		write->mData = data;
		write->mLength = length;
		mWrites.push_back(write);
	}

	void ApplyWrites(){
		for(List<Write*>::Iterator itr = mWrites.begin(); itr != mWrites.end(); ++itr){
			Write* write = *itr;
			Code::Write(write->mAddress, write->mData, write->mLength);
		}
	}

	List<Write*> mWrites;
};

#define RunOnLoad(FuncName) \
class FuncRunOnLoadClass_##FuncName {\
public: \
	FuncRunOnLoadClass_##FuncName(){ \
	RunList::Instance().AddFunction(FuncName, #FuncName); \
	}; \
}; \
	FuncRunOnLoadClass_##FuncName gAutoRunner_##FuncName;

#define HookOnLoad(pos, FuncName, nops) \
class FuncHookOnLoadClass_##FuncName {\
public: \
	FuncHookOnLoadClass_##FuncName(){ \
	HookList::Instance().AddHook(pos, (PF_CVOIDVOID)FuncName, nops, #FuncName); \
	}; \
}; \
	FuncHookOnLoadClass_##FuncName gAutoHooker_##FuncName;

#define WriteOnLoad(pos, data, length) \
class FuncWriteOnLoadClass_##FuncName {\
public: \
	FuncWriteOnLoadClass_##FuncName(){ \
	WriteList::Instance().AddHook(pos, data, length); \
	}; \
}; \
	FuncWriteOnLoadClass_##FuncName gAutoWriter_##FuncName;


#endif

