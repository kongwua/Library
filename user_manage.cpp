//
// Created by recatu on 2024/11/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_User_manage.h" resolved


#include "user_manage.h"
#include "ui_User_manage.h"
#include "Library.h"
#include "admin.h"
#include "userinfo_dialog.h"
#include <QString>

User_manage::User_manage(QWidget *parent) :
        QWidget(parent), ui(new Ui::User_manage),_admin(qobject_cast<admin*>(parent)) {
    ui->setupUi(this);
    userModel = new QStandardItemModel();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//设置表头宽度固定
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置表格不可编辑
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);//设置选择模式为单选
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选择行为为选择整行
    ui->userInfo_btn->setDisabled(true);//设置按钮不可用
    displayUserData();
    if(login_UserID.empty()){
        return;
    }
    if(!lib.isAdmin(lib.findUser(login_UserID))){
        isAdmin = false;//非管理员，禁止修改
        ui->addUser_btn->setHidden(true);//隐藏添加用户按钮
        ui->search_btn->setHidden(true);//隐藏搜索按钮
        ui->search_line->setHidden(true);//隐藏搜索框
        userModel->clear();
        displaySingleUserData(lib.findUser(login_UserID));
    }else{
        isAdmin = true;
    };

}

User_manage::~User_manage() {
    delete ui;
}

void User_manage::displayUserData() {
    //显示用户数据

    _admin->displayUserData(userModel);
    ui->tableView->setModel(userModel);
}

void User_manage::on_addUser_btn_clicked() {
    //添加账号，槽函数
    userinfo_dialog dialog(this);
    dialog.exec();
    displayUserData();//刷新用户数据
    ui->userInfo_btn->setDisabled(true);//设置按钮不可用
}



string User_manage::getSelect() {
    int row = ui->tableView->currentIndex().row();
    QAbstractItemModel* itemModel = ui->tableView->model();//获取表格模型
    QModelIndex itemIndex = itemModel->index(row, 0);//获取当前行的第一列索引
    QVariant data = itemModel->data(itemIndex);//获取当前行的第一列数据

    return data.toString().toStdString();//返回选择的ID
}

void User_manage::on_tableView_clicked(const QModelIndex &index) {
    //单击表格行
    ui->userInfo_btn->setEnabled(true);//设置查看用户信息按钮可用
}

void User_manage::on_tableView_doubleClicked() {
    //双击表格行
    ui->userInfo_btn->click();
}

void User_manage::on_userInfo_btn_clicked() {
    //查看用户信息按钮槽函数
     string userID = getSelect();
     userinfo_dialog dialog(this, userID);
     dialog.exec();
     //点击搜索按钮
     ui->search_btn->click();
    ui->userInfo_btn->setDisabled(true);//设置按钮不可用
}

void User_manage::displaySingleUserData(Node<UserInfo> *p) {
    //显示单个用户数据
    _admin->displayOneUser(userModel,p);
}

void User_manage::on_search_btn_clicked() {
    //搜索按钮槽函数
    QString query = ui->search_line->text();
    ui->userInfo_btn->setDisabled(true);//设置按钮不可用
    if(query.isEmpty()){
        if (isAdmin){
            displayUserData();
        } else{
            displaySingleUserData(lib.findUser(login_UserID));
        }
        return;
    }
    displaySingleUserData(lib.findUser(query.toStdString()));

}

