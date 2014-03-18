/**
 * @file zz_type.h
 * @brief miscellaneous type.
 * @author Jiho Choi(zho@popsmail.com)
 * @version 2.0
 * @date 24-aug-2001
 *
 * $Header: /engine/include/zz_type.h 20    06-12-29 4:24a Choo0219 $
 * $History: zz_type.h $
 * 
 * *****************  Version 20  *****************
 * User: Choo0219     Date: 06-12-29   Time: 4:24a
 * Updated in $/engine/include
 * 
 * *****************  Version 19  *****************
 * User: Choo0219     Date: 05-03-02   Time: 10:49a
 * Updated in $/engine/include
 * 
 * *****************  Version 18  *****************
 * User: Zho          Date: 04-08-17   Time: 2:53p
 * Updated in $/engine/include
 * 
 * *****************  Version 17  *****************
 * User: Zho          Date: 04-08-16   Time: 11:35p
 * Updated in $/engine/include
 * 
 * *****************  Version 16  *****************
 * User: Zho          Date: 04-07-26   Time: 11:43a
 * Updated in $/engine/include
 * 
 * *****************  Version 15  *****************
 * User: Zho          Date: 04-07-25   Time: 9:33p
 * Updated in $/engine/include
 * 
 * *****************  Version 14  *****************
 * User: Zho          Date: 04-07-24   Time: 10:01p
 * Updated in $/engine/include
 * 
 * *****************  Version 13  *****************
 * User: Zho          Date: 04-07-24   Time: 6:51p
 * Updated in $/engine/include
 * 
 * *****************  Version 12  *****************
 * User: Zho          Date: 04-07-05   Time: 9:37p
 * Updated in $/engine/include
 * vertex buffer redesigned
 * 
 * *****************  Version 11  *****************
 * User: Zho          Date: 04-05-26   Time: 9:13p
 * Updated in $/engine/include
 * 
 * *****************  Version 10  *****************
 * User: Zho          Date: 04-04-21   Time: 11:01p
 * Updated in $/engine/include
 * 
 * *****************  Version 9  *****************
 * User: Zho          Date: 04-02-26   Time: 12:01p
 * Updated in $/engine/include
 * 
 * *****************  Version 8  *****************
 * User: Zho          Date: 04-02-11   Time: 5:06p
 * Updated in $/engine/include
 * Added ZZ_TIME_TO_SEC
 * 
 * *****************  Version 7  *****************
 * User: Zho          Date: 04-02-06   Time: 1:28p
 * Updated in $/engine/include
 * Xform coordinate system
 * 
 * *****************  Version 6  *****************
 * User: Zho          Date: 04-02-04   Time: 5:08p
 * Updated in $/engine/include
 * 
 * *****************  Version 5  *****************
 * User: Zho          Date: 03-12-17   Time: 10:31p
 * Updated in $/engine/include
 * - renamed MILLISECOND to MSEC.
 * - instant eye-blinking implementation.
 * 
 * *****************  Version 4  *****************
 * User: Zho          Date: 03-12-12   Time: 7:50p
 * Updated in $/engine/include
 * color format added
 * 
 * *****************  Version 3  *****************
 * User: Zho          Date: 03-12-02   Time: 9:20p
 * Updated in $/engine/include
 * do not use zz_vfs_pkg as defaulst filesystem 
 * 
 * *****************  Version 2  *****************
 * User: Zho          Date: 03-12-02   Time: 6:03p
 * Updated in $/engine/include
 * read_uint32(int&) bug fixed. if read_uint32(int&) read zero, then
 * status changed to EOF. that was the bug.
 * In zz_type.h, new define zz_vfs added.
 * 
 * *****************  Version 1  *****************
 * User: Zho          Date: 03-11-30   Time: 8:06p
 * Created in $/engine/include
 * 
 * *****************  Version 1  *****************
 * User: Zho          Date: 03-11-30   Time: 7:58p
 * Created in $/engine_1/include
 * 
 * *****************  Version 1  *****************
 * User: Zho          Date: 03-11-30   Time: 7:54p
 * Created in $/engine/engine/include
 * 
 * *****************  Version 1  *****************
 * User: Zho          Date: 03-11-30   Time: 7:48p
 * Created in $/engine/msvc71/include
 * 
 * *****************  Version 1  *****************
 * User: Zho          Date: 03-11-30   Time: 6:20p
 * Created in $/Engine/BUILD/msvc71/msvc71.root/msvc71/include
 * 
 * *****************  Version 1  *****************
 * User: Zho          Date: 03-11-30   Time: 6:08p
 * Created in $/Engine/INCLUDE
 * 
 * *****************  Version 15  *****************
 * User: Zho          Date: 03-11-26   Time: 9:14p
 * Updated in $/znzin11/engine/include
 * - added zz_size
 */

