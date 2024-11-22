//
// Created by recatu on 2024/11/4.
//

#include "csv_function.h"

QFile* csv_User::init_csv(QString csv_name) {
    //初始化csv文件,如果文件不存在则创建,返回文件指针
    auto *file = new QFile(csv_name);
    //检查文件是否存在
    if (!file->exists()) {
        //文件不存在，创建文件
        qDebug() << "文件不存在，创建文件"<<csv_name;
        //写入初始管理员账号和密码
        file->open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(file);
        out << "1234" <<DIVIDER<< "1234" <<DIVIDER<< "0" <<DIVIDER<<"1"<<"\n"<< Qt::endl;//初始管理员账号为1234 密码为1234
    }
    csv_file = file;
    return file;
}

USER_NODE* csv_User::init_user_list() {
    //创建链表头结点，并返回头指针
   auto *head = new USER_NODE;
    if (head == nullptr) return nullptr;
    head->next = nullptr;
    head->data.ID = "NULL";
    head->data.password = "NULL";
    head->data.book_borrow = 0;//初始化数据
    user_head = head;//保存头指针
    return head;

}

bool csv_User::read_csv() {
    //读取csv文件，并创建链表
    if(!csv_file->open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "文件打开失败";
        return false;
    }
    if(user_head == nullptr){
        qDebug() << "链表为空，打开失败";
        return false;
    }
    QTextStream in(csv_file);

    auto *p = user_head;//找到链表头指针
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();//读取一行数据
        if (line.isEmpty()) continue;//跳过空行

        QStringList fields = line.split(DIVIDER);//以DIVIDER分割数据
        //遍历每一行数据，将其添加到链表中
        auto *new_node = new USER_NODE;//创建新节点
        new_node->data.ID = fields.at(0);
        new_node->data.password = fields.at(1);
        new_node->data.book_borrow = fields.at(2).toInt();
        new_node->data.user_type = fields.at(3).toInt();
        new_node->next = nullptr;
        p->next = new_node;//将新节点链接到链表
        p = new_node;//更新指针
    }
    return true;
}

bool csv_User::check_user(QString user_id, QString password) {
    //检查用户是否存在，存在返回true，不存在返回false
    auto *p = user_head;
    if (p == nullptr) return false;
    p = p->next;
    while (p != nullptr) {
        //遍历链表，查找用户
        if (p->data.ID == user_id && p->data.password == password) {
            return true;
        }
        p = p->next;
    }
    return false;
}




