//
// Created by recatu on 2024/11/2.
//
//管理员-借阅记录界面
#ifndef LIBRARY_BORROW_RECORD_H
#define LIBRARY_BORROW_RECORD_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Borrow_record; }
QT_END_NAMESPACE

class Borrow_record : public QWidget {
Q_OBJECT

public:
    explicit Borrow_record(QWidget *parent = nullptr);

    ~Borrow_record() override;

private:
    Ui::Borrow_record *ui;
};


#endif //LIBRARY_BORROW_RECORD_H
