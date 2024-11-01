//
// Created by recatu on 2024/10/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_login.h" resolved
#include <QPluginLoader>
#include "login.h"
#include "ui_login.h"
#include "database.h"
#include "Library.h"

login::login(QWidget *parent) :
        QWidget(parent), ui(new Ui::login) {
    ui->setupUi(this);


    database::create_database("users.db");//创建名为users.db的数据库文件
    connect(ui->login_btn, &QPushButton::clicked, this,&login::user_login);//登录按钮点击事件
}

login::~login() {
    delete ui;
}

void login::user_login() {
    //登录事件处理
    //先获取输入的用户名和密码，在数据库中查询。若存在，则登录成功，跳转界面；若不存在，则提示错误信息。
    User user;
    user.id = ui->id_Ledit->text();
    user.psw = ui->psw_Ledit->text();
    if(database::chack_user(user)){
        QMessageBox::information(this,"登录成功","欢迎您，"+user.id+"！");
        //跳转界面
    }else{
        QMessageBox::warning(this,"登录失败","用户不存在或密码错误！");
    }
}