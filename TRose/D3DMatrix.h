#ifndef D3DMATRIX_H
#define D3DMATRIX_H

#include "FunctionPointer.h"

#ifndef __D3DX9MATH_H__
struct D3DMATRIX {
	union {
		struct {
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};

		float m[4][4];
	};
};
#endif

PTRFUNC_A4(0x0056A948, __stdcall, void, D3DXMatrixTranslation, D3DMATRIX* matrix, float x, float y, float z)

#endif
