/********************************************************************************
** Form generated from reading UI file 'DocManagement.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCMANAGEMENT_H
#define UI_DOCMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DocManagementClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DocManagementClass)
    {
        if (DocManagementClass->objectName().isEmpty())
            DocManagementClass->setObjectName(QStringLiteral("DocManagementClass"));
        DocManagementClass->resize(600, 400);
        centralWidget = new QWidget(DocManagementClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 30, 541, 311));
        tabWidget->setTabPosition(QTabWidget::West);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        DocManagementClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DocManagementClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        DocManagementClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DocManagementClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DocManagementClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DocManagementClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DocManagementClass->setStatusBar(statusBar);

        retranslateUi(DocManagementClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DocManagementClass);
    } // setupUi

    void retranslateUi(QMainWindow *DocManagementClass)
    {
        DocManagementClass->setWindowTitle(QApplication::translate("DocManagementClass", "DocManagement", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DocManagementClass", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DocManagementClass", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DocManagementClass: public Ui_DocManagementClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCMANAGEMENT_H