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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_userinfo_dialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *returnBook_btn;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *delete_btn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *admin_checkBox;
    QPushButton *psw_btn;
    QTableView *reserve_tableView;
    QTableView *book_tableView;
    QLabel *num_label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;

    void setupUi(QDialog *userinfo_dialog)
    {
        if (userinfo_dialog->objectName().isEmpty())
            userinfo_dialog->setObjectName("userinfo_dialog");
        userinfo_dialog->resize(665, 570);
        gridLayout = new QGridLayout(userinfo_dialog);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        returnBook_btn = new QPushButton(userinfo_dialog);
        returnBook_btn->setObjectName("returnBook_btn");

        horizontalLayout_2->addWidget(returnBook_btn);


        gridLayout->addLayout(horizontalLayout_2, 6, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(userinfo_dialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(userinfo_dialog);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        label_3 = new QLabel(userinfo_dialog);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_2 = new QLabel(userinfo_dialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        delete_btn = new QPushButton(userinfo_dialog);
        delete_btn->setObjectName("delete_btn");

        horizontalLayout->addWidget(delete_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(userinfo_dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        admin_checkBox = new QCheckBox(userinfo_dialog);
        admin_checkBox->setObjectName("admin_checkBox");

        verticalLayout_2->addWidget(admin_checkBox);

        psw_btn = new QPushButton(userinfo_dialog);
        psw_btn->setObjectName("psw_btn");

        verticalLayout_2->addWidget(psw_btn);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);

        reserve_tableView = new QTableView(userinfo_dialog);
        reserve_tableView->setObjectName("reserve_tableView");

        gridLayout->addWidget(reserve_tableView, 5, 0, 1, 3);

        book_tableView = new QTableView(userinfo_dialog);
        book_tableView->setObjectName("book_tableView");

        gridLayout->addWidget(book_tableView, 3, 0, 1, 3);

        num_label = new QLabel(userinfo_dialog);
        num_label->setObjectName("num_label");

        gridLayout->addWidget(num_label, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 6, 1, 1, 2);

        label_4 = new QLabel(userinfo_dialog);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 4, 2, 1, 1);


        retranslateUi(userinfo_dialog);

        QMetaObject::connectSlotsByName(userinfo_dialog);
    } // setupUi

    void retranslateUi(QDialog *userinfo_dialog)
    {
        userinfo_dialog->setWindowTitle(QCoreApplication::translate("userinfo_dialog", "\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        returnBook_btn->setText(QCoreApplication::translate("userinfo_dialog", "\350\277\230\344\271\246", nullptr));
        label->setText(QCoreApplication::translate("userinfo_dialog", "\347\224\250\346\210\267ID", nullptr));
        label_3->setText(QCoreApplication::translate("userinfo_dialog", "\345\267\262\351\242\204\347\272\246\344\271\246\347\261\215", nullptr));
        label_2->setText(QCoreApplication::translate("userinfo_dialog", "\345\267\262\345\200\237\351\230\205\344\271\246\347\261\215", nullptr));
        delete_btn->setText(QCoreApplication::translate("userinfo_dialog", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        admin_checkBox->setText(QCoreApplication::translate("userinfo_dialog", "\347\256\241\347\220\206\345\221\230", nullptr));
        psw_btn->setText(QCoreApplication::translate("userinfo_dialog", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        num_label->setText(QCoreApplication::translate("userinfo_dialog", "\345\267\262\345\200\237 0 \346\234\254", nullptr));
        label_4->setText(QCoreApplication::translate("userinfo_dialog", "\345\267\262\351\242\204\347\272\246 0 \346\234\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userinfo_dialog: public Ui_userinfo_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_DIALOG_H
