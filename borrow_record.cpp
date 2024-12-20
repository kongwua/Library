//
// Created by recatu on 2024/11/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Borrow_record.h" resolved

#include "borrow_record.h"
#include "ui_Borrow_record.h"
#include "Library.h"


Borrow_record::Borrow_record(QWidget *parent) :
        QWidget(parent), ui(new Ui::Borrow_record) {
    ui->setupUi(this);
    recordModel = new QStandardItemModel();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//设置表头宽度固定
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置表格不可编辑
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);//设置选择模式为单选
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选择行为为选择整行
    ui->dateEdit->setDate(lib.currentTime);
    ui->payFine_btn->setEnabled(false);//设置支付罚金按钮不可用
    connect(ui->dateEdit,&QDateEdit::dateChanged,this,[this]{
        updateRecord();
    });
    displayRecord();
}

Borrow_record::~Borrow_record() {
    delete ui;
}

void Borrow_record::initRecordModel() {
    //初始化记录模型
    recordModel->clear();
    recordModel->setHorizontalHeaderLabels({"借阅者ID","书名","书号","应还日期","已借天数","是否逾期"});
}

void Borrow_record::displayRecord() {
    //显示记录
    initRecordModel();
    int check = ui->checkBox->checkState();//是否只查看逾期记录
    ui->payFine_btn->setEnabled(false);//设置支付罚金按钮不可用
    for(auto p=lib.records.begin();p!=lib.records.end();p=p->next){
        if(check){
            if(p->elem.returnTime<lib.currentTime){
                appendOneRecord(p);//只显示逾期记录
            }
        } else {
            appendOneRecord(p);//显示全部记录
        }
    }
    ui->tableView->setModel(recordModel);
}

void Borrow_record::appendOneRecord(Node<RecordInfo> *p) {
    //添加一条记录到模型中
    if(!p) return;
    int check = ui->checkBox->checkState();//是否只查看逾期记录
    if(check && p->elem.returnTime>lib.currentTime) return;//只显示逾期记录
    auto book = lib.findBookbyISBN(p->elem.bookISBN);
    int date = p->elem.returnTime.addDays(-lib.days).daysTo(lib.currentTime);//计算已借天数
    QList<QStandardItem*> list;
    list<< new QStandardItem(p->elem.readerID.data())
       << new QStandardItem(book->elem.name.data())
       << new QStandardItem(book->elem.isbn.data())
       << new QStandardItem(p->elem.returnTime.toString("yyyy-MM-dd"))
       << new QStandardItem(QString::number(date))
       << new QStandardItem((p->elem.returnTime<lib.currentTime)? "已逾期" : "无");
    recordModel->appendRow(list);
}

void Borrow_record::displayOneRecord(Node<RecordInfo> *p) {
    //显示一条记录
    initRecordModel();
    appendOneRecord(p);
    ui->tableView->setModel(recordModel);
}

void Borrow_record::updateRecord() {
    //更新记录信息和用户信息
    lib.currentTime = ui->dateEdit->date();//更新当前时间
    qDebug()<<"修改当前时间为"<<lib.currentTime.toString("yyyy-MM-dd");
    clearFine();//清空罚金
    for(auto p=lib.records.begin();p!=lib.records.end();p=p->next){
        if(p->elem.returnTime < lib.currentTime){
            auto user = lib.findUser(p->elem.readerID);
            auto book = lib.findBookbyISBN(p->elem.bookISBN);
            user->elem.fine += book->elem.price;
        }
    }
    displayRecord();
}

void Borrow_record::clearFine() {
    //清空罚金
    for(auto p = lib.users.begin();p!=lib.users.end();p=p->next){
        p->elem.fine = 0.0;
    }
}

void Borrow_record::on_payFine_btn_clicked() {
    //支付罚金按钮事件
    string readerID = getSelect();
    auto user = lib.findUser(readerID);
    if((QMessageBox::question(this,"缴纳罚款","该用户有"+QString::number(user->elem.books.size())+"本书未还\n"+
         "是否缴纳"+QString::number(user->elem.fine)+"元罚金并强制归还书籍？"),
        QMessageBox::Yes|QMessageBox::No) == QMessageBox::No){
            return;
    } else{
        //先还书后再清空罚款
        qDebug()<<"开始缴纳罚款";
        for(auto p=user->elem.books.begin();p!=user->elem.books.end();p=p->next){
            if(lib.returnBookbyISBN(user->elem.ID,p->elem->elem.isbn)){
                qDebug()<<"交款还书失败";
                break;
            }
            if(!lib.delRecord(user->elem.ID,p->elem->elem.isbn)){
                qDebug()<<"删除记录失败";
                break;
            }
        }
        user->elem.fine = 0.0;
    }
    displayRecord();
}

string Borrow_record::getSelect() {
    //获取选中的记录的用户id
    int row = ui->tableView->currentIndex().row();
    QAbstractItemModel* itemModel = ui->tableView->model();
    QModelIndex index = itemModel->index(row, 0);
    QVariant data = itemModel->data(index);
    return data.toString().toStdString();//返回选中的记录的用户id
}

void Borrow_record::on_tableView_clicked(const QModelIndex &index){
    //单击表格事件
    ui->payFine_btn->setEnabled(true);
}

void Borrow_record::on_search_btn_clicked() {
    //搜索按钮事件
    int check = ui->checkBox->checkState();//是否只查看逾期记录
    QString query = ui->searchEdit->text();
    if(query.isEmpty()){
        displayRecord();
        return;
    }
    if(ui->comboBox->currentIndex() == 0){
        //按读者ID搜索
        displayUserList(query);
    } else if(ui->comboBox->currentIndex() == 1){
        //按书号搜索
        displayBookList(query);
    } else{
        //按书名搜索
        displayBookNameList(query);
    }
}

void Borrow_record::displayUserList(QString query) {
    //显示用户列表
    initRecordModel();
    for(auto p=lib.records.begin();p!=lib.records.end();p=p->next){
        if(p->elem.readerID == query.toStdString()){
            appendOneRecord(p);
        }
    }
}

void Borrow_record::displayBookNameList(QString query) {
    //显示书名列表
    initRecordModel();
    for(auto p=lib.records.begin();p!=lib.records.end();p=p->next){
        auto book = lib.findBookbyISBN(p->elem.bookISBN);
        if(book->elem.name.find(query.toStdString())!=string::npos){
            appendOneRecord(p);
        }
    }
}

void Borrow_record::displayBookList(QString query) {
    //显示书号列表
    initRecordModel();
    for(auto p=lib.records.begin();p!=lib.records.end();p=p->next){
        if(p->elem.bookISBN == query.toStdString()){
            appendOneRecord(p);
        }
    }
}
