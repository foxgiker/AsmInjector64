//
// Created by c0518535x on 2023/9/8.
//

#ifndef ASMINJECTOR_MAIN_H
#define ASMINJECTOR_MAIN_H

#include <windows.h>
#include <Process.h>
#include <tlhelp32.h>
#include "DetourHelper.h"

HMODULE g_hDllModule = NULL;
HHOOK g_hHook = NULL;
DWORD g_targetProcessId = 0;

const char* g_target_exe = "gok.exe";


extern "C" __declspec(dllexport) bool setHook();
extern "C" __declspec(dllexport) bool unHook();
extern "C" __declspec(dllexport) bool isHooked();

void tourTargetProcess();
void detourTargetProcess();
static BOOL HookedTerminateProcess(HANDLE hProcess, UINT   uExitCode);
#endif //ASMINJECTOR_MAIN_H
