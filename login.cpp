//
// Created by recatu on 2024/10/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_login.h" resolved
#include <QPluginLoader>
#include <QMessageBox>
#include "login.h"
#include "ui_login.h"
#include "Library.h"
#include "csv_function.h"


login::login(QWidget *parent) :
        QWidget(parent), ui(new Ui::login) {
    ui->setupUi(this);

    csv_User csv;
    csv.init_csv("user.csv");//初始化用户信息文件
    connect(ui->login_btn, &QPushButton::clicked, this, &login::user_login);//登录按钮点击事件

}

login::~login() {
    delete ui;
}

void login::user_login() {
    //登录事件处理

    //先获取输入的用户名和密码，在用户链表中查询。若存在，则登录成功，跳转界面；若不存在，则提示错误信息。
    QString userid = ui->id_Ledit->text();
    QString password = ui->psw_Ledit->text();
    //如果输入为空，则提示错误信息
    if(userid.isEmpty() || password.isEmpty()){
        QMessageBox::warning(this, "登录失败", "用户名或密码不能为空！");

        return;
    }
    csv_User csv;
    csv.init_csv("user.csv");//初始化用户信息文件
    csv.init_user_list();//初始化用户链表
    csv.read_csv();
    if(csv.check_user(userid,password)){
       QMessageBox::information(this, "登录成功", "欢迎您，"+userid+"！");
    } else{
        QMessageBox::warning(this, "登录失败", "用户名或密码错误！");
    }

}

