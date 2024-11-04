//
// Created by recatu on 2024/11/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_User_manage.h" resolved

#include "user_manage.h"
#include "ui_User_manage.h"


User_manage::User_manage(QWidget *parent) :
        QWidget(parent), ui(new Ui::User_manage) {
    ui->setupUi(this);
<<<<<<< Updated upstream
=======
//    auto model = new QStandardItemModel(0, 2);
//    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);//设置表头宽度固定
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置表格不可编辑
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);//设置选择模式为单选
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选择行为为选择整行
//    model->setHorizontalHeaderLabels({"用户ID", "密码", "权限"});
//    model->appendRow({new QStandardItem("10001"), new QStandardItem("123456"), new QStandardItem("管理员")});
    DatabaseManager db;
    db.setupDatabaseAndModel(ui->tableView);
    connect(ui->search_line, &QLineEdit::returnPressed, this, &User_manage::on_search);
    //当搜索框内有内容再按下回车时，搜索并高亮显示
>>>>>>> Stashed changes
}

User_manage::~User_manage() {
    delete ui;
}

void User_manage::on_search() {

}