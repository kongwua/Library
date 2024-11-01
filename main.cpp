#include <QApplication>
#include <QDir>
#include "login.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    login w;
    w.show();
    return QApplication::exec();
}
