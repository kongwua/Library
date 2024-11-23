#include <QApplication>
#include <QDir>
#include "Library.h"
Library lib;
string login_UserID;
bool isAdmin;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    login login_w;//登录界面


    if (lib.read("user.csv",
                 "book.csv")) {//读取用户信息和图书信息
        //首次登录
        login_w.first_longin();
    }
    admin w1;//管理员界面
    QObject::connect(&login_w,&login::login_success,[&](){
        //登录成功,切换界面
        login_w.close();
        w1.show();
    });
    login_w.show();


    return QApplication::exec();
}
