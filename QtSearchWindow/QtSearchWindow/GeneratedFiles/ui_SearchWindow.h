/********************************************************************************
** Form generated from reading UI file 'SearchWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHWINDOW_H
#define UI_SEARCHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchWindow
{
public:
    QTableView *tableView;
    QPushButton *AddButton;
    QPushButton *RecoverButton;
    QPushButton *EditButton;

    void setupUi(QWidget *SearchWindow)
    {
        if (SearchWindow->objectName().isEmpty())
            SearchWindow->setObjectName(QStringLiteral("SearchWindow"));
        SearchWindow->resize(517, 375);
        tableView = new QTableView(SearchWindow);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(61, 31, 361, 241));
        AddButton = new QPushButton(SearchWindow);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setGeometry(QRect(80, 300, 75, 23));
        RecoverButton = new QPushButton(SearchWindow);
        RecoverButton->setObjectName(QStringLiteral("RecoverButton"));
        RecoverButton->setGeometry(QRect(290, 300, 75, 23));
        EditButton = new QPushButton(SearchWindow);
        EditButton->setObjectName(QStringLiteral("EditButton"));
        EditButton->setGeometry(QRect(180, 300, 75, 23));

        retranslateUi(SearchWindow);

        QMetaObject::connectSlotsByName(SearchWindow);
    } // setupUi

    void retranslateUi(QWidget *SearchWindow)
    {
        SearchWindow->setWindowTitle(QApplication::translate("SearchWindow", "Form", Q_NULLPTR));
        AddButton->setText(QApplication::translate("SearchWindow", "\346\226\260\345\273\272", Q_NULLPTR));
        RecoverButton->setText(QApplication::translate("SearchWindow", "\346\222\244\345\233\236", Q_NULLPTR));
        EditButton->setText(QApplication::translate("SearchWindow", "\347\274\226\350\276\221", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SearchWindow: public Ui_SearchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWINDOW_H
