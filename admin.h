//
// Created by recatu on 2024/11/2.
//

#ifndef LIBRARY_ADMIN_H
#define LIBRARY_ADMIN_H

#include <QMainWindow>
#include <QWidget>
#include "Library.h"
#include "book_manage.h"    //图书管理界面
#include "user_manage.h"    //用户管理界面
#include "borrow_manage.h"  //借阅管理界面
#include "borrow_record.h" //借阅记录界面

QT_BEGIN_NAMESPACE
namespace Ui { class admin; }
QT_END_NAMESPACE

class admin : public QMainWindow {
Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    virtual void closeEvent(QCloseEvent *event);



    ~admin() override;
    void initUI();//初始化界面
    QStandardItemModel* initUserModel(QStandardItemModel* userModel); //初始化用户模型
    QStandardItemModel* initBookModel(QStandardItemModel* bookModel);//初始化书籍模型
    void displayUserData(QStandardItemModel* userModel); //显示用户信息
    void appendOneUser(QStandardItemModel* userModel,Node<UserInfo>* p); //添加一个用户到模型中
    void displayOneUser(QStandardItemModel* userModel,Node<UserInfo>* p); //显示一个用户信息
    void displayBookData(QStandardItemModel* bookModel);//显示图书信息
    void appendOneBook(QStandardItemModel* bookModel,Node<BookInfo>* p); //添加一个书籍到模型中
    void displayOneBook(QStandardItemModel* bookModel,Node<BookInfo>* p); //显示一个书籍信息
public slots:
    void menu_change(); //界面切换
private:
    Ui::admin *ui;
    User_manage *m_user_manage;
    Book_manage *m_book_manage;
    Borrow_manage *m_borrow_manage;
    Borrow_record *m_borrow_record;

};


#endif //LIBRARY_ADMIN_H
