//
// Created by recatu on 2024/11/26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_bookinfo_dialog.h" resolved

#include "bookinfo_dialog.h"
#include "ui_bookinfo_dialog.h"
#include <QMessageBox>
#include <QStandardItem>

bookinfo_dialog::bookinfo_dialog(QWidget *parent,string _bookIsbn) :
        QDialog(parent), ui(new Ui::bookinfo_dialog) {
    ui->setupUi(this);
    userModel = new QStandardItemModel(this);
    reserveModel = new QStandardItemModel(this);
    ui->reader_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->reader_tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->reserve_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->reserve_tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    book = lib.findBookbyISBN(_bookIsbn);
    if(book){
        //搜索结果不为空
        displayUserData();
        ui->name_edit->setText(book->elem.name.data());
        ui->isbn_edit->setText(book->elem.isbn.data());
        ui->num_spinBox->setValue(book->elem.quantity);
        ui->price_doubleSpinBox->setValue(book->elem.price);
    } else{
        //搜索结果为空,添加图书信息
    }
}

bookinfo_dialog::~bookinfo_dialog() {
    delete ui;
}

void bookinfo_dialog::initUserTable() {
    //初始化用户表
    userModel->clear();
    userModel->setColumnCount(3);
    userModel->setHeaderData(0, Qt::Horizontal, "用户ID");
    userModel->setHeaderData(1, Qt::Horizontal, "借阅数量");
    userModel->setHeaderData(2, Qt::Horizontal, "预约数量");
    ui->reader_tableView->setModel(userModel);
    ui->reader_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->reader_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->reader_tableView->setAlternatingRowColors(true);

    reserveModel->clear();
    reserveModel->setColumnCount(3);
    reserveModel->setHeaderData(0, Qt::Horizontal, "用户ID");
    reserveModel->setHeaderData(1, Qt::Horizontal, "借阅数量");
    reserveModel->setHeaderData(2, Qt::Horizontal, "预约数量");
    ui->reserve_tableView->setModel(reserveModel);
    ui->reserve_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->reserve_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->reserve_tableView->setAlternatingRowColors(true);
}

void bookinfo_dialog::appendOneUser(Node<UserInfo> *p) {
    //向用户表中添加一行数据
    if(!p) return;
    QList<QStandardItem*> list;
    list << new QStandardItem(p->elem.ID.data())
         << new QStandardItem(QString::number(p->elem.books.size()))
         << new QStandardItem(QString::number(p->elem.reserveBooks.size()));
    userModel->appendRow(list);
}

void bookinfo_dialog::displayUserData() {
    //显示借阅者信息
    initUserTable();
    ui->num_label->setText("共借出"+QString::number(book->elem.readers.size())+"本书");
    for(auto p=book->elem.readers.begin();p!=book->elem.readers.end();p=p->next){
        appendOneUser(p->elem);
    }
    ui->reserve_lable->setText("共有"+QString::number(book->elem.reserveReaders.size())+"人预约");
    for(auto p = book->elem.reserveReaders.getFront();p!=nullptr;p=p->next){
        appendOneReserve(p->elem);
    }
}

void bookinfo_dialog::on_buttonBox_accepted() {
    //确认按钮槽函数
    if(checkBookInfo()){
        updateBookInfo();
        accept();
        QMessageBox::information(this, "提示", "图书信息修改成功！");
    }
}

void bookinfo_dialog::updateBookInfo() {
    //更新图书信息
    string name = ui->name_edit->text().toStdString();
    string isbn = ui->isbn_edit->text().toStdString();
    int num = ui->num_spinBox->value();
    auto price = static_cast<float>(ui->price_doubleSpinBox->value());
    if(book){
        //书籍存在，更新信息
        book->elem.name = name;
        book->elem.isbn = isbn;
        book->elem.quantity = num;
        book->elem.price = price;
    } else{
        //书籍不存在，添加新书
        book = lib.add(BookInfo(name,isbn,num,price));
    }

}

bool bookinfo_dialog::checkBookInfo() {
    //检查图书信息
    string name = ui->name_edit->text().toStdString();
    string isbn = ui->isbn_edit->text().toStdString();
    if ((name.empty() || isbn.empty())){
        QMessageBox::warning(this, "错误", "图书名称或ISBN不能为空！");
        return false;
    }
    auto Result = lib.findBookbyISBN(isbn);
    if (Result && Result != book){
        QMessageBox::warning(this, "错误", "该书号已存在！");
        return false;
    }
    return true;

}

void bookinfo_dialog::on_delete_btn_clicked() {
    //删除图书按钮
    if(!book){
        return;//书籍不存在
    }
    if((QMessageBox::question(this, "提示", "确认删除该书籍？"),
            QMessageBox::Yes|QMessageBox::No)==QMessageBox::No){
        return;
    }
    if(!lib.del(book)){
        if (QMessageBox::warning(this, tr("警告"),
                                 tr("还有 ") + QString::number(book->elem.readers.size())
                                 + tr(" 本书仍处于借出状态。要强制删除吗？"),
                                 QMessageBox::Ok | QMessageBox::Cancel)
            == QMessageBox::Cancel) {
            return;
    }
        lib.del(book, true);//强制删除
    }
    QMessageBox::information(this, "提示", "图书删除成功！");
    accept();

}

void bookinfo_dialog::on_borrowBook_btn_clicked() {
    //图书详细界面借书
    int res = lib.borrowBookByISBN(login_UserID,book->elem.isbn);
    if(res == 1){
        QMessageBox::warning(this,"警告","借阅失败");
    } else if(res == 2){
        QMessageBox::information(this,"提示","当前无剩余图书，已预约!");
    } else{QMessageBox::information(this,"提示",("借阅《" + tr(book->elem.name.data())+"》成功！"));}

    displayUserData();

}

void bookinfo_dialog::on_returnBook_btn_clicked() {
    //图书详细界面归还书
    if (lib.returnBookbyISBN(login_UserID,book->elem.isbn)){
        QMessageBox::information(this,"提示","你没有借阅这本书！");
        return;
    }
    displayUserData();
    QMessageBox::information(this,"提示",("还书《" + tr(book->elem.name.data())+"》成功！"));
}

void bookinfo_dialog::appendOneReserve(QNode<UserInfo> *p) {
    if(!p) return;
    QList<QStandardItem*> list;
    list << new QStandardItem(p->elem.ID.data())
         << new QStandardItem(QString::number(p->elem.books.size()))
         << new QStandardItem(QString::number(p->elem.reserveBooks.size()));
    reserveModel->appendRow(list);
}




