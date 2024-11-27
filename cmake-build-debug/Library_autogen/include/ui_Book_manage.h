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
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QRadioButton *bookName_radioButton;
    QPushButton *search_btn;
    QRadioButton *ISBN_radioButton;
    QPushButton *addBook_btn;
    QLineEdit *SearchEdit;
    QTableView *book_tableView;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QPushButton *bookInfo_btn;
    QPushButton *returnBook_btn;
    QPushButton *borrowBook_btn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Book_manage)
    {
        if (Book_manage->objectName().isEmpty())
            Book_manage->setObjectName("Book_manage");
        Book_manage->resize(787, 560);
        gridLayout_4 = new QGridLayout(Book_manage);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_2 = new QLabel(Book_manage);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        widget = new QWidget(Book_manage);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        bookName_radioButton = new QRadioButton(widget);
        bookName_radioButton->setObjectName("bookName_radioButton");

        gridLayout->addWidget(bookName_radioButton, 0, 0, 1, 1);

        search_btn = new QPushButton(widget);
        search_btn->setObjectName("search_btn");

        gridLayout->addWidget(search_btn, 0, 3, 1, 1);

        ISBN_radioButton = new QRadioButton(widget);
        ISBN_radioButton->setObjectName("ISBN_radioButton");

        gridLayout->addWidget(ISBN_radioButton, 0, 1, 1, 1);

        addBook_btn = new QPushButton(widget);
        addBook_btn->setObjectName("addBook_btn");

        gridLayout->addWidget(addBook_btn, 0, 4, 1, 1);

        SearchEdit = new QLineEdit(widget);
        SearchEdit->setObjectName("SearchEdit");

        gridLayout->addWidget(SearchEdit, 0, 2, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        book_tableView = new QTableView(Book_manage);
        book_tableView->setObjectName("book_tableView");

        gridLayout_2->addWidget(book_tableView, 2, 0, 1, 1);

        widget_2 = new QWidget(Book_manage);
        widget_2->setObjectName("widget_2");
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName("gridLayout_3");
        bookInfo_btn = new QPushButton(widget_2);
        bookInfo_btn->setObjectName("bookInfo_btn");

        gridLayout_3->addWidget(bookInfo_btn, 0, 2, 1, 1);

        returnBook_btn = new QPushButton(widget_2);
        returnBook_btn->setObjectName("returnBook_btn");

        gridLayout_3->addWidget(returnBook_btn, 0, 1, 1, 1);

        borrowBook_btn = new QPushButton(widget_2);
        borrowBook_btn->setObjectName("borrowBook_btn");

        gridLayout_3->addWidget(borrowBook_btn, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 3, 1, 1);


        gridLayout_2->addWidget(widget_2, 3, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);


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
        bookInfo_btn->setText(QCoreApplication::translate("Book_manage", "\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        returnBook_btn->setText(QCoreApplication::translate("Book_manage", "\350\277\230\344\271\246", nullptr));
        borrowBook_btn->setText(QCoreApplication::translate("Book_manage", "\345\200\237\344\271\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Book_manage: public Ui_Book_manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOK_MANAGE_H
