#include "MemoryBase.h"

void* FUseSystemMallocForNew::operator new(SIZE_T Size)
{
    return FPlatformMemory::SystemMalloc(Size);
}

void* FUseSystemMallocForNew::operator new[](SIZE_T Size)
{
    return FPlatformMemory::SystemMalloc(Size);
}

void FUseSystemMallocForNew::operator delete(void* Ptr)
{
    return FPlatformMemory::SystemFree(Ptr);
}

void FUseSystemMallocForNew::operator delete[](void* Ptr)
{
    return FPlatformMemory::SystemFree(Ptr);
}