//
// Created by recatu on 2024/11/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_User_manage.h" resolved


#include "user_manage.h"
#include "ui_User_manage.h"
#include "csv_function.h"

User_manage::User_manage(QWidget *parent) :
        QWidget(parent), ui(new Ui::User_manage) {
    ui->setupUi(this);

//    auto model = new QStandardItemModel(0, 2);
//    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);//设置表头宽度固定
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置表格不可编辑
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);//设置选择模式为单选
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选择行为为选择整行
//    model->setHorizontalHeaderLabels({"用户ID", "密码", "权限"});
//    model->appendRow({new QStandardItem("10001"), new QStandardItem("123456"), new QStandardItem("管理员")});


//    connect(ui->search_line, &QLineEdit::returnPressed, this, &User_manage::on_search);
    //当搜索框内有内容再按下回车时，搜索并高亮显示
    QStandardItemModel *model = createTablemodel();
    ui->tableView->setModel(model);

}

User_manage::~User_manage() {
    delete ui;
}

QStandardItemModel* User_manage::createTablemodel() {
    //读取csv文件,获取链表,创建表格模型,返回模型
    csv_User csv;
    csv.init_csv("user.csv");
    csv.read_csv();
    auto p = csv.get_user_head();
    p = p->next;
    QStandardItemModel *model = new QStandardItemModel();
    //设置表头
    model->setHorizontalHeaderLabels({"用户ID", "密码", "借阅数量","权限"});
    //遍历链表，添加数据到表格
    int row = 0;
    while (p) {
        model->setItem(row, 0, new QStandardItem(p->data.ID));
        model->setItem(row, 1, new QStandardItem(p->data.password));
        model->setItem(row, 2, new QStandardItem(QString::number(p->data.book_borrow)));
        model->setItem(row, 3, new QStandardItem(QString::number(p->data.user_type)));
        p = p->next;
        row++;
    }
    return model;

}
