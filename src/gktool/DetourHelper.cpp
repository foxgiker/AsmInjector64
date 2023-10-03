//
// Created by c0518535x on 2023/9/14.
//

#include "DetourHelper.h"


DetourHelper::DetourHelper() {

}

void DetourHelper::attach(PVOID src, PVOID dest) {
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&src,dest);
    DetourTransactionCommit();
}

void DetourHelper::detach(PVOID src, PVOID dest) {
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&src,dest);
    DetourTransactionCommit();
}