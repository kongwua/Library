/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *login_btn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *register_btn;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *id_Ledit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *psw_Ledit;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(600, 450);
        login->setMinimumSize(QSize(600, 450));
        login->setMaximumSize(QSize(600, 450));
        label = new QLabel(login);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 50, 171, 41));
        widget = new QWidget(login);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(150, 270, 251, 42));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        login_btn = new QPushButton(widget);
        login_btn->setObjectName("login_btn");
        login_btn->setMinimumSize(QSize(90, 40));
        login_btn->setMaximumSize(QSize(90, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(14);
        login_btn->setFont(font);

        horizontalLayout->addWidget(login_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        register_btn = new QPushButton(widget);
        register_btn->setObjectName("register_btn");
        register_btn->setMinimumSize(QSize(90, 40));
        register_btn->setMaximumSize(QSize(90, 40));
        register_btn->setFont(font);

        horizontalLayout->addWidget(register_btn);

        widget1 = new QWidget(login);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(150, 150, 255, 32));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        id_Ledit = new QLineEdit(widget1);
        id_Ledit->setObjectName("id_Ledit");
        id_Ledit->setMinimumSize(QSize(190, 30));
        id_Ledit->setMaximumSize(QSize(190, 30));

        horizontalLayout_2->addWidget(id_Ledit);

        widget2 = new QWidget(login);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(150, 210, 255, 32));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget2);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        psw_Ledit = new QLineEdit(widget2);
        psw_Ledit->setObjectName("psw_Ledit");
        psw_Ledit->setMinimumSize(QSize(190, 30));
        psw_Ledit->setMaximumSize(QSize(190, 30));

        horizontalLayout_3->addWidget(psw_Ledit);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        label->setText(QCoreApplication::translate("login", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">\347\231\273\345\275\225</span></p></body></html>", nullptr));
        login_btn->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        register_btn->setText(QCoreApplication::translate("login", "\346\263\250\345\206\214", nullptr));
        label_2->setText(QCoreApplication::translate("login", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\350\264\246\345\217\267\357\274\232</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("login", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\345\257\206\347\240\201\357\274\232</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H