#ifndef __ZZ_TYPE_H__
#define __ZZ_TYPE_H__

#pragma warning(disable : 4786)

/* for vector argument */
#define _X_ 0
#define _Y_ 1
#define _Z_ 2

#define _R_ 0
#define _G_ 1
#define _B_ 2
#define _A_ 3

/* in VC++ type ranges */
/*
type_name      | bytes | other names    | range of values
=================================================
int            | * | signed, signed int                 | System dependent 
unsigned int   | * | unsigned                           | System dependent 
__int8         | 1 | char, signed char                  | -128 to 127 
__int16        | 2 | short, short int, signed short int | -32,768 to 32,767 
__int32        | 4 | signed, signed int                 | -2,147,483,648 to 2,147,483,647 
__int64        | 8 | none                               | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 
char           | 1 | signed char                        | -128 to 127 
unsigned char  | 1 | none                               | 0 to 255 
short          | 2 | short int, signed short int        | -32,768 to 32,767 
unsigned short | 2 | unsigned short int                 | 0 to 65,535 
long           | 4 | long int, signed long int          | -2,147,483,648 to 2,147,483,647 
unsigned long  | 4 | unsigned long int                  | 0 to 4,294,967,295 
enum           | * | none                               | Same as int  
float          | 4 | none                               | 3.4E +/- 38 (7 digits) 
double         | 8 | none                               | 1.7E +/- 308 (15 digits) 
long double    |10 | none                               | 1.2E +/- 4932 (19 digits) 
*/

//typedef unsigned char  bool; /* 1 */
typedef unsigned char  byte; /* 1 */

#ifdef WIN32
#include <windows.h>
#include <d3d9.h>
typedef signed __int16        int16; /* 2 */
typedef signed __int32        int32; /* 4 */
typedef signed __int64        int64; /* 8 */
typedef unsigned __int64 uint64;
typedef DWORD dword;
typedef RECT zz_rect;
typedef D3DCOLOR color32; // argb
typedef SIZE zz_size;
#else
typedef short int      int16; /* 2 */
typedef int            int32; /* 4 */
typedef unsigned long dword;
// same as WIN32 RECT
typedef struct _zz_rect {
  long left; 
  long top; 
  long right; 
  long bottom; 
} zz_rect; 
typedef dword color32; // argb
typedef struct _zz_size {
	long cx; 
	long cy; 
} zz_size;

#endif // WIN32

typedef unsigned short uint16; /* 2 */
// typedef unsigned long  uint32; /* 4 */
typedef unsigned int uint32; /* 4 */
typedef unsigned int uint; /* ?(..4) */
typedef unsigned char  uchar; /* 1 */

typedef unsigned long ulong;

typedef unsigned long zz_time;

typedef unsigned long zz_handle;

// checks if the handle is in the valid range
#define ZZ_HANDLE_NULL        (-1)             // null handle value
#define ZZ_HANDLE_IS_VALID(h) (h != -1)       // Is this handle valid?
#define ZZ_HANDLE_IS_INVALID(h) (h == -1) // Is this handle invalid?

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

// default 100 MEGA byte memory (is it OK?)
#define ZZ_MAX_MEMORY 100000000 
#define ZZ_MAX_STRING 255
#define ZZ_MAX_VERTEX_BUFFERS 1000
#define ZZ_MAX_INDEX_BUFFERS 1000
#define ZZ_MAX_TEXTURES 100
#define ZZ_MAX_NODENAME_SIZE 255
#define ZZ_MAX_LIGHTS 8
#define ZZ_MAX_SMOOTH_GROUPS 32 // smoothing groups
#define ZZ_MAX_WEIGHTING_BONES 4 // default = 4
#define ZZ_MAX_HW_BONE_SIZE 27
#define ZZ_MAX_SHADERS 100
#define ZZ_MAX_MAP_CHANNEL 4 // mesh max map channel

