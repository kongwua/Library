//
// Created by recatu on 2024/11/4.
//

#ifndef LIBRARY_CSV_FUNCTION_H
#define LIBRARY_CSV_FUNCTION_H
#include "Library.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

#define DIVIDER "," //设置分隔符为逗号

class csv_User {
    //用户csv读写操作类
public:
    csv_User() {
        user_head = nullptr;
        user_num = 0;
    }

    ~csv_User() {

    }

    QFile* init_csv(QString csv_name); //初始化csv文件,返回文件指针
    USER_NODE* init_user_list(); //初始化用户链表,返回链表头指针
    bool read_csv(); //读取csv文件内容到链表中
//    bool write_csv(); //将链表内容写入csv文件中
    bool check_user(QString user_id,QString password); //检查用户和密码是否正确
//    bool insert_user(USER_NODE *user); //插入用户
//    bool delete_user(QString user_id); //删除用户
private:
    QFile *csv_file; //csv文件指针
    USER_NODE *user_head; //用户链表头指针
    int user_num; //用户数量
};


#endif //LIBRARY_CSV_FUNCTION_H
