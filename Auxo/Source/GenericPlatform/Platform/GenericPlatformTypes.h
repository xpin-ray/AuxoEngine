/*********************************************************
* Author :   xpin-ray
* Date   :   2021/12/19
* License:   Apache License 2.0
*********************************************************/
#pragma once
// ----------------------------------------
// setting up the pointer size integer type
// ----------------------------------------
// select int pointer type
template<typename T32BITS, typename T64BITS, int Size>
struct TSelectIntPointerType
{
    // do nothing
};

// select 4-byte int pointer type
template<typename T32BITS, typename T64BITS>
struct TSelectIntPointerType<typename T32BITS, typename T64BITS, 4>
{
    using Type = T32BITS;
};


// select 8-byte int pointer type
template<typename T32BITS, typename T64BITS>
struct TSelectIntPointerType<typename T32BITS, typename T64BITS, 8>
{
    using Type = T64BITS;
};

// ---------------------------
// a generic platform type def
// ---------------------------
struct FGenericPlatformTypes
{
    // unsigned int
    using uint8     = unsigned char;
    using uint16    = unsigned short int;
    using uint32    = unsigned int;
    using uint64    = unsigned long long;

    // signed int
    using int8      = signed char;
    using int16     = signed short int;
    using int32     = signed int;
    using int64     = signed long long;

    // character
    using CHAR8     = uint8;
    using CHAR16    = uint16;
    using CHAR32    = uint32;
    using ANSICHAR  = char;
    using WIDECHAR  = wchar_t;

    // select int pointer type for generic platform
    using UPTRINT   = TSelectIntPointerType<uint32, uint64, sizeof(void*)>::Type;
    using PTRINT    = TSelectIntPointerType<int32, int64, sizeof(void*)>::Type;

    using SIZE_T    = UPTRINT;
    using SSIZE_T   = PTRINT;

#if defined(_UNICODE) || (UNICODE)
    #if !defined(TEXT)
        #define TEXT(STR) L ## STR
    #endif
        using TCHAR = WIDECHAR;
    #else
        using TCHAR = ANSICHAR;
#endif
};