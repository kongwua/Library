//
// Created by recatu on 2024/11/2.
//

#ifndef LIBRARY_ADMIN_H
#define LIBRARY_ADMIN_H

#include <QMainWindow>
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

    ~admin() override;
    void initUI();//初始化界面
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
