//
// Created by c0518535x on 2023/9/14.
//

#include "MainUI.h"



MainUI::MainUI(QWidget* parent): QMainWindow(parent){

    doLayout();
}

MainUI::~MainUI(){

}

void MainUI::doLayout() {
    _testTab = new UITestTab(this);
    setCentralWidget(_testTab);
    resize(600,400);
}