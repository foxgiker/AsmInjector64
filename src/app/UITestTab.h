//
// Created by c0518535x on 2023/9/15.
//

#ifndef ASMINJECTOR_UITESTTAB_H
#define ASMINJECTOR_UITESTTAB_H
#include "windows.h"
#include <QObject>
#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QFrame>
#include <QPushButton>

#include "DetourHelper.h"
#include "tou.hpp"

static int WIDTH_GROUP_BOX  = 150;
static int HEIGHT_GROUP_BOX = 50;

static BOOL HookedTerminateProcess( HANDLE hProcess, UINT   uExitCode);

class UITestTab:public QFrame {
    Q_OBJECT
private:
    QGridLayout*        _main_layout            = nullptr;
    QGroupBox*          _box_detour             = nullptr;
    QVBoxLayout*        _box_detour_layout      = nullptr;
    QPushButton*        _btn_detour_attach      = nullptr;
    QPushButton*        _btn_detour_detach      = nullptr;

    QGroupBox*          _box_hook               = nullptr;
    QVBoxLayout*        _box_hook_layout        = nullptr;
    QPushButton*        _btn_hook               = nullptr;
    QPushButton*        _btn_unhook             = nullptr;

    QGroupBox*          _box_send_msg           = nullptr;
    QGroupBox*          _box_other              = nullptr;

    void doLayout();
public:
    UITestTab(QWidget* parent = nullptr);
    ~UITestTab();
};


#endif //ASMINJECTOR_UITESTTAB_H
