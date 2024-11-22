#include <QApplication>
#include <QDir>
#include "Library.h"
Library lib;
string login_UserID;
bool isAdmin;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    if (lib.read("user.csv",
                 "book.csv")) {//读取用户信息和图书信息
        login_UserID = "1234";//默认登录用户
        isAdmin = true;
    }
//    admin w;//管理员界面
    login w;//登录界面
    w.show();
    return QApplication::exec();
}
