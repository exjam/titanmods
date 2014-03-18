////////////////////////////////////////////////////////////////////////
///////  CSyncIdxARRAY<CGameOBJ*>  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#include "CSyncIdxARRAY.h"

class CGameOBJ;
void CSyncIdxARRAY<CGameOBJ *>::Lock() { return CallMemberFunction<CSyncIdxARRAY<CGameOBJ *>, void>(0x1000C5D0, this); }
void CSyncIdxARRAY<CGameOBJ *>::Unlock() { return CallMemberFunction<CSyncIdxARRAY<CGameOBJ *>, void>(0x1000C610, this); }