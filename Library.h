//
// Created by recatu on 2024/11/1.
//
//用于存放用户和图书相关的类定义
#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H
#include "login.h"
#include "admin.h"

struct USER_data{
    //用户信息结构
    QString ID;//用户ID
    QString password;//用户密码
    int book_borrow;//用户借阅的图书数量
};
struct USER_NODE{
    //用户节点结构
    USER_data data;
    USER_NODE *next;
};


#endif //LIBRARY_LIBRARY_H
