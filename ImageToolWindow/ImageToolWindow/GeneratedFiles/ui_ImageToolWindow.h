/********************************************************************************
** Form generated from reading UI file 'ImageToolWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGETOOLWINDOW_H
#define UI_IMAGETOOLWINDOW_H

#include <ImageWindowWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageToolWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *detailBrowser;
    ImageWindowWidget *out_window;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ImageToolWindow)
    {
        if (ImageToolWindow->objectName().isEmpty())
            ImageToolWindow->setObjectName(QStringLiteral("ImageToolWindow"));
        ImageToolWindow->resize(800, 600);
        centralwidget = new QWidget(ImageToolWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        detailBrowser = new QTextBrowser(centralwidget);
        detailBrowser->setObjectName(QStringLiteral("detailBrowser"));
        detailBrowser->setGeometry(QRect(30, 100, 101, 351));
        out_window = new ImageWindowWidget(centralwidget);
        out_window->setObjectName(QStringLiteral("out_window"));
        out_window->setGeometry(QRect(180, 110, 321, 321));
        ImageToolWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ImageToolWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        ImageToolWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ImageToolWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ImageToolWindow->setStatusBar(statusbar);

        retranslateUi(ImageToolWindow);

        QMetaObject::connectSlotsByName(ImageToolWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ImageToolWindow)
    {
        ImageToolWindow->setWindowTitle(QApplication::translate("ImageToolWindow", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImageToolWindow: public Ui_ImageToolWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGETOOLWINDOW_H
