#pragma once
#include <malloc.h>
#include "GenericPlatformMemory.h"

class FWindowsPlatformMemory :
    public FGenericPlatformMemory
{
public:
    static FORCEINLINE void* Malloc(SIZE_T Size)
    {
        return malloc(Size);
    }

    static FORCEINLINE void* Realloc(void* Ptr, SIZE_T Size)
    {
        return realloc(Ptr, Size);
    }

    static FORCEINLINE void Free(void* Ptr)
    {
        free(Ptr);
    }
};

using FPlatformMemory = FWindowsPlatformMemory;