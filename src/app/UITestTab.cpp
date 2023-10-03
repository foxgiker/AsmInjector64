//
// Created by c0518535x on 2023/9/15.
//

#include "UITestTab.h"


UITestTab::UITestTab(QWidget *parent): QFrame(parent) {
    doLayout();
}

UITestTab::~UITestTab(){

}

void UITestTab::doLayout() {

    _main_layout  = new QGridLayout(this);

    _box_detour   = new QGroupBox(this);
    _box_detour->setTitle("Detour");
    _box_detour->setMinimumSize(WIDTH_GROUP_BOX,HEIGHT_GROUP_BOX);
    _box_detour->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    _btn_detour_attach = new QPushButton(_box_detour);
    _btn_detour_detach = new QPushButton(_box_detour);
    _btn_detour_attach->setText("拦截TerminateProcess");
    _btn_detour_detach->setText("放行TerminateProcess");
    connect(_btn_detour_attach,&QPushButton::clicked,this,[this](){
        _btn_detour_attach->setEnabled(false);
        _btn_detour_detach->setEnabled(true);
        DETOUR_ATTACH(TerminateProcess, HookedTerminateProcess);
    });
    connect(_btn_detour_detach,&QPushButton::clicked,this,[this]{
        _btn_detour_attach->setEnabled(true);
        _btn_detour_detach->setEnabled(false);
        DETOUR_DETACH(TerminateProcess, HookedTerminateProcess);
    });

    _box_detour_layout = new QVBoxLayout(_box_detour);
    _box_detour_layout->addWidget(_btn_detour_detach);
    _box_detour_layout->addWidget(_btn_detour_attach);
    _box_detour->setLayout(_box_detour_layout);

    _box_hook     = new QGroupBox(this);
    _box_hook->setTitle("Hook");
    _box_hook->setMinimumSize(WIDTH_GROUP_BOX,HEIGHT_GROUP_BOX);
    _box_hook->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    _box_hook_layout = new QVBoxLayout(_box_hook);
    _btn_hook = new QPushButton("hook",_box_hook);
    _btn_unhook = new QPushButton("unhook",_box_hook);
    connect(_btn_hook,&QPushButton::clicked,this,[this]{
        _btn_hook->setEnabled(false);
        _btn_unhook->setEnabled(true);
        setHook();
    });
    connect(_btn_unhook,&QPushButton::clicked,this,[this]{
        _btn_hook->setEnabled(true);
        _btn_unhook->setEnabled(false);
        unHook();
    });
    _box_hook_layout->addWidget(_btn_hook);
    _box_hook_layout->addWidget(_btn_unhook);
    _box_hook->setLayout(_box_hook_layout);


    _box_send_msg = new QGroupBox(this);
    _box_send_msg->setTitle("SendMessage");
    _box_send_msg->setMinimumSize(WIDTH_GROUP_BOX,HEIGHT_GROUP_BOX);
    _box_send_msg->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    _box_other    = new QGroupBox(this);
    _box_other->setTitle("其他");
    _box_other->setMinimumSize(WIDTH_GROUP_BOX,HEIGHT_GROUP_BOX);
    _box_other->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    _main_layout->addWidget(_box_detour,   0,0,1,1);
    _main_layout->addWidget(_box_hook,     0,1,1,1);
    _main_layout->addWidget(_box_send_msg, 0,2,1,1);
    _main_layout->addWidget(_box_other,    1,0,1,3);
    setLayout(_main_layout);
}

BOOL HookedTerminateProcess(HANDLE hProcess, UINT   uExitCode){
    MessageBoxW(NULL,L"错误",L"该进程受到法律保护！",MB_OK);
    return FALSE;
}