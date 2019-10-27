/********************************************************************************
** Form generated from reading UI file 'DocDisp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCDISP_H
#define UI_DOCDISP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DocDispClass
{
public:
    QTextEdit *textEdit;

    void setupUi(QWidget *DocDispClass)
    {
        if (DocDispClass->objectName().isEmpty())
            DocDispClass->setObjectName(QStringLiteral("DocDispClass"));
        DocDispClass->resize(400, 300);
        textEdit = new QTextEdit(DocDispClass);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(50, 30, 311, 231));

        retranslateUi(DocDispClass);

        QMetaObject::connectSlotsByName(DocDispClass);
    } // setupUi

    void retranslateUi(QWidget *DocDispClass)
    {
        DocDispClass->setWindowTitle(QApplication::translate("DocDispClass", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DocDispClass: public Ui_DocDispClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCDISP_H
