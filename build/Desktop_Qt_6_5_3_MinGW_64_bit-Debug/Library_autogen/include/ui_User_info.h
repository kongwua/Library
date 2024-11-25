/********************************************************************************
** Form generated from reading UI file 'user_info.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_INFO_H
#define UI_USER_INFO_H

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

class Ui_dialog
{
public:
    QTableView *book_tableView;
    QTableView *reserve_tableView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *deleteUser_btn;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *returnBook_btn;
    QPushButton *borrowBook_btn;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *userID_edit;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *admin_check;
    QPushButton *change_psw_btn;

    void setupUi(QDialog *dialog)
    {
        if (dialog->objectName().isEmpty())
            dialog->setObjectName("dialog");
        dialog->resize(632, 460);
        book_tableView = new QTableView(dialog);
        book_tableView->setObjectName("book_tableView");
        book_tableView->setGeometry(QRect(20, 141, 581, 141));
        reserve_tableView = new QTableView(dialog);
        reserve_tableView->setObjectName("reserve_tableView");
        reserve_tableView->setGeometry(QRect(20, 290, 581, 111));
        layoutWidget = new QWidget(dialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 100, 581, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        deleteUser_btn = new QPushButton(layoutWidget);
        deleteUser_btn->setObjectName("deleteUser_btn");

        horizontalLayout->addWidget(deleteUser_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);

        layoutWidget1 = new QWidget(dialog);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 420, 158, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        returnBook_btn = new QPushButton(layoutWidget1);
        returnBook_btn->setObjectName("returnBook_btn");

        horizontalLayout_2->addWidget(returnBook_btn);

        borrowBook_btn = new QPushButton(layoutWidget1);
        borrowBook_btn->setObjectName("borrowBook_btn");

        horizontalLayout_2->addWidget(borrowBook_btn);

        layoutWidget2 = new QWidget(dialog);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(20, 10, 581, 71));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(layoutWidget2);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label);

        userID_edit = new QLineEdit(layoutWidget2);
        userID_edit->setObjectName("userID_edit");
        userID_edit->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(userID_edit);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        admin_check = new QCheckBox(layoutWidget2);
        admin_check->setObjectName("admin_check");

        verticalLayout_2->addWidget(admin_check);

        change_psw_btn = new QPushButton(layoutWidget2);
        change_psw_btn->setObjectName("change_psw_btn");

        verticalLayout_2->addWidget(change_psw_btn);


        horizontalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(dialog);

        QMetaObject::connectSlotsByName(dialog);
    } // setupUi

    void retranslateUi(QDialog *dialog)
    {
        dialog->setWindowTitle(QCoreApplication::translate("dialog", "\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        deleteUser_btn->setText(QCoreApplication::translate("dialog", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        returnBook_btn->setText(QCoreApplication::translate("dialog", "\350\277\230\344\271\246", nullptr));
        borrowBook_btn->setText(QCoreApplication::translate("dialog", "\345\200\237\344\271\246", nullptr));
        label->setText(QCoreApplication::translate("dialog", "<html><head/><body><p><span style=\" font-size:10pt;\">\347\224\250\346\210\267ID</span></p></body></html>", nullptr));
        admin_check->setText(QCoreApplication::translate("dialog", "\347\256\241\347\220\206\345\221\230", nullptr));
        change_psw_btn->setText(QCoreApplication::translate("dialog", "\346\233\264\346\224\271\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog: public Ui_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_INFO_H
