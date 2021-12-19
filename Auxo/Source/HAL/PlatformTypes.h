/*********************************************************
* Author :   xpin-ray
* Date   :   2021/12/19
* License:   Apache License 2.0
*********************************************************/
#pragma once
// ----------------
// windows platform
// ----------------
#if defined(_WIN64) || (_WIN32)
#include "HAL/Platform/WindowsPlatformTypes.h"
#endif

// ----------------------------------
// let these platform types to global
// ----------------------------------
using uint8     = FPlatformTypes::uint8;
using uint16    = FPlatformTypes::uint16;
using uint32    = FPlatformTypes::uint32;
using uint64    = FPlatformTypes::uint64;

using int8      = FPlatformTypes::int8;
using int16     = FPlatformTypes::int16;
using int32     = FPlatformTypes::int32;
using int64     = FPlatformTypes::int64;

using CHAR8     = FPlatformTypes::CHAR8;
using CHAR16    = FPlatformTypes::CHAR16;
using CHAR32    = FPlatformTypes::CHAR32;
using ANSICHAR  = FPlatformTypes::ANSICHAR;
using WIDECHAR  = FPlatformTypes::WIDECHAR;
using TCHAR     = FPlatformTypes::TCHAR;

using PTRINT    = FPlatformTypes::PTRINT;
using UPTRINT   = FPlatformTypes::UPTRINT;

using SIZE_T    = FPlatformTypes::SIZE_T;
using SSIZE_T   = FPlatformTypes::SSIZE_T;