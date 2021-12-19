/*********************************************************
* Author :   xpin-ray
* Date   :   2021/12/19
* License:   Apache License 2.0
*********************************************************/
#pragma once
#include <iostream>
// ----------------
// windows platform
// ----------------
#if defined(_WIN64) || (_WIN32)
#include "GenericPlatform/Memory/WindowsPlatformMemory.h"
#endif