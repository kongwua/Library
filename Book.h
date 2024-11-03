//
// Created by recatu on 2024/11/2.
//
//图书类的声明，含链表结构体定义和相关函数
#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H
#include <iostream>
#include <string>
#include <malloc.h>
using namespace std;

class BOOK {
    //图书类
public:
    struct book_node {
        string book_name; //图书名称
        string author; //作者
        string publisher; //出版社
        string publish_date; //出版日期
        string ISBN; //ISBN号
        float price; //价格
        int stock_num;//总库存量
        int borrow_num; //借阅数量
        book_node *next; //指向下一个图书节点的指针
    };
public:
    BOOK(); //构造函数,对链表进行初始化
    ~BOOK(); //析构函数,释放链表内存

protected:
    book_node *head; //链表头指针
};


#endif //LIBRARY_BOOK_H
