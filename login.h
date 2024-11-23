//
// Created by recatu on 2024/10/31.
//
//登录界面

#ifndef LIBRARY_LOGIN_H
#define LIBRARY_LOGIN_H

#include <QWidget>
using std::string;

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QWidget {
Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    void first_longin();//首次登录，将账号密码写入用户链表
    ~login() override;
signals:
        void login_success();//登录成功信号
public slots:
    void user_login();//登录槽函数
private:
    Ui::login *ui;
    string userID;
    string password;
};


#endif //LIBRARY_LOGIN_H
