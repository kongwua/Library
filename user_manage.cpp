//
// Created by recatu on 2024/11/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_User_manage.h" resolved


#include "user_manage.h"
#include "ui_User_manage.h"
#include "Library.h"

User_manage::User_manage(QWidget *parent) :
        QWidget(parent), ui(new Ui::User_manage) {
    ui->setupUi(this);
    userModel = new QStandardItemModel();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//设置表头宽度固定
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置表格不可编辑
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);//设置选择模式为单选
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选择行为为选择整行

    displayUserData();


}

User_manage::~User_manage() {
    delete ui;
}



void User_manage::initModel() {
    //初始化表格模型
    userModel->clear();
    userModel->setHorizontalHeaderLabels({"用户ID","借阅数量","预约数量","权限"});
    ui->tableView->setModel(userModel);
}

void User_manage::displayUserData() {
    //显示用户数据
    initModel();
    for(auto p=lib.users.begin();p!=lib.users.end();p=p->next){
        if(!p) return;
        QList<QStandardItem*> list;
        list << new QStandardItem(p->elem.ID.data())
             << new QStandardItem(std::to_string(p->elem.books.size()).data())
             << new QStandardItem(std::to_string(p->elem.reserveISBN.size()).data())
             << new QStandardItem((std::to_string(p->elem.type).data()?"管理员":"普通用户"));
        userModel->appendRow(list);
    }

}

