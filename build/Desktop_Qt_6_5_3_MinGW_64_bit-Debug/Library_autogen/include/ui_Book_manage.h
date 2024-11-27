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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Book_manage
{
public:
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QRadioButton *bookName_radioButton;
    QPushButton *search_btn;
    QRadioButton *ISBN_radioButton;
    QPushButton *addBook_btn;
    QLineEdit *SearchEdit;
    QTableView *book_tableView;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Book_manage)
    {
        if (Book_manage->objectName().isEmpty())
            Book_manage->setObjectName("Book_manage");
        Book_manage->resize(671, 466);
        widget = new QWidget(Book_manage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 651, 451));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        widget1 = new QWidget(widget);
        widget1->setObjectName("widget1");
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName("gridLayout");
        bookName_radioButton = new QRadioButton(widget1);
        bookName_radioButton->setObjectName("bookName_radioButton");

        gridLayout->addWidget(bookName_radioButton, 0, 0, 1, 1);

        search_btn = new QPushButton(widget1);
        search_btn->setObjectName("search_btn");

        gridLayout->addWidget(search_btn, 0, 3, 1, 1);

        ISBN_radioButton = new QRadioButton(widget1);
        ISBN_radioButton->setObjectName("ISBN_radioButton");

        gridLayout->addWidget(ISBN_radioButton, 0, 1, 1, 1);

        addBook_btn = new QPushButton(widget1);
        addBook_btn->setObjectName("addBook_btn");

        gridLayout->addWidget(addBook_btn, 0, 4, 1, 1);

        SearchEdit = new QLineEdit(widget1);
        SearchEdit->setObjectName("SearchEdit");

        gridLayout->addWidget(SearchEdit, 0, 2, 1, 1);


        gridLayout_2->addWidget(widget1, 1, 0, 1, 1);

        book_tableView = new QTableView(widget);
        book_tableView->setObjectName("book_tableView");

        gridLayout_2->addWidget(book_tableView, 2, 0, 1, 1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName("gridLayout_3");
        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout_3->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName("pushButton");

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 3, 1, 1);


        gridLayout_2->addWidget(widget_2, 3, 0, 1, 1);


        retranslateUi(Book_manage);

        QMetaObject::connectSlotsByName(Book_manage);
    } // setupUi

    void retranslateUi(QWidget *Book_manage)
    {
        Book_manage->setWindowTitle(QCoreApplication::translate("Book_manage", "Book_manage", nullptr));
        label_2->setText(QCoreApplication::translate("Book_manage", "\345\233\276\344\271\246\347\256\241\347\220\206", nullptr));
        bookName_radioButton->setText(QCoreApplication::translate("Book_manage", "\344\271\246\345\220\215", nullptr));
        search_btn->setText(QCoreApplication::translate("Book_manage", "\346\220\234\347\264\242", nullptr));
        ISBN_radioButton->setText(QCoreApplication::translate("Book_manage", "\344\271\246\345\217\267", nullptr));
        addBook_btn->setText(QCoreApplication::translate("Book_manage", "\345\242\236\345\212\240\345\233\276\344\271\246", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Book_manage", "\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Book_manage", "\350\277\230\344\271\246", nullptr));
        pushButton->setText(QCoreApplication::translate("Book_manage", "\345\200\237\344\271\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Book_manage: public Ui_Book_manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOK_MANAGE_H
