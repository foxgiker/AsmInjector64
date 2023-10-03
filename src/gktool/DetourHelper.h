//
// Created by c0518535x on 2023/9/14.
//

#ifndef ASMINJECTOR_DETOURHELPER_H
#define ASMINJECTOR_DETOURHELPER_H

/*
 * 单例对象用于测试Detour库
 */
#include "windows.h"
#include "detours.h"




class DetourHelper {
private:
    DetourHelper();
public:
    DetourHelper(DetourHelper&& ) = delete;  // 删除移动构造函数
    DetourHelper(const DetourHelper& ) =delete;          // 删除复制构造函数

    DetourHelper& operator = (DetourHelper&& ) =delete;
    DetourHelper& operator = (const DetourHelper& ) = delete;  //删除移动赋值运算符

    static DetourHelper& instance(){
        static DetourHelper _instance;
        return _instance;
    }

    void attach(PVOID src,PVOID dest);
    void detach(PVOID src,PVOID dest);
};


#define DETOUR_ATTACH(src,dest) DetourHelper::instance().attach(src,dest)
#define DETOUR_DETACH(src,dest) DetourHelper::instance().detach(src,dest)

#endif //ASMINJECTOR_DETOURHELPER_H
