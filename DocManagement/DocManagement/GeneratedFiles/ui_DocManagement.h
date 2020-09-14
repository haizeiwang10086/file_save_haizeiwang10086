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
#include <QtWidgets/QGridLayout>
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
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DocManagementClass)
    {
        if (DocManagementClass->objectName().isEmpty())
            DocManagementClass->setObjectName(QStringLiteral("DocManagementClass"));
        DocManagementClass->resize(1000, 600);
        DocManagementClass->setMinimumSize(QSize(1000, 600));
        centralWidget = new QWidget(DocManagementClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabPosition(QTabWidget::West);

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        DocManagementClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DocManagementClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 30));
        DocManagementClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DocManagementClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DocManagementClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DocManagementClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DocManagementClass->setStatusBar(statusBar);

        retranslateUi(DocManagementClass);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(DocManagementClass);
    } // setupUi

    void retranslateUi(QMainWindow *DocManagementClass)
    {
        DocManagementClass->setWindowTitle(QApplication::translate("DocManagementClass", "DocManagement", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DocManagementClass: public Ui_DocManagementClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCMANAGEMENT_H
