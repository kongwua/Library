//
// Created by recatu on 2024/11/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Book_manage.h" resolved

#include "book_manage.h"
#include "ui_Book_manage.h"
#include "Library.h"
#include "admin.h"
#include "bookinfo_dialog.h"
Book_manage::Book_manage(QWidget *parent) :
        QWidget(parent), ui(new Ui::Book_manage),_admin(qobject_cast<admin*>(parent)) {
    ui->setupUi(this);
    bookModel = new QStandardItemModel();
    ui->book_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//设置表头宽度固定
    ui->book_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置表格不可编辑
    ui->book_tableView->setSelectionMode(QAbstractItemView::SingleSelection);//设置选择模式为单选
    ui->book_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选择行为为选择整行
    ui->bookInfo_btn->setDisabled(true);//设置详细信息按钮不可用
    ui->borrowBook_btn->setDisabled(true);//设置借阅按钮不可用
    ui->returnBook_btn->setDisabled(true);//设置还书按钮不可用
    ui->bookName_radioButton->setChecked(true);//默认按书名搜索
    if (!isAdmin){
        ui->addBook_btn->setHidden(true);//非管理员禁止添加书籍
    }
    displayBookData();
}

Book_manage::~Book_manage() {
    delete ui;
}

void Book_manage::displayBookData() {
    _admin->displayBookData(bookModel);
    ui->book_tableView->setModel(bookModel);
    ui->bookInfo_btn->setDisabled(true);//设置详细信息按钮不可用
    ui->borrowBook_btn->setDisabled(true);//设置借阅按钮不可用
    ui->returnBook_btn->setDisabled(true);//设置还书按钮不可用
}

void Book_manage::displaySingleBookData(Node<BookInfo> *p) {
    _admin->displayOneBook(bookModel,p);
}

string Book_manage::getSelect() {
    int row = ui->book_tableView->currentIndex().row();
    QAbstractItemModel* itemModel = ui->book_tableView->model();
    QModelIndex itemIndex = itemModel->index(row,1);//获取第二列的索引
    QVariant data = itemModel->data(itemIndex);
    return data.toString().toStdString();//返回选中的书号
}

void Book_manage::on_addBook_btn_clicked() {
    //添加图书
    bookinfo_dialog dialog(this);
    dialog.exec();
    ui->search_btn->click();
}

void Book_manage::on_search_btn_clicked() {
    //搜索图书 分为据书名模糊搜索和书号精确搜索
    QString query = ui->SearchEdit->text();
    if (query.isEmpty()){
        displayBookData();//如果搜索框为空，则显示全部图书
        return;
    }
    if(ui->bookName_radioButton->isChecked()){
        //按书名模糊搜索
        displayBookList(lib.fuzzyFindBook(query.toStdString()));
    } else{
        //按书号精确搜索
        auto p = lib.findBookbyISBN(query.toStdString());
        displaySingleBookData(p);
    }
}

void Book_manage::displayBookList(List<Node<BookInfo>*> list) {
    //显示图书列表
    _admin->initBookModel(bookModel);
    for(auto p=list.begin();p!=list.end();p=p->next){
        _admin->appendOneBook(bookModel,p->elem);
    }
}

void Book_manage::on_book_tableView_clicked(const QModelIndex &index) {
    //单击获取当前选中的图书信息
    //设置详细信息按钮可用
    ui->bookInfo_btn->setDisabled(false);
    ui->borrowBook_btn->setDisabled(false);
    ui->returnBook_btn->setDisabled(false);
}

void Book_manage::on_bookInfo_btn_clicked() {
    //显示对话框显示当前选中的图书信息
    string bookIsbn = getSelect();
    bookinfo_dialog dialog(this,bookIsbn);
    dialog.exec();
    ui->search_btn->click();
}

void Book_manage::on_book_tableView_doubleClicked() {
    //双击编辑图书信息
    ui->bookInfo_btn->click();
}

void Book_manage::on_borrowBook_btn_clicked() {
    //借阅图书
    string bookIsbn = getSelect();
    if(lib.borrowBookByISBN(login_UserID, bookIsbn)){
        QMessageBox::information(this,"提示","该书无剩余，已为您预约。当有空余时自动帮你借阅！");
        displayBookData();
        return;
    }
    displayBookData();
    QMessageBox::information(this,"提示",("借阅《" + tr(lib.findBookbyISBN(bookIsbn)->elem.name.data())+"》成功！"));
}

void Book_manage::on_returnBook_btn_clicked() {
    //还书
    string bookIsbn = getSelect();
    if(lib.returnBookbyISBN(login_UserID, bookIsbn)){
        QMessageBox::information(this,"提示","你没有借阅这本书！");
        return;
    }
    displayBookData();
    QMessageBox::information(this,"提示",("还书《" + tr(lib.findBookbyISBN(bookIsbn)->elem.name.data())+"》成功！"));
}
