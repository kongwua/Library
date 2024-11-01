//
// Created by recatu on 2024/10/31.
//
//数据库相关操作函数
#ifndef LIBRARY_DATABASE_H
#define LIBRARY_DATABASE_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>
class database {
    public:
    void create_database(QString db_name); //创建数据库
};


#endif //LIBRARY_DATABASE_H
