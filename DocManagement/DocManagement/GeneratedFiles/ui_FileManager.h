/********************************************************************************
** Form generated from reading UI file 'FileManager.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEMANAGER_H
#define UI_FILEMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileManager
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineedit_search_string;
    QPushButton *btn_search;
    QPushButton *btn_empty;
    QPushButton *AddButton;
    QTableView *tableView;

    void setupUi(QWidget *FileManager)
    {
        if (FileManager->objectName().isEmpty())
            FileManager->setObjectName(QStringLiteral("FileManager"));
        FileManager->resize(669, 497);
        FileManager->setMinimumSize(QSize(0, 0));
        gridLayout_2 = new QGridLayout(FileManager);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget = new QWidget(FileManager);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineedit_search_string = new QLineEdit(widget);
        lineedit_search_string->setObjectName(QStringLiteral("lineedit_search_string"));

        horizontalLayout->addWidget(lineedit_search_string);

        btn_search = new QPushButton(widget);
        btn_search->setObjectName(QStringLiteral("btn_search"));
        btn_search->setMinimumSize(QSize(28, 23));
        btn_search->setMaximumSize(QSize(28, 23));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/search.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_search->setIcon(icon);

        horizontalLayout->addWidget(btn_search);

        btn_empty = new QPushButton(widget);
        btn_empty->setObjectName(QStringLiteral("btn_empty"));
        btn_empty->setMinimumSize(QSize(41, 23));
        btn_empty->setMaximumSize(QSize(41, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/sync.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_empty->setIcon(icon1);

        horizontalLayout->addWidget(btn_empty);

        AddButton = new QPushButton(widget);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setMinimumSize(QSize(55, 23));
        AddButton->setMaximumSize(QSize(55, 23));

        horizontalLayout->addWidget(AddButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableView = new QTableView(widget);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(FileManager);

        QMetaObject::connectSlotsByName(FileManager);
    } // setupUi

    void retranslateUi(QWidget *FileManager)
    {
        FileManager->setWindowTitle(QApplication::translate("FileManager", "Form", Q_NULLPTR));
        btn_search->setText(QString());
        btn_empty->setText(QString());
        AddButton->setText(QApplication::translate("FileManager", "\346\226\260\345\273\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileManager: public Ui_FileManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGER_H
