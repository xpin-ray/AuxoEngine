/*********************************************************
* Author :   xpin-ray
* Date   :   2021/12/19
* License:   Apache License 2.0
*********************************************************/
#pragma once
#include <intrin.h>

// here is nop because the vs debugger has a bug
#define PLATFORM_BREAK { __nop(), __debugbreak(); }

#define AUXO_RUNTIME_ASSERT(EXPR, ...) if(!EXPR) PLATFORM_BREAK else { }

// only debug mode, the AE_DEBUG_ASSERT will run
#if defined(AUXO_DEBUG) || (AUXO_BUILD)
    #define AUXO_DEBUG_ASSERT(EXPR, ...) AUXO_RUNTIME_ASSERT(EXPR)
#else
    #define AUXO_DEBUG_ASSERT(EXPR, TIPS)
#endif

#define checkf(EXPR, ...) AUXO_RUNTIME_ASSERT(EXPR)