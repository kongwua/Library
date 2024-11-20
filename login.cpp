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


<<<<<<< Updated upstream
    database::create_database("users.db");//创建名为users的数据库文件
    connect(ui->login_btn, &QPushButton::clicked, this,&login::user_login);//登录按钮点击事件
    connect(ui->register_btn, &QPushButton::clicked, this,&login::user_register);//注册按钮点击事件
=======
    csv_User csv;
    csv.init_csv("user.csv");//初始化用户信息文件
    connect(ui->login_btn, &QPushButton::clicked, this, &login::user_login);//登录按钮点击事件
>>>>>>> Stashed changes
}

login::~login() {
    delete ui;
}

void login::user_login() {
    //登录事件处理
<<<<<<< Updated upstream
    //先获取输入的用户名和密码，在数据库中查询。若存在，则登录成功，跳转界面；若不存在，则提示错误信息。
    User user;
    user.id = ui->id_Ledit->text();
    user.psw = ui->psw_Ledit->text();
    if(user.id.isEmpty() || user.psw.isEmpty()){
        QMessageBox::warning(this,"登录失败","用户ID或密码不能为空！");
=======
    //先获取输入的用户名和密码，在用户链表中查询。若存在，则登录成功，跳转界面；若不存在，则提示错误信息。
    QString userid = ui->id_Ledit->text();
    QString password = ui->psw_Ledit->text();
    //如果输入为空，则提示错误信息
    if(userid.isEmpty() || password.isEmpty()){
        QMessageBox::warning(this, "登录失败", "用户名或密码不能为空！");
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
void login::user_register() {
    //注册事件处理
    //先获取用户id和密码，检查是否符合要求，然后将用户信息写入数据库。该方法只能注册学生用户
    User user;
    user.id = ui->id_Ledit->text();
    user.psw = ui->psw_Ledit->text();
    user.type = 1;//学生用户

    if(user.id.isEmpty() || user.psw.isEmpty()){
        QMessageBox::warning(this,"注册失败","用户ID或密码不能为空！");
        return;
    }
    if (user.id.length()>30 || user.psw.length()>30){
        QMessageBox::warning(this,"注册失败","用户ID或密码过长！应小于30个字符！");
        return;
    }
    if(database::insert_user(user)){//注册成功
        QMessageBox::information(this,"注册成功","恭喜您，注册成功！");
    } else{
        QMessageBox::warning(this,"注册失败","用户ID已存在！");
    }
}
=======
>>>>>>> Stashed changes
