/********************************************************************************
** Form generated from reading UI file 'New.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_H
#define UI_NEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewWindow
{
public:
    QLabel *title;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QLabel *content;
    QPushButton *save;
    QPushButton *btn_modify;
    QComboBox *comboBox_label;

    void setupUi(QWidget *NewWindow)
    {
        if (NewWindow->objectName().isEmpty())
            NewWindow->setObjectName(QStringLiteral("NewWindow"));
        NewWindow->resize(400, 300);
        title = new QLabel(NewWindow);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(50, 49, 54, 20));
        textEdit = new QTextEdit(NewWindow);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(90, 80, 281, 171));
        lineEdit = new QLineEdit(NewWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 50, 281, 20));
        content = new QLabel(NewWindow);
        content->setObjectName(QStringLiteral("content"));
        content->setGeometry(QRect(50, 82, 54, 12));
        save = new QPushButton(NewWindow);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(100, 270, 75, 23));
        btn_modify = new QPushButton(NewWindow);
        btn_modify->setObjectName(QStringLiteral("btn_modify"));
        btn_modify->setGeometry(QRect(200, 270, 75, 23));
        comboBox_label = new QComboBox(NewWindow);
        comboBox_label->setObjectName(QStringLiteral("comboBox_label"));
        comboBox_label->setGeometry(QRect(290, 270, 69, 22));

        retranslateUi(NewWindow);

        QMetaObject::connectSlotsByName(NewWindow);
    } // setupUi

    void retranslateUi(QWidget *NewWindow)
    {
        NewWindow->setWindowTitle(QApplication::translate("NewWindow", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("NewWindow", "\346\240\207\351\242\230\357\274\232", Q_NULLPTR));
        content->setText(QApplication::translate("NewWindow", "\345\206\205\345\256\271\357\274\232", Q_NULLPTR));
        save->setText(QApplication::translate("NewWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        btn_modify->setText(QApplication::translate("NewWindow", "\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewWindow: public Ui_NewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_H
