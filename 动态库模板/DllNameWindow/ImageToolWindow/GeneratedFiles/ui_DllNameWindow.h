/********************************************************************************
** Form generated from reading UI file 'DllNameWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGETOOLWINDOW_H
#define UI_IMAGETOOLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DllNameWindow
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *DllNameWindow)
    {
        if (DllNameWindow->objectName().isEmpty())
            DllNameWindow->setObjectName(QStringLiteral("DllNameWindow"));
        DllNameWindow->resize(517, 375);
        pushButton = new QPushButton(DllNameWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 170, 75, 23));

        retranslateUi(DllNameWindow);

        QMetaObject::connectSlotsByName(DllNameWindow);
    } // setupUi

    void retranslateUi(QWidget *DllNameWindow)
    {
        DllNameWindow->setWindowTitle(QApplication::translate("DllNameWindow", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DllNameWindow", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DllNameWindow: public Ui_DllNameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGETOOLWINDOW_H
