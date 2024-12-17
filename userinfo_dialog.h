//
// Created by recatu on 2024/11/24.
//

#ifndef LIBRARY_USERINFO_DIALOG_H
#define LIBRARY_USERINFO_DIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include "Library.h"
using std::string;

QT_BEGIN_NAMESPACE
namespace Ui { class userinfo_dialog; }
QT_END_NAMESPACE

class userinfo_dialog : public QDialog {
Q_OBJECT

public:
    explicit userinfo_dialog(QWidget *parent = nullptr,string _userID="");

    ~userinfo_dialog() override;
    bool check_user();
    void updateUser();
    void change_password(QString psw);//改变密码
    void initBookModel();//初始化书籍列表
    void displayBookTable();//显示书籍列表
    void appendOneBook(Node<BookInfo>* book);//添加一本书到模型
    void appendOneReserve(Node<BookInfo>* book);//添加一本预约书籍到模型
    string getSelect();//获取选中的书籍isbn
public slots:
    void buttonBox_accepted();//确认后更新用户信息
    void delete_btn_clicked();//删除用户信息
    void changePsw_btn_clicked();//修改密码
    void on_book_tableView_clicked(const QModelIndex &index);//单击书籍列表
    void on_returnBook_btn_clicked();//归还书籍
private:
    Ui::userinfo_dialog *ui;
    QStandardItemModel *bookModel;
    QStandardItemModel *reserveModel;
    Node<UserInfo>* user;
};


#endif //LIBRARY_USERINFO_DIALOG_H
