#ifndef _TRIGGERVFS
#define _TRIGGERVFS

#ifdef TRIGGERVFS_EXPORTS
#define TRIGGERVFS_API __declspec(dllexport)
#else
#define TRIGGERVFS_API __declspec(dllimport)
#endif

typedef unsigned long INDEXHANDLE;
typedef unsigned long FILEHANDLE;

extern "C" TRIGGERVFS_API INDEXHANDLE _stdcall OpenVFS(const char* idxfile, const char* mode);
extern "C" TRIGGERVFS_API unsigned long _stdcall CloseVFS(INDEXHANDLE handle);
extern "C" TRIGGERVFS_API unsigned long _stdcall VGetVfsCount(INDEXHANDLE handle);
extern "C" TRIGGERVFS_API void _stdcall VGetVfsNames(INDEXHANDLE handle, char** names, unsigned long maxcount, unsigned long maxlen);
extern "C" TRIGGERVFS_API unsigned long _stdcall VGetFileCount(INDEXHANDLE handle, const char* vfsfile);
extern "C" TRIGGERVFS_API void _stdcall VGetFileNames(INDEXHANDLE handle, const char* name, char** files, unsigned long &maxfiles, unsigned long maxlen);
extern "C" TRIGGERVFS_API void _stdcall VGetFileInfo(INDEXHANDLE handle, const char* filename, char* info, unsigned long somehandle);
extern "C" TRIGGERVFS_API unsigned long _stdcall VAddFile(INDEXHANDLE handle, const char* insertvfs, const char* localpath, const char* vfspath, unsigned long attribute, unsigned long checksum, unsigned long reserved, unsigned long reserved2, unsigned long reserved3);
extern "C" TRIGGERVFS_API bool _stdcall VFileExists(INDEXHANDLE handle, const char* filename);
extern "C" TRIGGERVFS_API bool _stdcall VFileExistsInVfs(INDEXHANDLE handle, const char* filename);
extern "C" TRIGGERVFS_API unsigned long _stdcall VRemoveFile(INDEXHANDLE handle, const char* filename);
extern "C" TRIGGERVFS_API unsigned short _stdcall VGetError();
extern "C" TRIGGERVFS_API unsigned long _stdcall VGetTotFileCount(INDEXHANDLE handle);
extern "C" TRIGGERVFS_API unsigned long _stdcall VGetCurVersion(INDEXHANDLE handle);
extern "C" TRIGGERVFS_API unsigned long _stdcall VSetCurVersion(INDEXHANDLE handle, unsigned long newver);
extern "C" TRIGGERVFS_API unsigned long _stdcall VGetStdVersion(INDEXHANDLE handle);
extern "C" TRIGGERVFS_API unsigned long _stdcall VSetStdVersion(INDEXHANDLE handle, unsigned long newver);
extern "C" TRIGGERVFS_API bool _stdcall VAddVfs(INDEXHANDLE handle, const char* vfsname);
extern "C" TRIGGERVFS_API FILEHANDLE _stdcall VOpenFile(const char* path, INDEXHANDLE handle);
extern "C" TRIGGERVFS_API void _stdcall VCloseFile(FILEHANDLE handle);
extern "C" TRIGGERVFS_API unsigned long _stdcall vfgetsize(FILEHANDLE handle);
extern "C" TRIGGERVFS_API unsigned long _stdcall vfread(void* buffer, unsigned long size, unsigned long count, FILEHANDLE handle);
extern "C" TRIGGERVFS_API unsigned long _stdcall vfseek(unsigned long filehandle, unsigned long offset, unsigned long origin);
extern "C" TRIGGERVFS_API unsigned long _stdcall vfgetdata(unsigned long filehandle, char* buffer);
extern "C" TRIGGERVFS_API unsigned long _stdcall vftell(unsigned long filehandle);
extern "C" TRIGGERVFS_API unsigned long _stdcall ComputeCrc(INDEXHANDLE handle, const char* filename);

#ifndef TRIGGERVFS_EXPORTS
class CVfs {
public:
	CVfs() : mHandle(0) {};
	CVfs(char* index){
		OpenVFS(index);
	}

	~CVfs(){
		if(mHandle)
			CloseVFS();
	}

	bool OpenVFS(const char* idxfile, const char* mode = "rb"){
		mHandle = ::OpenVFS(idxfile, mode);
		return mHandle != 0;
	}

	void CloseVFS(){
		::CloseVFS(mHandle);
		mHandle = 0;
	}

	unsigned long GetVfsCount(){
		return ::VGetVfsCount(mHandle);
	}

	void GetVfsNames(char** names, unsigned long maxcount, unsigned long maxlen){
		return ::VGetVfsNames(mHandle, names, maxcount, maxlen);
	}

	unsigned long GetFileCount(const char* vfsfile){
		return ::VGetFileCount(mHandle, vfsfile);
	}

	void GetFileNames(const char* name, char** files, unsigned long &maxfiles, unsigned long maxlen){
		return ::VGetFileNames(mHandle, name, files, maxfiles, maxlen);
	}

	void GetFileInfo(const char* filename, char* info, unsigned long somehandle){
		return ::VGetFileInfo(mHandle, filename, info, somehandle);
	}

	unsigned long AddFile(const char* insertvfs, const char* localpath, const char* vfspath, unsigned long attribute = 100, unsigned long reserved = 0, unsigned long reserved2 = 0, unsigned long reserved3 = 0){
		return ::VAddFile(mHandle, insertvfs, localpath, vfspath, attribute, ComputeCrc(localpath), reserved, reserved2, reserved3);
	}

	bool FileExists(const char* filename){
		return ::VFileExists(mHandle, filename);
	}

	bool FileExistsInVfs(const char* filename){
		return ::VFileExistsInVfs(mHandle, filename);
	}

	unsigned long RemoveFile(const char* filename){
		return ::VRemoveFile(mHandle, filename);
	}

	unsigned short GetError(){
		return ::VGetError();
	}

	unsigned long GetTotFileCount(){
		return ::VGetTotFileCount(mHandle);
	}

	unsigned long GetCurVersion(){
		return ::VGetCurVersion(mHandle);
	}

	unsigned long SetCurVersion(unsigned long newver){
		return ::VSetCurVersion(mHandle, newver);
	}

	unsigned long GetStdVersion(){
		return ::VGetStdVersion(mHandle);
	}

	unsigned long SetStdVersion(unsigned long newver){
		return ::VSetStdVersion(mHandle, newver);
	}

	bool AddVfs(const char* vfsname){
		return ::VAddVfs(mHandle, vfsname);
	}

	FILEHANDLE OpenFile(const char* path){
		return ::VOpenFile(path, mHandle);
	}

	void CloseFile(FILEHANDLE handle){
		return ::VCloseFile(handle);
	}

	unsigned long FGetSize(FILEHANDLE handle){
		return ::vfgetsize(handle);
	}

	unsigned long FRead(void* buffer, unsigned long size, unsigned long count, FILEHANDLE handle){
		return ::vfread(buffer, size, count, handle);
	}

	unsigned long FSeek(FILEHANDLE filehandle, unsigned long offset, unsigned long origin){
		return ::vfseek(filehandle, offset, origin);
	}

	unsigned long FGetData(FILEHANDLE filehandle, char* buffer){
		return ::vfgetdata(filehandle, buffer);
	}

	unsigned long FTell(FILEHANDLE filehandle){
		return ::vftell(filehandle);
	}

	unsigned long ComputeCrc(const char* filename){
		return ::ComputeCrc(mHandle, filename);
	}
	
private:
	INDEXHANDLE mHandle;
};
#endif

#endif
