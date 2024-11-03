/********************************************************************************
** Form generated from reading UI file 'book_manage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOK_MANAGE_H
#define UI_BOOK_MANAGE_H

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

class Ui_Book_manage
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;

    void setupUi(QWidget *Book_manage)
    {
        if (Book_manage->objectName().isEmpty())
            Book_manage->setObjectName("Book_manage");
        Book_manage->resize(687, 548);
        gridLayout_2 = new QGridLayout(Book_manage);
        gridLayout_2->setObjectName("gridLayout_2");
        label_2 = new QLabel(Book_manage);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        widget = new QWidget(Book_manage);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 0, 3, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        tableView = new QTableView(Book_manage);
        tableView->setObjectName("tableView");

        gridLayout_2->addWidget(tableView, 2, 0, 1, 1);


        retranslateUi(Book_manage);

        QMetaObject::connectSlotsByName(Book_manage);
    } // setupUi

    void retranslateUi(QWidget *Book_manage)
    {
        Book_manage->setWindowTitle(QCoreApplication::translate("Book_manage", "Book_manage", nullptr));
        label_2->setText(QCoreApplication::translate("Book_manage", "\345\233\276\344\271\246\347\256\241\347\220\206", nullptr));
        label->setText(QCoreApplication::translate("Book_manage", "\346\220\234\347\264\242\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("Book_manage", "\345\242\236\345\212\240\347\224\250\346\210\267", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Book_manage", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Book_manage", "\346\233\264\346\224\271\347\224\250\346\210\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Book_manage: public Ui_Book_manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOK_MANAGE_H
