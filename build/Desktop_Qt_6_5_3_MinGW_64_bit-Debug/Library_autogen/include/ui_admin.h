/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *tool;
    QGridLayout *gridLayout;
    QPushButton *user_btn;
    QPushButton *book_btn;
    QPushButton *borrow_btn;
    QPushButton *borrow_record_btn;
    QSpacerItem *verticalSpacer;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName("admin");
        admin->resize(810, 530);
        centralwidget = new QWidget(admin);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget#tool QPushButton{min-height:55px;font-size:16px;border:none;}\n"
"QWidget#tool {background-color:rgb(204,204,204);}\n"
"QWidget#tool QPushButton:checked{background-color:rgb(130, 130, 130);}\n"
""));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");

        gridLayout_2->addWidget(stackedWidget, 0, 1, 1, 1);

        tool = new QWidget(centralwidget);
        tool->setObjectName("tool");
        tool->setMinimumSize(QSize(160, 0));
        tool->setMaximumSize(QSize(160, 16777215));
        tool->setStyleSheet(QString::fromUtf8("QWidget{back-ground-color=gray}"));
        gridLayout = new QGridLayout(tool);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        user_btn = new QPushButton(tool);
        buttonGroup = new QButtonGroup(admin);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(user_btn);
        user_btn->setObjectName("user_btn");
        user_btn->setCheckable(true);
        user_btn->setChecked(true);

        gridLayout->addWidget(user_btn, 0, 0, 1, 1);

        book_btn = new QPushButton(tool);
        buttonGroup->addButton(book_btn);
        book_btn->setObjectName("book_btn");
        book_btn->setCheckable(true);

        gridLayout->addWidget(book_btn, 1, 0, 1, 1);

        borrow_btn = new QPushButton(tool);
        buttonGroup->addButton(borrow_btn);
        borrow_btn->setObjectName("borrow_btn");
        borrow_btn->setCheckable(true);

        gridLayout->addWidget(borrow_btn, 2, 0, 1, 1);

        borrow_record_btn = new QPushButton(tool);
        buttonGroup->addButton(borrow_record_btn);
        borrow_record_btn->setObjectName("borrow_record_btn");
        borrow_record_btn->setCheckable(true);

        gridLayout->addWidget(borrow_record_btn, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 277, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);


        gridLayout_2->addWidget(tool, 0, 0, 1, 1);

        admin->setCentralWidget(centralwidget);

        retranslateUi(admin);

        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QMainWindow *admin)
    {
        admin->setWindowTitle(QCoreApplication::translate("admin", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        user_btn->setText(QCoreApplication::translate("admin", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        book_btn->setText(QCoreApplication::translate("admin", " \345\233\276\344\271\246\347\256\241\347\220\206", nullptr));
        borrow_btn->setText(QCoreApplication::translate("admin", "\345\200\237\351\230\205\347\256\241\347\220\206", nullptr));
        borrow_record_btn->setText(QCoreApplication::translate("admin", "\345\200\237\351\230\205\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
