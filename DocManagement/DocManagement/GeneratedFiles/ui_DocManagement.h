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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DocManagementClass
{
public:
    QWidget *centralWidget;
    QTextEdit *fileNameLists;
    QTextEdit *docDisp;
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
        fileNameLists = new QTextEdit(centralWidget);
        fileNameLists->setObjectName(QStringLiteral("fileNameLists"));
        fileNameLists->setGeometry(QRect(0, 0, 104, 341));
        fileNameLists->setReadOnly(true);
        docDisp = new QTextEdit(centralWidget);
        docDisp->setObjectName(QStringLiteral("docDisp"));
        docDisp->setGeometry(QRect(160, 40, 371, 291));
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
