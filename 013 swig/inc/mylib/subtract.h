#ifndef __SUBTRACT_H__
#define __SUBTRACT_H__

#ifdef _WIN32
    #ifdef DLL_EXPORT
        #define DLL_API __declspec(dllexport)
    #else
        #define DLL_API __declspec(dllimport)
    #endif
#else
    #define DLL_API
#endif

#ifdef __cplusplus
extern "C"
{
#endif

DLL_API int subtract(int a, int b);

#ifdef __cplusplus
}
#endif

#endif