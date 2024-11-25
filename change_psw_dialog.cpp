//
// Created by recatu on 2024/11/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_change_psw_dialog.h" resolved

#include "change_psw_dialog.h"
#include "ui_change_psw_dialog.h"


change_psw_dialog::change_psw_dialog(QWidget *parent,Node<UserInfo> *_user) :
        QDialog(parent), ui(new Ui::change_psw_dialog), user(_user) {
    ui->setupUi(this);
    if(isAdmin){
        ui->old_psw_edit->setHidden(true);
        ui->label->setHidden(true);
    }
}

change_psw_dialog::~change_psw_dialog() {
    delete ui;
}

bool change_psw_dialog::check_psw() {
    //检查密码是否正确
    string real_psw = user->elem.password;
    QString old_psw = ui->old_psw_edit->text();

    return real_psw == old_psw.toStdString();
}

void change_psw_dialog::on_buttonBox_accepted() {
    //修改密码
    if (isAdmin){
        emit changePsw(ui->new_psw_edit->text());//管理员修改密码
    }else{
        if(check_psw()){
            emit changePsw(ui->new_psw_edit->text());//修改密码
        } else{
            QMessageBox::warning(this, "警告", "旧密码错误！");
        }
    }
    accept();
}
