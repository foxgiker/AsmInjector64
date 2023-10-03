//
// Created by c0518535x on 2023/9/14.
//

#ifndef ASMINJECTOR_MAINUI_H
#define ASMINJECTOR_MAINUI_H

#include <QWidget>
#include <QObject>
#include <QMainWindow>
#include "UITestTab.h"

class MainUI: public QMainWindow{
    Q_OBJECT
private:
    UITestTab*            _testTab     =  nullptr;
    QHBoxLayout*          _main_layout = nullptr;
    void doLayout();
public:
    MainUI(QWidget *parent= nullptr);
    ~MainUI();
};


#endif //ASMINJECTOR_MAINUI_H
