//
// Created by recatu on 2024/10/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_login.h" resolved
#include <QPluginLoader>
#include <QMessageBox>
#include "login.h"
#include "ui_login.h"
#include "Library.h"



login::login(QWidget *parent) :
        QWidget(parent), ui(new Ui::login) {
    ui->setupUi(this);

//    csv_User csv;
//    csv.init_csv("user.csv");//初始化用户信息文件
    connect(ui->login_btn, &QPushButton::clicked, this, &login::user_login);//登录按钮点击事件

}

login::~login() {
    delete ui;
}

void login::user_login() {
    //登录事件处理
    userID = ui->id_Ledit->text().toStdString();
    password = ui->psw_Ledit->text().toStdString();
    if(userID.empty() || password.empty()){
        QMessageBox::warning(this, "登录失败", "用户名或密码不能为空！");
        return;
    }
    if (lib.login(userID, password)) {
        login_UserID = lib.findUser(userID)->elem.ID;
        QMessageBox::information(this, "登录成功", "欢迎您，"+QString::fromStdString(userID)+"！");
       emit login_success();//登录成功信号
    } else {
        QMessageBox::warning(this, tr("提示"), tr("用户名或密码错误。"), QMessageBox::Ok);
    }
}

void login::first_longin() {
    //第一次登录，创建默认管理员账户
    UserInfo firstUser("1234","1234",1);
    lib.users.append(firstUser);
    login_UserID = firstUser.ID;
    isAdmin = true;
}

