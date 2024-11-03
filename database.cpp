//
// Created by recatu on 2024/10/31.
//

#include "database.h"



void database::create_database(QString db_name) {
    //创建并初始化数据库
    QSqlDatabase db;
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
    database::create_user_table();//创建用户表格
}

void database::create_user_table() {
    //创建用户表格
    QSqlDatabase db = QSqlDatabase::database(QString("users.db"));//打开用户数据库
    QSqlQuery query(db);//创建查询对象
    if (query.exec(QString("select * from user_table"))) {
//        qDebug() << "用户表格已存在";
    } else {
        QString cmd = "create table user_table(id varchar(30) primary key, psw varchar(30),type int)";
        //通过执行SQL命令创建表格
        if (query.exec(cmd)) {
            qDebug() << "用户表格创建成功";
        } else {
            qDebug() << "用户表格创建失败: " << query.lastError().text();
        }
    }
    //查找表格中是否有初始管理员账号
    QString id = "1234";
    QString psw = "1234";
    int type = 0;
    query.exec(QString("select * from user_table where id='%1' and psw='%2' and type='%3'").arg(id)
                       .arg(psw).arg(type));
    if (query.next()) {
//        qDebug() << "初始管理员账号已存在";
    } else {
        //如果没有初始管理员账号，则插入初始管理员账号
        QSqlQuery insert_query;
        insert_query.prepare("insert into user_table(id, psw, type) values(:id, :psw, :type)");
        insert_query.bindValue(":id", id);
        insert_query.bindValue(":psw", psw);
        insert_query.bindValue(":type", type);

        if (insert_query.exec()) {
//            qDebug() << "初始管理员账号插入成功";
        } else {
            qDebug() << "插入失败:" << insert_query.lastError().text();
        }

    }
}

bool database::chack_user(User user) {
    //检查用户名和密码是否在数据库中存在

    QSqlDatabase db = QSqlDatabase::database(QString("users.db"));//打开用户数据库
    QSqlQuery query(db);//创建查询对象
    query.exec(QString("select * from user_table where id='%1' and psw='%2'").arg(user.id).arg(user.psw));
    if (query.next()) {
//        qDebug() << "用户名和密码正确";
        user.type = query.value("type").toInt();
        qDebug() << "用户类型：" << user.type;
        return true;
    } else {
//        qDebug() << "用户名或密码错误";
        return false;
    }
}

bool database::insert_user(User user) {
    //插入用户信息到数据库
    QSqlDatabase db = QSqlDatabase::database(QString("users.db"));//打开用户数据库
    QSqlQuery query(db);//创建查询对象
    query.prepare("insert into user_table(id, psw, type) values(:id, :psw, :type)");
    query.bindValue(":id", user.id);
    query.bindValue(":psw", user.psw);
    query.bindValue(":type", user.type);
    if (query.exec()) {
//        qDebug() << "用户信息插入成功";
        return true;
    } else{
        qDebug() << "插入失败:" << query.lastError().text();
        return false;
    }

}