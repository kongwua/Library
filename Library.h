//
// Created by recatu on 2024/11/1.
//
//用于存放用户和图书相关的类定义
#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H
#include "login.h"



class User{
    //用户类
public:

    QString id;//用户账号
    QString psw;//用户密码
    int type;//用户类型,0为管理员，1为学生

};

#endif //LIBRARY_LIBRARY_H
