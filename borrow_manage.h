//
// Created by recatu on 2024/11/2.
//
//管理员-借阅管理界面
#ifndef LIBRARY_BORROW_MANAGE_H
#define LIBRARY_BORROW_MANAGE_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Borrow_manage; }
QT_END_NAMESPACE

class Borrow_manage : public QWidget {
Q_OBJECT

public:
    explicit Borrow_manage(QWidget *parent = nullptr);

    ~Borrow_manage() override;

private:
    Ui::Borrow_manage *ui;
};


#endif //LIBRARY_BORROW_MANAGE_H
