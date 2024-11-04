//
// Created by recatu on 2024/11/2.
//
//管理员-用户管理界面
#ifndef LIBRARY_USER_MANAGE_H
#define LIBRARY_USER_MANAGE_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class User_manage; }
QT_END_NAMESPACE

class User_manage : public QWidget {
Q_OBJECT

public:
    explicit User_manage(QWidget *parent = nullptr);

    ~User_manage() override;
public slots:
    void on_search();//当搜索框内有内容再按下回车时，搜索并高亮显示
private:
    Ui::User_manage *ui;
};


#endif //LIBRARY_USER_MANAGE_H
