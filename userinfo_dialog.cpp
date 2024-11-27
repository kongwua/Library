//
// Created by recatu on 2024/11/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_userinfo_dialog.h" resolved

#include "userinfo_dialog.h"
#include "ui_userinfo_dialog.h"
#include "change_psw_dialog.h"

userinfo_dialog::userinfo_dialog(QWidget *parent,string userID) :
        QDialog(parent), ui(new Ui::userinfo_dialog) {
    ui->setupUi(this);

    bookModel = new QStandardItemModel();//书籍模型

    ui->book_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->book_tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->reserve_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->reserve_tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(ui->buttonBox,&QDialogButtonBox::accepted,this,&userinfo_dialog::buttonBox_accepted);
    connect(ui->delete_btn,&QPushButton::clicked,this,&userinfo_dialog::delete_btn_clicked);
    connect(ui->psw_btn,&QPushButton::clicked,this,&userinfo_dialog::changePsw_btn_clicked);
    user = lib.findUser(userID);
    if(userID.empty()){
        //添加用户操作
        ui->delete_btn->setDisabled(true);
        ui->borrow_btn->setDisabled(true);
        ui->return_btn->setDisabled(true);
        ui->psw_btn->setDisabled(true);
        ui->psw_btn->setToolTip("保存用户后修改密码");
    } else{
            //显示用户信息
            displayBookTable();//显示书籍表格
            ui->lineEdit->setText(user->elem.ID.data());
            ui->admin_checkBox->setChecked(user->elem.type);//管理员权限
    }

}

userinfo_dialog::~userinfo_dialog() {
    delete ui;
}

bool userinfo_dialog::check_user() {
    //检查增加的用户信息是否合法
    string id = ui->lineEdit->text().toStdString();
    if(id.empty()){
        QMessageBox::warning(this, "错误", "用户ID不能为空！");
        return false;
    }
    auto result = lib.findUser(id);
    if(result && result!=user){
        QMessageBox::warning(this, "错误", "用户ID已存在！");
        return false;
    }
    return true;
}

void userinfo_dialog::updateUser() {
    //更新用户信息
    string id = ui->lineEdit->text().toStdString();
    int type = ui->admin_checkBox->isChecked();
    if(user){
        user->elem.ID = id;
        user->elem.type = type;
    } else{
        user = lib.add(UserInfo(id,type));
    }
}

void userinfo_dialog::buttonBox_accepted() {
    //保存用户信息
    if(check_user()){
        updateUser();
        accept();
    }
}

void userinfo_dialog::delete_btn_clicked() {
    //删除用户
    if(!user) {//如果用户不存在
        return;
    }
    if(QMessageBox::warning(this, "警告", "确认删除用户吗？",
                            QMessageBox::Yes | QMessageBox::No, QMessageBox::No)
                            ==QMessageBox::Cancel){
        return;//取消删除
    }
    if(!lib.del(user)){
        if(QMessageBox::warning(this, "警告", "该用户还有书为归还，是否删除？",
                             QMessageBox::Yes | QMessageBox::No, QMessageBox::No)
                             ==QMessageBox::No){ return;}
        lib.del(user,true);
    }
    accept();
}

void userinfo_dialog::change_password(QString psw) {
    //修改密码
    if(user){
        user->elem.password = psw.toStdString();
    }
    QMessageBox::information(this, "提示", "密码修改成功！");
}

void userinfo_dialog::changePsw_btn_clicked() {
    //修改密码按钮点击事件
    change_psw_dialog psw_dialog(this,user);
    connect(&psw_dialog, &change_psw_dialog::changePsw, this,&userinfo_dialog::change_password);
    psw_dialog.exec();
}

void userinfo_dialog::initBookModel() {
    //初始化书籍模型
    ui->return_btn->setDisabled(true);
    bookModel->clear();
    bookModel->setColumnCount(5);
    bookModel->setHeaderData(0, Qt::Horizontal, "书名");
    bookModel->setHeaderData(1, Qt::Horizontal, "书号");
    bookModel->setHeaderData(2, Qt::Horizontal, "总数量");
    bookModel->setHeaderData(3, Qt::Horizontal, "剩余数量");
    bookModel->setHeaderData(4, Qt::Horizontal, "价格");
    ui->book_tableView->setModel(bookModel);
    ui->book_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->book_tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->book_tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->book_tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);

    ui->book_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->book_tableView->setAlternatingRowColors(true);
}

void userinfo_dialog::displayBookTable() {
    //显示书籍表格
    initBookModel();
    ui->num_label->setText(tr("已借") + QString::number(user->elem.books.size())+tr("本"));
    for(auto p = user->elem.books.begin(); p!=user->elem.books.end(); p=p->next){
        appendOneBook(p->elem);
    }
}

void userinfo_dialog::appendOneBook(Node<BookInfo> *book) {
    //添加一本书到模型
    if(!book){
        return;
    }
    QList<QStandardItem*> list;
    list << new QStandardItem(book->elem.name.data())
         << new QStandardItem(book->elem.isbn.data())
         << new QStandardItem(std::to_string(book->elem.quantity).data())
         << new QStandardItem(std::to_string(book->elem.quantity-book->elem.readers.size()).data())
         << new QStandardItem(std::to_string(book->elem.price).data());
    bookModel->appendRow(list);
}


