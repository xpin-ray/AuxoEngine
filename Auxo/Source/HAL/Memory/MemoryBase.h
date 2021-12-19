/*********************************************************
* Author :   xpin-ray
* Date   :   2021/12/19
* License:   Apache License 2.0
*********************************************************/
#pragma once
#include "Misc/CoreMacros.h"
#include "HAL/PlatformMemory.h"

enum 
{ 
    DEFAULT_ALIGNMENT   = 0,
    MIN_ALIGNMENT       = 8
};

class CORE_API FUseSystemMallocForNew
{
    // override operator when use system allocator
    void* operator new(SIZE_T Size);
    // override operator when use system allocator
    void* operator new[](SIZE_T Size);
    // override operator when use system allocator
    void operator delete(void* Ptr);
    // override operator when use system allocator
    void operator delete[](void* Ptr);
};

class CORE_API FMalloc :
    public FUseSystemMallocForNew
{
    // malloc
    virtual void* Malloc(SIZE_T Count, uint32 Alignment = DEFAULT_ALIGNMENT) = 0;
    // realooc
    virtual void* Realloc(void* Original, SIZE_T Count, 
        uint32 Alignment = DEFAULT_ALIGNMENT) = 0;
    // free
    virtual void Free(void* Original) = 0;
};