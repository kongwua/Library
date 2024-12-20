#include <QApplication>
#include <QDir>
#include "admin.h"
#include "login.h"
Library lib;
string login_UserID;
bool isAdmin;


int main(int argc, char *argv[]) {
    qDebug()<<lib.currentTime;
    QApplication a(argc, argv);
    login login_w;//登录界面
    admin admin_w;//管理员界面
    QObject::connect(&login_w,&login::login_success,[&](){
        //登录成功,关闭登录界面
        login_w.close();
        admin_w.initUI();//必须使用initUI()初始化界面后才show
        admin_w.show();
        return QApplication::exec();
    });
    if (lib.read("user.csv",
                 "book.csv","reserve.csv","record.csv")) {//读取用户信息和图书信息
        //首次登录
        login_w.first_longin();
    }
    login_w.show();
    return QApplication::exec();
}
