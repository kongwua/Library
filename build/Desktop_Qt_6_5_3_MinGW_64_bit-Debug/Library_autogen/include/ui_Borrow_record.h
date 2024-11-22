/********************************************************************************
** Form generated from reading UI file 'borrow_record.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROW_RECORD_H
#define UI_BORROW_RECORD_H

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

class Ui_Borrow_record
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

    void setupUi(QWidget *Borrow_record)
    {
        if (Borrow_record->objectName().isEmpty())
            Borrow_record->setObjectName("Borrow_record");
        Borrow_record->resize(597, 425);
        gridLayout_2 = new QGridLayout(Borrow_record);
        gridLayout_2->setObjectName("gridLayout_2");
        label_2 = new QLabel(Borrow_record);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        widget = new QWidget(Borrow_record);
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

        tableView = new QTableView(Borrow_record);
        tableView->setObjectName("tableView");

        gridLayout_2->addWidget(tableView, 2, 0, 1, 1);


        retranslateUi(Borrow_record);

        QMetaObject::connectSlotsByName(Borrow_record);
    } // setupUi

    void retranslateUi(QWidget *Borrow_record)
    {
        Borrow_record->setWindowTitle(QCoreApplication::translate("Borrow_record", "Borrow_record", nullptr));
        label_2->setText(QCoreApplication::translate("Borrow_record", "\345\200\237\351\230\205\350\256\260\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("Borrow_record", "\346\220\234\347\264\242\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("Borrow_record", "\345\242\236\345\212\240\347\224\250\346\210\267", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Borrow_record", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Borrow_record", "\346\233\264\346\224\271\347\224\250\346\210\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Borrow_record: public Ui_Borrow_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROW_RECORD_H
