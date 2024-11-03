//
// Created by recatu on 2024/11/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Borrow_record.h" resolved

#include "borrow_record.h"
#include "ui_Borrow_record.h"


Borrow_record::Borrow_record(QWidget *parent) :
        QWidget(parent), ui(new Ui::Borrow_record) {
    ui->setupUi(this);
}

Borrow_record::~Borrow_record() {
    delete ui;
}
