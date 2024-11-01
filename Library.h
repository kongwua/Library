//
// Created by recatu on 2024/11/1.
//
//用于存放用户和图书相关的类定义
#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H
#include "login.h"

enum UserType{//用户类型枚举
    Admin,//管理员
    Student//学生
};

class User{
    //用户类
public:

private:
    QString id;//用户账号
    QString psw;//用户密码
    UserType type;//用户类型
};

#endif //LIBRARY_LIBRARY_H
