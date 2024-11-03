//
// Created by recatu on 2024/11/2.
//
//管理员-图书管理界面
#ifndef LIBRARY_BOOK_MANAGE_H
#define LIBRARY_BOOK_MANAGE_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Book_manage; }
QT_END_NAMESPACE

class Book_manage : public QWidget {
Q_OBJECT

public:
    explicit Book_manage(QWidget *parent = nullptr);

    ~Book_manage() override;

private:
    Ui::Book_manage *ui;
};


#endif //LIBRARY_BOOK_MANAGE_H
