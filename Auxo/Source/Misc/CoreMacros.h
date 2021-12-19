/*********************************************************
* Author :   xpin-ray
* Date   :   2021/12/19
* License:   Apache License 2.0
*********************************************************/
#pragma once
// -----------------------------------------
// Date: 2021/12/19
// Desc: Only Support Windows64 Platfrom Now
// -----------------------------------------
#if defined(_WIN64)
    #ifdef AUXO_BUILD
        #define CORE_API __declspec(dllexport)
    #else
        #define CORE_API __declspec(dllimport)
    #endif
#else
    #error Unsupported Platform
#endif