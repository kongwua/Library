//
// Created by recatu on 2024/11/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_admin.h" resolved

#include "admin.h"
#include "ui_admin.h"
#include "Library.h"


admin::admin(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::admin)
            ,m_user_manage(nullptr)
            ,m_book_manage(nullptr)
            ,m_borrow_manage(nullptr)
            ,m_borrow_record(nullptr)//页面指针初始化
{
    ui->setupUi(this);
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
            ui->stackedWidget->setCurrentIndex(0);//
            if (isAdmin){
                m_user_manage->displayUserData();
            } else{
                m_user_manage->displaySingleUserData(lib.findUser(login_UserID));
            }
            break;
        }
        if ("book_btn" == str){
            ui->stackedWidget->setCurrentIndex(1);//跳转到图书管理页面
            m_book_manage->displayBookData();
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

void admin::closeEvent(QCloseEvent *event) {
    //关闭窗口时，将链表内数据写入文件
    if(lib.writeUser(lib.userPath)||lib.writeBook(lib.bookPath)||lib.writeReserve(lib.reservePath)){
        QMessageBox::warning(this,"警告","数据写入失败！");
        return;
    }
    QMessageBox::information(this,"提示","数据已保存！");
    event->accept();
}

QStandardItemModel* admin::initUserModel(QStandardItemModel* userModel) {
    userModel->clear();
    userModel->setHorizontalHeaderLabels({"用户ID","借阅数量","预约数量","权限"});
}

void admin::displayUserData(QStandardItemModel* userModel) {
    initUserModel(userModel);
    for(auto p=lib.users.begin();p!=lib.users.end();p=p->next){
        appendOneUser(userModel,p);
    }

}

void admin::appendOneUser(QStandardItemModel *userModel, Node<UserInfo> *p) {
    if(!p) return;
    QList<QStandardItem*> list;
    list << new QStandardItem(p->elem.ID.data())
         << new QStandardItem(std::to_string(p->elem.books.size()).data())
         << new QStandardItem(std::to_string(p->elem.reserveBooks.size()).data())
         << new QStandardItem((p->elem.type)?"管理员":"普通用户");
    userModel->appendRow(list);
}

void admin::displayOneUser(QStandardItemModel *userModel, Node<UserInfo> *p) {
    initUserModel(userModel);
    appendOneUser(userModel,p);
}

QStandardItemModel *admin::initBookModel(QStandardItemModel *bookModel) {
    bookModel->clear();
    bookModel->setHorizontalHeaderLabels({"书名","书号","总数量","剩余数量","价格"});
    return bookModel;
}

void admin::displayBookData(QStandardItemModel *bookModel) {
    initBookModel(bookModel);
    for(auto p=lib.books.begin();p!=lib.books.end();p=p->next){
        appendOneBook(bookModel,p);
    }
}


void admin::appendOneBook(QStandardItemModel *bookModel, Node<BookInfo> *p) {
    if(!p) return;
    QList<QStandardItem*> list;
    list << new QStandardItem(p->elem.name.data())
         << new QStandardItem(p->elem.isbn.data())
         << new QStandardItem(std::to_string(p->elem.quantity).data())
         << new QStandardItem(std::to_string(p->elem.quantity-p->elem.readers.size()).data())
         << new QStandardItem(QString::number(p->elem.price));//保留两位小数
    bookModel->appendRow(list);
}

void admin::displayOneBook(QStandardItemModel *bookModel, Node<BookInfo> *p) {
    initBookModel(bookModel);
    appendOneBook(bookModel,p);

}


