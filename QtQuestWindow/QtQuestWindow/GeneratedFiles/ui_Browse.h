/********************************************************************************
** Form generated from reading UI file 'Browse.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSE_H
#define UI_BROWSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_BrowseWindow
{
public:
    QTextBrowser *text_content;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *BrowseWindow)
    {
        if (BrowseWindow->objectName().isEmpty())
            BrowseWindow->setObjectName(QStringLiteral("BrowseWindow"));
        BrowseWindow->resize(400, 300);
        text_content = new QTextBrowser(BrowseWindow);
        text_content->setObjectName(QStringLiteral("text_content"));
        text_content->setGeometry(QRect(50, 10, 311, 231));
        okButton = new QPushButton(BrowseWindow);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(110, 250, 75, 23));
        cancelButton = new QPushButton(BrowseWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(200, 250, 75, 23));

        retranslateUi(BrowseWindow);
        QObject::connect(okButton, SIGNAL(clicked()), BrowseWindow, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), BrowseWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(BrowseWindow);
    } // setupUi

    void retranslateUi(QDialog *BrowseWindow)
    {
        BrowseWindow->setWindowTitle(QApplication::translate("BrowseWindow", "Browse", Q_NULLPTR));
        okButton->setText(QApplication::translate("BrowseWindow", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("BrowseWindow", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BrowseWindow: public Ui_BrowseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSE_H