#define ZZ_MIN(x, y) (((x) < (y)) ? (x) : (y))
#define ZZ_MAX(x, y) (((x) > (y)) ? (x) : (y))

#define ZZ_TICK_PER_SEC 4800 // 1 second = 4800 timer ticks
#define ZZ_FRAME_TO_TICK(frame_to_tick_FRAME, frame_to_tick_FPS) \
	(zz_time(double(frame_to_tick_FRAME) * ZZ_TICK_PER_SEC / frame_to_tick_FPS))
#define ZZ_TICK_TO_FRAME(tick_to_frame_TICK, tick_to_frame_FPS) \
	(int(double(tick_to_frame_TICK) * tick_to_frame_FPS / ZZ_TICK_PER_SEC))

// convert zz_time type to milli-second type
// t is zz_time type.
#define ZZ_TIME_TO_MSEC(t) (t*1000/ZZ_TICK_PER_SEC)
#define ZZ_TIME_TO_SEC(t) (t/ZZ_TICK_PER_SEC)

// convert milli-second type to zz_time type
#define ZZ_MSEC_TO_TIME(m) (m*ZZ_TICK_PER_SEC/1000)

#define ZZ_DEFAULT_NODE_NAME "unknown_node_"

// miscellaneous helper functions : stolen from d3dutil.h
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)        { if(p) { (p)->Release(); (p)=NULL; } }
#endif

//#ifndef SAFE_DELETE_ARRAY
//#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
//#endif

#define ZZ_SAFE_DELETE(p)       { if(p) { zz_delete (p);     (p)=NULL; } }
#define ZZ_SAFE_DELETE_ARRAY(p) { if(p) { zz_delete[] (p);   (p)=NULL; } }

#define ZZ_SAFE_RELEASE(p)      { if(p) { (p)->release(); (p)=NULL; } }

// to replace "model->addref()" to "ZZ_ADDREF(model)", do as following in visual studio replace files dialog
// Find what    :  {:i}\-\>addref\(\)
// Replace with :  ZZ_ADDREF(\1)
// Use          :  Regular expression
#define ZZ_ADDREF(p)        { if (p) p->addref(); }

#define ZZ_STREQ(a, b) (strcmp(a, b) == 0)

//---------------------------------------------------------------------------------------------
// zz_color
//---------------------------------------------------------------------------------------------
#define ZZ_COLOR32_ARGB(a,r,g,b) \
    ((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff))
#define ZZ_COLOR32_ALPHA(C) (((C)&0xFF000000) >> 24)
#define ZZ_COLOR32_RED(C) (((C)&0x00FF0000) >> 16)
#define ZZ_COLOR32_GREEN(C) (((C)&0x0000FF00) >> 8)
#define ZZ_COLOR32_BLUE(C) (((C)&0x000000FF))

struct zz_color
{
	float r, g, b, a;

	zz_color() { }
	zz_color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) { }
	zz_color(color32 argb32) : a(float((argb32>>24)&0xff)/255.0f), r(float((argb32>>16)&0xff)/255.0f), g(float((argb32>>8)&0xff)/255.0f), b(float(argb32&0xff)/255.0f) {}
	
	operator dword () const
	{
		return ZZ_COLOR32_ARGB(int(a*255.0f), int(r*255.0f), int(g*255.0f), int(b*255.0f));
	}

	bool operator == (const zz_color& c) const
	{
		return ((c.a == a) && (c.r == r) && (c.g == g) && (c.b == b));
	}
};


