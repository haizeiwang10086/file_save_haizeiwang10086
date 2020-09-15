/********************************************************************************
** Form generated from reading UI file 'MsgNew.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGNEW_H
#define UI_MSGNEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MsgNewWindow
{
public:
    QLabel *title;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QLabel *content;
    QPushButton *save;
    QPushButton *cancle;
    QLabel *label_remarks;
    QTextEdit *textEdit_remarks;
    QPushButton *btn_modify;

    void setupUi(QWidget *MsgNewWindow)
    {
        if (MsgNewWindow->objectName().isEmpty())
            MsgNewWindow->setObjectName(QStringLiteral("MsgNewWindow"));
        MsgNewWindow->resize(400, 300);
        title = new QLabel(MsgNewWindow);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(50, 49, 54, 20));
        textEdit = new QTextEdit(MsgNewWindow);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(90, 80, 281, 71));
        lineEdit = new QLineEdit(MsgNewWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 50, 281, 20));
        content = new QLabel(MsgNewWindow);
        content->setObjectName(QStringLiteral("content"));
        content->setGeometry(QRect(50, 82, 54, 12));
        save = new QPushButton(MsgNewWindow);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(80, 270, 75, 23));
        cancle = new QPushButton(MsgNewWindow);
        cancle->setObjectName(QStringLiteral("cancle"));
        cancle->setGeometry(QRect(280, 270, 75, 23));
        label_remarks = new QLabel(MsgNewWindow);
        label_remarks->setObjectName(QStringLiteral("label_remarks"));
        label_remarks->setGeometry(QRect(50, 166, 54, 12));
        textEdit_remarks = new QTextEdit(MsgNewWindow);
        textEdit_remarks->setObjectName(QStringLiteral("textEdit_remarks"));
        textEdit_remarks->setGeometry(QRect(90, 166, 281, 91));
        btn_modify = new QPushButton(MsgNewWindow);
        btn_modify->setObjectName(QStringLiteral("btn_modify"));
        btn_modify->setGeometry(QRect(180, 270, 75, 23));

        retranslateUi(MsgNewWindow);

        QMetaObject::connectSlotsByName(MsgNewWindow);
    } // setupUi

    void retranslateUi(QWidget *MsgNewWindow)
    {
        MsgNewWindow->setWindowTitle(QApplication::translate("MsgNewWindow", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("MsgNewWindow", "\346\240\207\351\242\230\357\274\232", Q_NULLPTR));
        content->setText(QApplication::translate("MsgNewWindow", "\345\206\205\345\256\271\357\274\232", Q_NULLPTR));
        save->setText(QApplication::translate("MsgNewWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        cancle->setText(QApplication::translate("MsgNewWindow", "\345\217\226\346\266\210", Q_NULLPTR));
        label_remarks->setText(QApplication::translate("MsgNewWindow", "\345\244\207\346\263\250\357\274\232", Q_NULLPTR));
        btn_modify->setText(QApplication::translate("MsgNewWindow", "\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MsgNewWindow: public Ui_MsgNewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGNEW_H
