//
// Created by recatu on 2024/11/2.
//
//管理员-用户管理界面
#ifndef LIBRARY_USER_MANAGE_H
#define LIBRARY_USER_MANAGE_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class User_manage; }
QT_END_NAMESPACE

class User_manage : public QWidget {
Q_OBJECT

public:
    explicit User_manage(QWidget *parent = nullptr);

    ~User_manage() override;

private:
    Ui::User_manage *ui;
};


#endif //LIBRARY_USER_MANAGE_H