//---------------------------------------------------------------------------------------------
// color format (same as one in d3d9type.h)
//---------------------------------------------------------------------------------------------
// from d3d9types.h
/* Formats
 * Most of these names have the following convention:
 *      A = Alpha
 *      R = Red
 *      G = Green
 *      B = Blue
 *      X = Unused Bits
 *      P = Palette
 *      L = Luminance
 *      U = dU coordinate for BumpMap
 *      V = dV coordinate for BumpMap
 *      S = Stencil
 *      D = Depth (e.g. Z or W buffer)
 *      C = Computed from other channels (typically on certain read operations)
 *
 *      Further, the order of the pieces are from MSB first; hence
 *      D3DFMT_A8L8 indicates that the high byte of this two byte
 *      format is alpha.
 *
 *      D16 indicates:
 *           - An integer 16-bit value.
 *           - An app-lockable surface.
 *
 *      All Depth/Stencil formats except D3DFMT_D16_LOCKABLE indicate:
 *          - no particular bit ordering per pixel, and
 *          - are not app lockable, and
 *          - the driver is allowed to consume more than the indicated
 *            number of bits per Depth channel (but not Stencil channel).
 */
#ifndef ZZ_MAKEFOURCC
    #define ZZ_MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
                ((dword)(byte)(ch0) | ((dword)(byte)(ch1) << 8) |       \
                ((dword)(byte)(ch2) << 16) | ((dword)(byte)(ch3) << 24 ))
#endif /* defined(MAKEFOURCC) */

typedef enum _ZZ_FORMAT
{
    ZZ_FMT_UNKNOWN              =  0,

    ZZ_FMT_R8G8B8               = 20,
    ZZ_FMT_A8R8G8B8             = 21,
    ZZ_FMT_X8R8G8B8             = 22,
    ZZ_FMT_R5G6B5               = 23,
    ZZ_FMT_X1R5G5B5             = 24,
    ZZ_FMT_A1R5G5B5             = 25,
    ZZ_FMT_A4R4G4B4             = 26,
    ZZ_FMT_R3G3B2               = 27,
    ZZ_FMT_A8                   = 28,
    ZZ_FMT_A8R3G3B2             = 29,
    ZZ_FMT_X4R4G4B4             = 30,
    ZZ_FMT_A2B10G10R10          = 31,
    ZZ_FMT_A8B8G8R8             = 32,
    ZZ_FMT_X8B8G8R8             = 33,
    ZZ_FMT_G16R16               = 34,
    ZZ_FMT_A2R10G10B10          = 35,
    ZZ_FMT_A16B16G16R16         = 36,

    ZZ_FMT_A8P8                 = 40,
    ZZ_FMT_P8                   = 41,

    ZZ_FMT_L8                   = 50,
    ZZ_FMT_A8L8                 = 51,
    ZZ_FMT_A4L4                 = 52,

    ZZ_FMT_V8U8                 = 60,
    ZZ_FMT_L6V5U5               = 61,
    ZZ_FMT_X8L8V8U8             = 62,
    ZZ_FMT_Q8W8V8U8             = 63,
    ZZ_FMT_V16U16               = 64,
    ZZ_FMT_A2W10V10U10          = 67,

    ZZ_FMT_UYVY                 = ZZ_MAKEFOURCC('U', 'Y', 'V', 'Y'),
    ZZ_FMT_R8G8_B8G8            = ZZ_MAKEFOURCC('R', 'G', 'B', 'G'),
    ZZ_FMT_YUY2                 = ZZ_MAKEFOURCC('Y', 'U', 'Y', '2'),
    ZZ_FMT_G8R8_G8B8            = ZZ_MAKEFOURCC('G', 'R', 'G', 'B'),
    ZZ_FMT_DXT1                 = ZZ_MAKEFOURCC('D', 'X', 'T', '1'),
    ZZ_FMT_DXT2                 = ZZ_MAKEFOURCC('D', 'X', 'T', '2'),
    ZZ_FMT_DXT3                 = ZZ_MAKEFOURCC('D', 'X', 'T', '3'),
    ZZ_FMT_DXT4                 = ZZ_MAKEFOURCC('D', 'X', 'T', '4'),
    ZZ_FMT_DXT5                 = ZZ_MAKEFOURCC('D', 'X', 'T', '5'),

    ZZ_FMT_D16_LOCKABLE         = 70,
    ZZ_FMT_D32                  = 71,
    ZZ_FMT_D15S1                = 73,
    ZZ_FMT_D24S8                = 75,
    ZZ_FMT_D24X8                = 77,
    ZZ_FMT_D24X4S4              = 79,
    ZZ_FMT_D16                  = 80,

    ZZ_FMT_D32F_LOCKABLE        = 82,
    ZZ_FMT_D24FS8               = 83,


    ZZ_FMT_L16                  = 81,

    ZZ_FMT_VERTEXDATA           =100,
    ZZ_FMT_INDEX16              =101,
    ZZ_FMT_INDEX32              =102,

    ZZ_FMT_Q16W16V16U16         =110,

    ZZ_FMT_MULTI2_ARGB8         = ZZ_MAKEFOURCC('M','E','T','1'),

    // Floating point surface formats

    // s10e5 formats (16-bits per channel)
    ZZ_FMT_R16F                 = 111,
    ZZ_FMT_G16R16F              = 112,
    ZZ_FMT_A16B16G16R16F        = 113,

    // IEEE s23e8 formats (32-bits per channel)
    ZZ_FMT_R32F                 = 114,
    ZZ_FMT_G32R32F              = 115,
    ZZ_FMT_A32B32G32R32F        = 116,

    ZZ_FMT_CxV8U8               = 117,


    ZZ_FMT_FORCE_DWORD          =0x7fffffff
} ZZ_FORMAT;

