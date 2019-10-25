/********************************************************************************
** Form generated from reading UI file 'DataBaseLink.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASELINK_H
#define UI_DATABASELINK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataBaseLink
{
public:
    QLabel *dataBaseName;
    QLabel *userName;
    QLabel *password;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *spacerItem;
    QPushButton *btnTest;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *DataBaseLink)
    {
        if (DataBaseLink->objectName().isEmpty())
            DataBaseLink->setObjectName(QStringLiteral("DataBaseLink"));
        DataBaseLink->resize(400, 300);
        dataBaseName = new QLabel(DataBaseLink);
        dataBaseName->setObjectName(QStringLiteral("dataBaseName"));
        dataBaseName->setGeometry(QRect(60, 60, 72, 15));
        userName = new QLabel(DataBaseLink);
        userName->setObjectName(QStringLiteral("userName"));
        userName->setGeometry(QRect(74, 100, 61, 16));
        password = new QLabel(DataBaseLink);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(88, 138, 51, 16));
        lineEdit = new QLineEdit(DataBaseLink);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 60, 131, 21));
        lineEdit_2 = new QLineEdit(DataBaseLink);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 100, 131, 21));
        lineEdit_2->setEchoMode(QLineEdit::Normal);
        lineEdit_3 = new QLineEdit(DataBaseLink);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 138, 131, 21));
        lineEdit_3->setEchoMode(QLineEdit::Password);
        widget = new QWidget(DataBaseLink);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(21, 251, 333, 33));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(88, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerItem);

        btnTest = new QPushButton(widget);
        btnTest->setObjectName(QStringLiteral("btnTest"));

        horizontalLayout->addWidget(btnTest);

        okButton = new QPushButton(widget);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        retranslateUi(DataBaseLink);
        QObject::connect(okButton, SIGNAL(clicked()), DataBaseLink, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), DataBaseLink, SLOT(reject()));

        QMetaObject::connectSlotsByName(DataBaseLink);
    } // setupUi

    void retranslateUi(QDialog *DataBaseLink)
    {
        DataBaseLink->setWindowTitle(QApplication::translate("DataBaseLink", "Dialog", Q_NULLPTR));
        dataBaseName->setText(QApplication::translate("DataBaseLink", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", Q_NULLPTR));
        userName->setText(QApplication::translate("DataBaseLink", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        password->setText(QApplication::translate("DataBaseLink", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        btnTest->setText(QApplication::translate("DataBaseLink", "\346\265\213\350\257\225", Q_NULLPTR));
        okButton->setText(QApplication::translate("DataBaseLink", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("DataBaseLink", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DataBaseLink: public Ui_DataBaseLink {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASELINK_H
