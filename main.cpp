#include <QApplication>
#include <QDir>
#include "Library.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

//    login w;//登录界面

    admin w;//管理员界面

    w.show();
    return QApplication::exec();
}
