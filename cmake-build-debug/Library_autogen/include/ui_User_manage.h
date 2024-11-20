/********************************************************************************
** Form generated from reading UI file 'user_manage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_MANAGE_H
#define UI_USER_MANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_User_manage
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *search_line;
    QPushButton *add_user;
    QPushButton *delete_user;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QLabel *label_3;

    void setupUi(QWidget *User_manage)
    {
        if (User_manage->objectName().isEmpty())
            User_manage->setObjectName("User_manage");
        User_manage->resize(704, 502);
        gridLayout_2 = new QGridLayout(User_manage);
        gridLayout_2->setObjectName("gridLayout_2");
        label_2 = new QLabel(User_manage);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        widget = new QWidget(User_manage);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        search_line = new QLineEdit(widget);
        search_line->setObjectName("search_line");

        gridLayout->addWidget(search_line, 0, 1, 1, 1);

        add_user = new QPushButton(widget);
        add_user->setObjectName("add_user");

        gridLayout->addWidget(add_user, 0, 2, 1, 1);

        delete_user = new QPushButton(widget);
        delete_user->setObjectName("delete_user");

        gridLayout->addWidget(delete_user, 0, 3, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        tableView = new QTableView(User_manage);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8("QTableView QHeaderView::section {\n"
"    background-color: lightgray;\n"
"    border: 1px solid gray;\n"
"}"));

        gridLayout_2->addWidget(tableView, 3, 0, 1, 1);

        label_3 = new QLabel(User_manage);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);


        retranslateUi(User_manage);

        QMetaObject::connectSlotsByName(User_manage);
    } // setupUi

    void retranslateUi(QWidget *User_manage)
    {
        User_manage->setWindowTitle(QCoreApplication::translate("User_manage", "User_manage", nullptr));
        label_2->setText(QCoreApplication::translate("User_manage", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        label->setText(QCoreApplication::translate("User_manage", "\346\220\234\347\264\242\357\274\232", nullptr));
        add_user->setText(QCoreApplication::translate("User_manage", "\345\242\236\345\212\240\347\224\250\346\210\267", nullptr));
        delete_user->setText(QCoreApplication::translate("User_manage", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        pushButton_3->setText(QCoreApplication::translate("User_manage", "\346\233\264\346\224\271\347\224\250\346\210\267", nullptr));
        label_3->setText(QCoreApplication::translate("User_manage", "\346\263\250\357\274\232type\344\270\255\357\274\2320--\347\256\241\347\220\206\345\221\230 \357\274\2141--\345\255\246\347\224\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User_manage: public Ui_User_manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_MANAGE_H
