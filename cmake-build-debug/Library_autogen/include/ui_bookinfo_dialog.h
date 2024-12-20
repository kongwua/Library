/********************************************************************************
** Form generated from reading UI file 'bookinfo_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKINFO_DIALOG_H
#define UI_BOOKINFO_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_bookinfo_dialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *name_edit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *isbn_edit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QSpinBox *num_spinBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *price_doubleSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *delete_btn;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QPushButton *borrowBook_btn;
    QPushButton *returnBook_btn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *num_label;
    QTableView *reader_tableView;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_3;
    QLabel *reserve_lable;
    QTableView *reserve_tableView;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *bookinfo_dialog)
    {
        if (bookinfo_dialog->objectName().isEmpty())
            bookinfo_dialog->setObjectName("bookinfo_dialog");
        bookinfo_dialog->resize(649, 534);
        gridLayout = new QGridLayout(bookinfo_dialog);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(bookinfo_dialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        name_edit = new QLineEdit(bookinfo_dialog);
        name_edit->setObjectName("name_edit");

        verticalLayout->addWidget(name_edit);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(bookinfo_dialog);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        isbn_edit = new QLineEdit(bookinfo_dialog);
        isbn_edit->setObjectName("isbn_edit");

        verticalLayout_2->addWidget(isbn_edit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(bookinfo_dialog);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        num_spinBox = new QSpinBox(bookinfo_dialog);
        num_spinBox->setObjectName("num_spinBox");

        verticalLayout_3->addWidget(num_spinBox);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(bookinfo_dialog);
        label_4->setObjectName("label_4");

        verticalLayout_4->addWidget(label_4);

        price_doubleSpinBox = new QDoubleSpinBox(bookinfo_dialog);
        price_doubleSpinBox->setObjectName("price_doubleSpinBox");

        verticalLayout_4->addWidget(price_doubleSpinBox);


        horizontalLayout->addLayout(verticalLayout_4);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        delete_btn = new QPushButton(bookinfo_dialog);
        delete_btn->setObjectName("delete_btn");

        horizontalLayout_2->addWidget(delete_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(bookinfo_dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        borrowBook_btn = new QPushButton(bookinfo_dialog);
        borrowBook_btn->setObjectName("borrowBook_btn");

        gridLayout->addWidget(borrowBook_btn, 2, 0, 1, 1);

        returnBook_btn = new QPushButton(bookinfo_dialog);
        returnBook_btn->setObjectName("returnBook_btn");

        gridLayout->addWidget(returnBook_btn, 2, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(bookinfo_dialog);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        num_label = new QLabel(bookinfo_dialog);
        num_label->setObjectName("num_label");

        horizontalLayout_3->addWidget(num_label);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 2);

        reader_tableView = new QTableView(bookinfo_dialog);
        reader_tableView->setObjectName("reader_tableView");

        gridLayout->addWidget(reader_tableView, 4, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_7 = new QLabel(bookinfo_dialog);
        label_7->setObjectName("label_7");

        horizontalLayout_4->addWidget(label_7);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        reserve_lable = new QLabel(bookinfo_dialog);
        reserve_lable->setObjectName("reserve_lable");

        horizontalLayout_4->addWidget(reserve_lable);


        gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 2);

        reserve_tableView = new QTableView(bookinfo_dialog);
        reserve_tableView->setObjectName("reserve_tableView");

        gridLayout->addWidget(reserve_tableView, 6, 0, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_5, 7, 0, 1, 2);


        retranslateUi(bookinfo_dialog);

        QMetaObject::connectSlotsByName(bookinfo_dialog);
    } // setupUi

    void retranslateUi(QDialog *bookinfo_dialog)
    {
        bookinfo_dialog->setWindowTitle(QCoreApplication::translate("bookinfo_dialog", "\345\233\276\344\271\246\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("bookinfo_dialog", "\344\271\246\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("bookinfo_dialog", "\344\271\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("bookinfo_dialog", "\346\225\260\351\207\217", nullptr));
        label_4->setText(QCoreApplication::translate("bookinfo_dialog", "\344\273\267\346\240\274", nullptr));
        delete_btn->setText(QCoreApplication::translate("bookinfo_dialog", "\345\210\240\351\231\244\345\233\276\344\271\246", nullptr));
        borrowBook_btn->setText(QCoreApplication::translate("bookinfo_dialog", "\345\200\237\351\230\205\346\255\244\344\271\246", nullptr));
        returnBook_btn->setText(QCoreApplication::translate("bookinfo_dialog", "\345\275\222\350\277\230\346\255\244\344\271\246", nullptr));
        label_5->setText(QCoreApplication::translate("bookinfo_dialog", "\345\200\237\351\230\205\346\234\254\344\271\246\347\232\204\347\224\250\346\210\267", nullptr));
        num_label->setText(QCoreApplication::translate("bookinfo_dialog", "\345\205\261\345\200\237\345\207\272 0 \346\234\254", nullptr));
        label_7->setText(QCoreApplication::translate("bookinfo_dialog", "\351\242\204\347\272\246\346\234\254\344\271\246\347\232\204\347\224\250\346\210\267", nullptr));
        reserve_lable->setText(QCoreApplication::translate("bookinfo_dialog", "\345\205\261\351\242\204\347\272\246 0 \346\234\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookinfo_dialog: public Ui_bookinfo_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKINFO_DIALOG_H
