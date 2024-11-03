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
#include <QTableView>
#include <QSqlTableModel>

#include "Library.h"
class database {
    public:
    static void create_database(QString db_name); //创建数据库
    static void create_user_table();//创建用户表格
    static bool chack_user(User user);//验证用户
    static bool insert_user(User user);//插入用户
};

class DatabaseManager : public QObject
{
Q_OBJECT

public:
    explicit DatabaseManager(QObject *parent = nullptr) : QObject(parent) {}

    void setupDatabaseAndModel(QTableView *tableView)
    {
        // 连接到SQLite数据库
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("users.db");


        if (!db.open()) {
            qDebug() << "无法打开数据库:" << db.lastError().text();
            return;
        }
        QSqlQuery query(db);
        if (!query.exec("SELECT * FROM user_table")) {
            qDebug() << "SQL查询失败:" << query.lastError().text();
            return;
        }
        // 创建一个QSqlTableModel
        QSqlTableModel *model = new QSqlTableModel(nullptr, db);
        model->setTable("user_table");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit); // 设置编辑策略

        // 选择所有数据
        if (!model->select()) {
            qDebug() << "无法选择数据:" << model->lastError().text();
            return;
        }

        // 将模型设置到QTableView中
        tableView->setModel(model);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // 禁止编辑
        tableView->show();
    }
};

#endif //LIBRARY_DATABASE_H
