#include "TriggerVfs.h"

extern "C" TRIGGERVFS_API INDEXHANDLE _stdcall OpenVFS(const char* idxfile, const char* mode){ return 0; }
extern "C" TRIGGERVFS_API unsigned long _stdcall CloseVFS(INDEXHANDLE handle){ return 0; }
extern "C" TRIGGERVFS_API unsigned long _stdcall VGetVfsCount(INDEXHANDLE handle){ return 0; }
extern "C" TRIGGERVFS_API void _stdcall VGetVfsNames(INDEXHANDLE handle, char** names, unsigned long maxcount, unsigned long maxlen){}
extern "C" TRIGGERVFS_API unsigned long _stdcall VGetFileCount(INDEXHANDLE handle, const char* vfsfile){ return 0; }
extern "C" TRIGGERVFS_API void _stdcall VGetFileNames(INDEXHANDLE handle, const char* name, char** files, unsigned long &maxfiles, unsigned long maxlen){}
extern "C" TRIGGERVFS_API void _stdcall VGetFileInfo(INDEXHANDLE handle, const char* filename, char* info, unsigned long somehandle){}
extern "C" TRIGGERVFS_API unsigned long _stdcall VAddFile(INDEXHANDLE handle, const char* insertvfs, const char* localpath, const char* vfspath, unsigned long attribute, unsigned long checksum, unsigned long reserved, unsigned long reserved2, unsigned long reserved3){ return 0; }
extern "C" TRIGGERVFS_API bool _stdcall VFileExists(INDEXHANDLE handle, const char* filename){ return 0; }
extern "C" TRIGGERVFS_API bool _stdcall VFileExistsInVfs(INDEXHANDLE handle, const char* filename){ return 0; }
extern "C" TRIGGERVFS_API unsigned long _stdcall VRemoveFile(INDEXHANDLE handle, const char* filename){ return 0; }
extern "C" TRIGGERVFS_API unsigned short _stdcall VGetError(){ return 0; }
extern "C" TRIGGERVFS_API unsigned long _stdcall VGetTotFileCount(INDEXHANDLE handle){ return 0; }
extern "C" TRIGGERVFS_API unsigned long _stdcall VGetCurVersion(INDEXHANDLE handle){ return 0; }
extern "C" TRIGGERVFS_API unsigned long _stdcall VSetCurVersion(INDEXHANDLE handle, unsigned long newver){ return 0; }
extern "C" TRIGGERVFS_API unsigned long _stdcall VGetStdVersion(INDEXHANDLE handle){ return 0; }
extern "C" TRIGGERVFS_API unsigned long _stdcall VSetStdVersion(INDEXHANDLE handle, unsigned long newver){ return 0; }
extern "C" TRIGGERVFS_API bool _stdcall VAddVfs(INDEXHANDLE handle, const char* vfsname){ return 0; }
extern "C" TRIGGERVFS_API FILEHANDLE _stdcall VOpenFile(const char* path, INDEXHANDLE handle){ return 0; }
extern "C" TRIGGERVFS_API void _stdcall VCloseFile(FILEHANDLE handle){}
extern "C" TRIGGERVFS_API unsigned long _stdcall vfgetsize(FILEHANDLE handle){ return 0; }
extern "C" TRIGGERVFS_API unsigned long _stdcall vfread(void* buffer, unsigned long size, unsigned long count, FILEHANDLE handle){ return 0; }
extern "C" TRIGGERVFS_API unsigned long _stdcall vfseek(unsigned long filehandle, unsigned long offset, unsigned long origin){ return 0; }
extern "C" TRIGGERVFS_API unsigned long _stdcall vfgetdata(unsigned long filehandle, char* buffer){ return 0; }
extern "C" TRIGGERVFS_API unsigned long _stdcall vftell(unsigned long filehandle){ return 0; }
extern "C" TRIGGERVFS_API unsigned long _stdcall ComputeCrc(INDEXHANDLE handle, const char* filename){ return 0; }
