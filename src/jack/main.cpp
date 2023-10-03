//
// Created by c0518535x on 2023/9/8.
//

#include "main.h"



BOOL WINAPI DllMain (HMODULE  hModule, DWORD reason, LPVOID lpReserved)
{
    switch (reason)
    {
        case DLL_PROCESS_ATTACH:
            g_hDllModule = hModule;
            tourTargetProcess();
            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_PROCESS_DETACH:
            break;
        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE;
}

void tourTargetProcess(){
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (Process32First(snapshot, &entry) == TRUE){
        while (Process32Next(snapshot, &entry) == TRUE){
            if (_stricmp(entry.szExeFile, g_target_exe) == 0){
                g_targetProcessId = entry.th32ProcessID;
                DETOUR_ATTACH(TerminateProcess, HookedTerminateProcess);
                break;
            }
        }
    }
    CloseHandle(snapshot);
}

void detourTargetProcess(){
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (Process32First(snapshot, &entry) == TRUE){
        while (Process32Next(snapshot, &entry) == TRUE){
            if (_stricmp(entry.szExeFile, g_target_exe) == 0){
                g_targetProcessId = entry.th32ProcessID;
                DETOUR_DETACH(TerminateProcess, HookedTerminateProcess);
                break;
            }
        }
    }
    CloseHandle(snapshot);
}


BOOL HookedTerminateProcess(HANDLE hProcess, UINT   uExitCode){

    MessageBoxW(NULL,L"该进程受到保护",L"FBI Warning",MB_OK);
    return FALSE;
}

// 钩子回调函数
LRESULT GetMsgProc(int code,WPARAM wParam,LPARAM lParam)
{
    return CallNextHookEx(g_hHook, code, wParam, lParam);
}





bool setHook(){
    if (NULL == g_hHook)
    {
        g_hHook = SetWindowsHookExW(WH_GETMESSAGE,
                                    GetMsgProc,         // 回调函数
                                    g_hDllModule,      // 如果dwThreadId 指定了一个当前进程创建的线程并且hook过程在当前进程内，那么这个参数就必须设置为NULL
                                    0);           // 0 代表所有的线程
        return NULL == g_hHook;
    }else{
        return true;
    }
}

bool unHook(){
    if (g_hHook)
    {
        BOOL bRet = UnhookWindowsHookEx(g_hHook);
        if(bRet){
            g_hHook = NULL;
            detourTargetProcess();
        }
        return bRet;
    }
    return false;
}

bool isHooked(){
    return g_hHook? true: false;
}