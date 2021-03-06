/*********************************************************
* Author :   xpin-ray
* Date   :   2021/12/19
* License:   Apache License 2.0
*********************************************************/

#pragma once
#include "GenericPlatformTypes.h"

// ----------------------
// windows platform types
// ----------------------
struct FWindowsPlatformTypes : FGenericPlatformTypes
{
#ifdef _WIN64
    using SIZE_T    = unsigned __int64;
    using SSIZE_T   = __int64;
#else
    using SIZE_T    = unsigned long;
    using SSIZE_T   = long;
#endif
};

#define CDECL	        __cdecl
#define STDCALL		    __stdcall
#define FORCEINLINE     __forceinline
#define FORCENOINLINE   __declspec(noinline)

// export windows platform types
using FPlatformTypes = FWindowsPlatformTypes;