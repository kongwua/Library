/********************************************************************************
** Form generated from reading UI file 'change_psw_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_PSW_DIALOG_H
#define UI_CHANGE_PSW_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_change_psw_dialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *old_psw_edit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *new_psw_edit;

    void setupUi(QDialog *change_psw_dialog)
    {
        if (change_psw_dialog->objectName().isEmpty())
            change_psw_dialog->setObjectName("change_psw_dialog");
        change_psw_dialog->resize(309, 227);
        buttonBox = new QDialogButtonBox(change_psw_dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(80, 150, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(change_psw_dialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(70, 70, 179, 60));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        old_psw_edit = new QLineEdit(widget);
        old_psw_edit->setObjectName("old_psw_edit");

        horizontalLayout->addWidget(old_psw_edit);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        new_psw_edit = new QLineEdit(widget);
        new_psw_edit->setObjectName("new_psw_edit");

        horizontalLayout_2->addWidget(new_psw_edit);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(change_psw_dialog);

        QMetaObject::connectSlotsByName(change_psw_dialog);
    } // setupUi

    void retranslateUi(QDialog *change_psw_dialog)
    {
        change_psw_dialog->setWindowTitle(QCoreApplication::translate("change_psw_dialog", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("change_psw_dialog", "\346\227\247\345\257\206\347\240\201", nullptr));
        label_2->setText(QCoreApplication::translate("change_psw_dialog", "\346\226\260\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class change_psw_dialog: public Ui_change_psw_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_PSW_DIALOG_H
