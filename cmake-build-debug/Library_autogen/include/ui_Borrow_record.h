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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *searchEdit;
    QDateEdit *dateEdit;
    QPushButton *search_btn;
    QComboBox *comboBox;
    QLabel *label_3;
    QCheckBox *checkBox;
    QLabel *label;
    QPushButton *payFine_btn;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tableView;
    QLabel *label_2;

    void setupUi(QWidget *Borrow_record)
    {
        if (Borrow_record->objectName().isEmpty())
            Borrow_record->setObjectName("Borrow_record");
        Borrow_record->resize(780, 485);
        gridLayout_2 = new QGridLayout(Borrow_record);
        gridLayout_2->setObjectName("gridLayout_2");
        widget = new QWidget(Borrow_record);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        searchEdit = new QLineEdit(widget);
        searchEdit->setObjectName("searchEdit");

        gridLayout->addWidget(searchEdit, 0, 2, 1, 1);

        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName("dateEdit");

        gridLayout->addWidget(dateEdit, 0, 12, 1, 1);

        search_btn = new QPushButton(widget);
        search_btn->setObjectName("search_btn");

        gridLayout->addWidget(search_btn, 0, 6, 1, 1);

        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 11, 1, 1);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName("checkBox");

        gridLayout->addWidget(checkBox, 0, 4, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        payFine_btn = new QPushButton(widget);
        payFine_btn->setObjectName("payFine_btn");

        gridLayout->addWidget(payFine_btn, 0, 7, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 10, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 5, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        tableView = new QTableView(Borrow_record);
        tableView->setObjectName("tableView");

        gridLayout_2->addWidget(tableView, 2, 0, 1, 1);

        label_2 = new QLabel(Borrow_record);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);


        retranslateUi(Borrow_record);

        QMetaObject::connectSlotsByName(Borrow_record);
    } // setupUi

    void retranslateUi(QWidget *Borrow_record)
    {
        Borrow_record->setWindowTitle(QCoreApplication::translate("Borrow_record", "Borrow_record", nullptr));
        search_btn->setText(QCoreApplication::translate("Borrow_record", "\346\220\234\347\264\242", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Borrow_record", "\347\224\250\346\210\267ID", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Borrow_record", "\344\271\246\345\217\267", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Borrow_record", "\344\271\246\345\220\215", nullptr));

        label_3->setText(QCoreApplication::translate("Borrow_record", "\345\275\223\345\211\215\346\227\245\346\234\237", nullptr));
        checkBox->setText(QCoreApplication::translate("Borrow_record", "\345\217\252\347\234\213\351\200\276\346\234\237\350\256\260\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("Borrow_record", "\346\220\234\347\264\242\357\274\232", nullptr));
        payFine_btn->setText(QCoreApplication::translate("Borrow_record", "\346\270\205\347\274\264\347\275\232\346\254\276", nullptr));
        label_2->setText(QCoreApplication::translate("Borrow_record", "\345\200\237\351\230\205\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Borrow_record: public Ui_Borrow_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROW_RECORD_H
