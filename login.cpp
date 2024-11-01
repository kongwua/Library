//
// Created by recatu on 2024/10/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_login.h" resolved
#include <QPluginLoader>
#include "login.h"
#include "ui_login.h"
#include "database.h"

login::login(QWidget *parent) :
        QWidget(parent), ui(new Ui::login) {
    ui->setupUi(this);
    QString path = QDir::currentPath();
    QApplication::addLibraryPath(path + "/plugins");
    QPluginLoader loader(path+QString("/plugins/sqldrivers/qsqlite.dll"));

    database db;
    db.create_database("users.db");//创建名为users.db的数据库文件
}

login::~login() {
    delete ui;
}
