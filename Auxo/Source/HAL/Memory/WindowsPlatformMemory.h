/*********************************************************
* Author :   xpin-ray
* Date   :   2021/12/19
* License:   Apache License 2.0
*********************************************************/
#pragma once
#include <malloc.h>
#include "GenericPlatformMemory.h"

class FWindowsPlatformMemory :
    public FGenericPlatformMemory
{
public:
    static FORCEINLINE void* SystemMalloc(SIZE_T Size)
    {
        return ::malloc(Size);
    }

    static FORCEINLINE void* SystemRealloc(void* Ptr, SIZE_T Size)
    {
        return ::realloc(Ptr, Size);
    }

    static FORCEINLINE void SystemFree(void* Ptr)
    {
        ::free(Ptr);
    }
};

using FPlatformMemory = FWindowsPlatformMemory;