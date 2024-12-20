//
// Created by recatu on 2024/11/2.
//
//管理员-借阅记录界面(仅管理员可见)
#ifndef LIBRARY_BORROW_RECORD_H
#define LIBRARY_BORROW_RECORD_H

#include <QWidget>
#include <QStandardItemModel>
#include "Library.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Borrow_record; }
QT_END_NAMESPACE

class Borrow_record : public QWidget {
Q_OBJECT

public:
    explicit Borrow_record(QWidget *parent = nullptr);

    ~Borrow_record() override;
    void initRecordModel();//初始化记录模型
    void displayRecord();//显示记录
    void displayOneRecord(Node<RecordInfo> *p);//显示一条记录
    void appendOneRecord(Node<RecordInfo> *p);//添加一条记录到模型中
    void clearFine();//清空罚款
    void updateRecord(); //时间变化后更新用户罚款
    string getSelect(); //获取选中的记录的用户id
    void displayUserList(QString query);//显示记录中某用户的所有借阅记录
    void displayBookNameList(QString query);//显示记录中某书名的所有借阅记录
    void displayBookList(QString query);//显示记录中某书号的所有借阅记录
public slots:
    void on_tableView_clicked(const QModelIndex &index);// 表格点击事件
    void on_payFine_btn_clicked();//缴纳罚款按钮点击事件
    void on_search_btn_clicked(); // 搜索按钮点击事件
private:
    Ui::Borrow_record *ui;
    QStandardItemModel *recordModel;

};


#endif //LIBRARY_BORROW_RECORD_H
