//
// Created by recatu on 2024/11/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_User_manage.h" resolved

#include "user_manage.h"
#include "ui_User_manage.h"


User_manage::User_manage(QWidget *parent) :
        QWidget(parent), ui(new Ui::User_manage) {
    ui->setupUi(this);
}

User_manage::~User_manage() {
    delete ui;
}
