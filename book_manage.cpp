//
// Created by recatu on 2024/11/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Book_manage.h" resolved

#include "book_manage.h"
#include "ui_Book_manage.h"


Book_manage::Book_manage(QWidget *parent) :
        QWidget(parent), ui(new Ui::Book_manage) {
    ui->setupUi(this);
}

Book_manage::~Book_manage() {
    delete ui;
}
