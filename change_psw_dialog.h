//
// Created by recatu on 2024/11/24.
//

#ifndef LIBRARY_CHANGE_PSW_DIALOG_H
#define LIBRARY_CHANGE_PSW_DIALOG_H

#include <QDialog>
#include "Library.h"

QT_BEGIN_NAMESPACE
namespace Ui { class change_psw_dialog; }
QT_END_NAMESPACE

class change_psw_dialog : public QDialog {
Q_OBJECT

public:
    explicit change_psw_dialog(QWidget *parent = nullptr,Node<UserInfo> *_user = nullptr);

    ~change_psw_dialog() override;
signals:
    void changePsw(QString);//发送修改密码信号
public slots:
    void on_buttonBox_accepted();//确认修改密码槽函数
private:
    Ui::change_psw_dialog *ui;
    Node<UserInfo>* user;

    bool check_psw();//检查密码是否正确
};


#endif //LIBRARY_CHANGE_PSW_DIALOG_H
