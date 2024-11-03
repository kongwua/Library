//
// Created by recatu on 2024/11/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Borrow_manage.h" resolved

#include "borrow_manage.h"
#include "ui_Borrow_manage.h"


Borrow_manage::Borrow_manage(QWidget *parent) :
        QWidget(parent), ui(new Ui::Borrow_manage) {
    ui->setupUi(this);
}

Borrow_manage::~Borrow_manage() {
    delete ui;
}
