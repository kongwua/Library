//
// Created by recatu on 2024/11/2.
//
//管理员-用户管理界面
#ifndef LIBRARY_USER_MANAGE_H
#define LIBRARY_USER_MANAGE_H

#include <QWidget>
#include <QStandardItemModel>
#include "Library.h"
class admin;//前向声明

using std::string;
QT_BEGIN_NAMESPACE
namespace Ui { class User_manage; }
QT_END_NAMESPACE

class User_manage : public QWidget {
Q_OBJECT

public:
    explicit User_manage(QWidget *parent = nullptr);

    ~User_manage() override;
    void displayUserData();//显示用户数据
    string getSelect();//获取选中的用户ID
    void displaySingleUserData(Node<UserInfo> *p);//显示单个用户数据
public slots:
    void on_addUser_btn_clicked();//添加账号
    void on_search_btn_clicked();//搜索
    void on_tableView_clicked(const QModelIndex &index);//单击选中某一行
    void on_tableView_doubleClicked();//双击某一行
    void on_userInfo_btn_clicked();//查看编辑用户信息

private:
    Ui::User_manage *ui;
    QStandardItemModel* userModel;
    admin* _admin;
};



#endif //LIBRARY_USER_MANAGE_H
