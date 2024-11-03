//
// Created by recatu on 2024/11/2.
//

#include "Book.h"

BOOK::BOOK() {
    //类的构造函数，初始化链表
    head = new book_node;//创建头结点
    head->book_name = "";
    head->author = "";
    head->publisher = "";
    head->publish_date = "";
    head->price = 0.0;
    head->stock_num = 0;
    head->borrow_num = 0;
    //头结点不存储数据
    head->next = NULL;
}

BOOK::~BOOK() {
    //类的析构函数，释放链表
    book_node *p = head;//头结点空间也要被释放
    book_node *temp = NULL;
    while (p!= NULL) {
        temp = p;
        p = p->next;
        delete temp;//释放结点
    }
}

