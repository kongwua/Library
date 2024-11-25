/********************************************************************************
** Form generated from reading UI file 'userinfo_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFO_DIALOG_H
#define UI_USERINFO_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userinfo_dialog
{
public:
    QTableView *book_tableView;
    QTableView *reserve_tableView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *admin_checkBox;
    QPushButton *psw_btn;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *delete_btn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *return_btn;
    QPushButton *borrow_btn;
    QLabel *num_label;

    void setupUi(QDialog *userinfo_dialog)
    {
        if (userinfo_dialog->objectName().isEmpty())
            userinfo_dialog->setObjectName("userinfo_dialog");
        userinfo_dialog->resize(607, 486);
        book_tableView = new QTableView(userinfo_dialog);
        book_tableView->setObjectName("book_tableView");
        book_tableView->setGeometry(QRect(10, 140, 581, 171));
        reserve_tableView = new QTableView(userinfo_dialog);
        reserve_tableView->setObjectName("reserve_tableView");
        reserve_tableView->setGeometry(QRect(10, 330, 581, 111));
        layoutWidget = new QWidget(userinfo_dialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 10, 201, 44));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        layoutWidget1 = new QWidget(userinfo_dialog);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(510, 10, 77, 50));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        admin_checkBox = new QCheckBox(layoutWidget1);
        admin_checkBox->setObjectName("admin_checkBox");

        verticalLayout_2->addWidget(admin_checkBox);

        psw_btn = new QPushButton(layoutWidget1);
        psw_btn->setObjectName("psw_btn");

        verticalLayout_2->addWidget(psw_btn);

        layoutWidget2 = new QWidget(userinfo_dialog);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(20, 70, 571, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        delete_btn = new QPushButton(layoutWidget2);
        delete_btn->setObjectName("delete_btn");

        horizontalLayout->addWidget(delete_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(layoutWidget2);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);

        layoutWidget3 = new QWidget(userinfo_dialog);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 450, 158, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        return_btn = new QPushButton(layoutWidget3);
        return_btn->setObjectName("return_btn");

        horizontalLayout_2->addWidget(return_btn);

        borrow_btn = new QPushButton(layoutWidget3);
        borrow_btn->setObjectName("borrow_btn");

        horizontalLayout_2->addWidget(borrow_btn);

        num_label = new QLabel(userinfo_dialog);
        num_label->setObjectName("num_label");
        num_label->setGeometry(QRect(520, 110, 71, 21));

        retranslateUi(userinfo_dialog);

        QMetaObject::connectSlotsByName(userinfo_dialog);
    } // setupUi

    void retranslateUi(QDialog *userinfo_dialog)
    {
        userinfo_dialog->setWindowTitle(QCoreApplication::translate("userinfo_dialog", "\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("userinfo_dialog", "\347\224\250\346\210\267ID", nullptr));
        admin_checkBox->setText(QCoreApplication::translate("userinfo_dialog", "\347\256\241\347\220\206\345\221\230", nullptr));
        psw_btn->setText(QCoreApplication::translate("userinfo_dialog", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        delete_btn->setText(QCoreApplication::translate("userinfo_dialog", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        return_btn->setText(QCoreApplication::translate("userinfo_dialog", "\350\277\230\344\271\246", nullptr));
        borrow_btn->setText(QCoreApplication::translate("userinfo_dialog", "\345\200\237\344\271\246", nullptr));
        num_label->setText(QCoreApplication::translate("userinfo_dialog", "\345\267\262\345\200\237 0 \346\234\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userinfo_dialog: public Ui_userinfo_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_DIALOG_H
