//
// Created by recatu on 2024/10/31.
//
//登录界面

#ifndef LIBRARY_LOGIN_H
#define LIBRARY_LOGIN_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QWidget {
Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);

    ~login() override;

private:
    Ui::login *ui;
};


#endif //LIBRARY_LOGIN_H
