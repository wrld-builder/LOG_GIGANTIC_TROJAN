#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

#define DLL_EXPORT __declspec(dllexport)

extern "C"{
void DLL_EXPORT setClip(LPCSTR text);
LPCSTR DLL_EXPORT getClip();
void DLL_EXPORT loop();
}

#endif // __MAIN_H__
