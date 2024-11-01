//
// Created by recatu on 2024/10/31.
//

#include "database.h"



void database::create_database(QString db_name) {
    //创建并初始化数据库
    QSqlDatabase db;
    qDebug() << "数据库驱动:"<<QSqlDatabase::drivers();
    if (QSqlDatabase::contains(db_name)){
        db = QSqlDatabase::database(db_name);//如果数据库已经存在，则直接使用该数据库
    } else{
        db = QSqlDatabase::addDatabase("QSQLITE");//创建sqlite数据库
    }
        db.setDatabaseName(db_name);//设置数据库名称
    if(!db.open()){
        qDebug() << "数据库打开错误: " << db.lastError().text();
    } else{
//        qDebug() << "数据库打开成功";
    }
}
