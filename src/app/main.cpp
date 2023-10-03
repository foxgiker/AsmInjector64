#include <iostream>


extern "C" long asmTest( long, long,long);
extern "C" void callPrint();
extern "C" void reverseStr(char*);

#include <QApplication>
#include "MainUI.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainUI app;
    app.show();
    return a.exec();
    return 0;
}
