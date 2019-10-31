/********************************************************************************
** Form generated from reading UI file 'QuestionWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONWINDOW_H
#define UI_QUESTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionWindow
{
public:
    QTableView *tableView;
    QPushButton *AddButton;
    QPushButton *btn_search;
    QLineEdit *lineedit_search_string;
    QPushButton *btn_empty;

    void setupUi(QWidget *QuestionWindow)
    {
        if (QuestionWindow->objectName().isEmpty())
            QuestionWindow->setObjectName(QStringLiteral("QuestionWindow"));
        QuestionWindow->resize(517, 375);
        tableView = new QTableView(QuestionWindow);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(60, 90, 361, 241));
        AddButton = new QPushButton(QuestionWindow);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setGeometry(QRect(430, 60, 75, 23));
        btn_search = new QPushButton(QuestionWindow);
        btn_search->setObjectName(QStringLiteral("btn_search"));
        btn_search->setGeometry(QRect(280, 60, 75, 23));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/search.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_search->setIcon(icon);
        lineedit_search_string = new QLineEdit(QuestionWindow);
        lineedit_search_string->setObjectName(QStringLiteral("lineedit_search_string"));
        lineedit_search_string->setGeometry(QRect(60, 61, 221, 20));
        btn_empty = new QPushButton(QuestionWindow);
        btn_empty->setObjectName(QStringLiteral("btn_empty"));
        btn_empty->setGeometry(QRect(360, 60, 75, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/sync.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_empty->setIcon(icon1);

        retranslateUi(QuestionWindow);

        QMetaObject::connectSlotsByName(QuestionWindow);
    } // setupUi

    void retranslateUi(QWidget *QuestionWindow)
    {
        QuestionWindow->setWindowTitle(QApplication::translate("QuestionWindow", "Form", Q_NULLPTR));
        AddButton->setText(QApplication::translate("QuestionWindow", "\346\226\260\345\273\272", Q_NULLPTR));
        btn_search->setText(QString());
        btn_empty->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QuestionWindow: public Ui_QuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONWINDOW_H
