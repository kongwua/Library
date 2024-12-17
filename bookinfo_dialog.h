//
// Created by recatu on 2024/11/26.
//

#ifndef LIBRARY_BOOKINFO_DIALOG_H
#define LIBRARY_BOOKINFO_DIALOG_H
#include "Library.h"
#include <QDialog>
#include <QStandardItemModel>


QT_BEGIN_NAMESPACE
namespace Ui { class bookinfo_dialog; }
QT_END_NAMESPACE

class bookinfo_dialog : public QDialog {
Q_OBJECT

public:
    explicit bookinfo_dialog(QWidget *parent = nullptr,string _bookIsbn = "");

    ~bookinfo_dialog() override;
    void initUserTable();//初始化借阅用户表
    void appendOneUser(Node<UserInfo>* p);//添加单个用户到模型
    void appendOneReserve(QNode<UserInfo>* p);//添加单个预约用户到模型
    void displayUserData();//显示借阅者信息
    void updateBookInfo();//更新书籍信息
    bool checkBookInfo();//检查书籍信息是否合法

public slots:
    void  on_buttonBox_accepted();
    void on_delete_btn_clicked();//删除按钮
    void on_borrowBook_btn_clicked();//借阅按钮
    void on_returnBook_btn_clicked();//归还按钮
private:
    Ui::bookinfo_dialog *ui;
    QStandardItemModel* userModel;//借阅用户模型
    QStandardItemModel* reserveModel;//预约用户模型
    Node<BookInfo>* book;
};


#endif //LIBRARY_BOOKINFO_DIALOG_H
