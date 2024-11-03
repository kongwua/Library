//
// Created by recatu on 2024/11/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_admin.h" resolved

#include "admin.h"
#include "ui_admin.h"


admin::admin(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::admin)
            ,m_user_manage(nullptr)
            ,m_book_manage(nullptr)
            ,m_borrow_manage(nullptr)
            ,m_borrow_record(nullptr)//页面指针初始化
{    ui->setupUi(this);
    initUI();
}

admin::~admin() {
    delete ui;
}

void admin::initUI() {
    m_user_manage = new User_manage(this);
    m_book_manage = new Book_manage(this);
    m_borrow_manage = new Borrow_manage(this);
    m_borrow_record = new Borrow_record(this);
    ui->stackedWidget->addWidget(m_user_manage);
    ui->stackedWidget->addWidget(m_book_manage);
    ui->stackedWidget->addWidget(m_borrow_manage);
    ui->stackedWidget->addWidget(m_borrow_record);

    ui->stackedWidget->setCurrentIndex(0);
    auto l = ui->tool->children();//获取tool的子控件

    for(auto i:l){
        if (i->objectName().contains("btn")){
            connect(static_cast<QPushButton*>(i), &QPushButton::clicked, this, &admin::menu_change);
            //创建信号槽
        }
    }
}

void admin::menu_change(){
    //获取发送信号的控件的名字
    auto str = sender()->objectName();
    do {
        if ("user_btn" == str){
            ui->stackedWidget->setCurrentIndex(0);//跳转到用户管理页面
            break;
        }
        if ("book_btn" == str){
            ui->stackedWidget->setCurrentIndex(1);//跳转到图书管理页面
            break;
        }
        if ("borrow_btn" == str){
            ui->stackedWidget->setCurrentIndex(2);//跳转到借阅管理页面
            break;
        }
        if ("borrow_record_btn" == str){
            ui->stackedWidget->setCurrentIndex(3);//跳转到借阅记录页面
            break;
        }
    } while (false);
}