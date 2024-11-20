#include <QApplication>
#include <QDir>
#include "Library.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
<<<<<<< Updated upstream
//    login w;//登录界面
//   w.show();
    admin w;//管理员界面
=======
    login w;//登录界面

//    admin ad;//管理员界面
>>>>>>> Stashed changes
    w.show();
    return QApplication::exec();
}