// do not mix the order. client uses it as integer. just add new
enum zz_collision_level {
	ZZ_CL_NONE					= 0x0,
	ZZ_CL_SPHERE				= 0x1,
	ZZ_CL_AABB					= 0x2,
	ZZ_CL_OBB					= 0x3,
	ZZ_CL_POLYGON				= 1 << 2,
	ZZ_CL_NOTMOVEABLE			= 1 << 3, 
	ZZ_CL_NOTPICKABLE			= 1 << 4,
    ZZ_CL_HEIGHTONLY            = 1 << 5,
    ZZ_CL_NOTCAMERACOLLISION    = 1 << 6,
};

#define ZZ_IS_SPHERE_LEVEL(L)			(((L) & 0x7) == ZZ_CL_SPHERE)
#define ZZ_IS_AABB_LEVEL(L)				(((L) & 0x7) == ZZ_CL_AABB)
#define ZZ_IS_OBB_LEVEL(L)				(((L) & 0x7) == ZZ_CL_OBB)
#define ZZ_IS_POLYGON_LEVEL(L)			(((L) & 0x7) == ZZ_CL_POLYGON)
#define ZZ_IS_MOVEABLE(L)				(!((L) & ZZ_CL_NOTMOVEABLE))
#define ZZ_IS_PICKABLE(L)				(!((L) & ZZ_CL_NOTPIKABLE))
#define ZZ_IS_NOTMOVEABLE(L)			((L) & ZZ_CL_NOTMOVEABLE)
#define ZZ_IS_NOTPICKABLE(L)			((L) & ZZ_CL_NOTPICKABLE)
#define ZZ_IS_HEIGHTONOY(L)             ((L) & ZZ_CL_HEIGHTONLY) 
#define ZZ_IS_NOTCAMERACOLLISION(L)    ((L) & ZZ_CL_NOTCAMERACOLLISION) 

#define ZZ_SCALE_IN			(0.01f)
#define ZZ_SCALE_OUT		(100.0f)
#define ZZ_XFORM_IN(X)		(ZZ_SCALE_IN*(X))
#define ZZ_XFORM_OUT(X)		(ZZ_SCALE_OUT*(X))

// To debug when resource file loading.
#define MAX_NUM_BONES 1000
#define MAX_NUM_DUMMIES 1000
#define MAX_NUM_VERTS 100000
#define MAX_NUM_FACES 100000

enum zz_glow_type {
	ZZ_GLOW_NONE					= 0, // do not use glow
	ZZ_GLOW_NOTSET				= 1, // not set yet. it is the visible's default setting. it does not affect material's glow state.
	ZZ_GLOW_SIMPLE				= 2, // simple color glow
	ZZ_GLOW_LIGHT					= 3, // lit color glow
	ZZ_GLOW_TEXTURE				= 4, // color x texture glow
	ZZ_GLOW_TEXTURE_LIGHT = 5, // lit color x texture glow
	ZZ_GLOW_ALPHA					= 6, // only alpha
};

#endif // __ZZ_TYPE_H__