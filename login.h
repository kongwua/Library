//
// Created by recatu on 2024/10/31.
//
//��¼����

#ifndef LIBRARY_LOGIN_H
#define LIBRARY_LOGIN_H

#include <QWidget>
using std::string;

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QWidget {
Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    void first_longin();//�״ε�¼�����˺�����д���û�����
    ~login() override;
signals:
        void login_success();//��¼�ɹ��ź�
public slots:
    void user_login();//��¼�ۺ���
private:
    Ui::login *ui;
    string userID;
    string password;
};


#endif //LIBRARY_LOGIN_H
