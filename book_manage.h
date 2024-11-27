//
// Created by recatu on 2024/11/2.
//
//管理员-图书管理界面
#ifndef LIBRARY_BOOK_MANAGE_H
#define LIBRARY_BOOK_MANAGE_H

#include <QWidget>
#include <QStandardItemModel>
#include "Library.h"
class admin;
QT_BEGIN_NAMESPACE
namespace Ui { class Book_manage; }
QT_END_NAMESPACE

class Book_manage : public QWidget {
Q_OBJECT

public:
    explicit Book_manage(QWidget *parent = nullptr);

    ~Book_manage() override;
    void displayBookData();//显示图书数据
    string getSelect();//获取选中的图书书号
    void displaySingleBookData(Node<BookInfo> *p);//显示单个图书数据
    void displayBookList(List<Node<BookInfo>*> list);//显示多本图书

public slots:
    void on_addBook_btn_clicked();//添加图书槽函数
    void on_search_btn_clicked();//搜索图书槽函数
    void on_book_tableView_clicked(const QModelIndex &index);//表格单击槽函数
    void on_book_tableView_doubleClicked();//表格双击槽函数
    void on_bookInfo_btn_clicked();//图书详细信息按钮
    void on_borrowBook_btn_clicked();//借阅图书
    void on_returnBook_btn_clicked();//归还图书
private:
    Ui::Book_manage *ui;
    QStandardItemModel *bookModel;
    admin *_admin;
};


#endif //LIBRARY_BOOK_MANAGE_H
