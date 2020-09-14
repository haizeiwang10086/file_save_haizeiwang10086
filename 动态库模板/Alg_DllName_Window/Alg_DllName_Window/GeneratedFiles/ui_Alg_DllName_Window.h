/********************************************************************************
** Form generated from reading UI file 'Alg_DllName_Window.ui'
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

class Ui_Alg_DllName_Window
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *Alg_DllName_Window)
    {
        if (Alg_DllName_Window->objectName().isEmpty())
            Alg_DllName_Window->setObjectName(QStringLiteral("Alg_DllName_Window"));
        Alg_DllName_Window->resize(517, 375);
        pushButton = new QPushButton(Alg_DllName_Window);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 170, 75, 23));

        retranslateUi(Alg_DllName_Window);

        QMetaObject::connectSlotsByName(Alg_DllName_Window);
    } // setupUi

    void retranslateUi(QWidget *Alg_DllName_Window)
    {
        Alg_DllName_Window->setWindowTitle(QApplication::translate("Alg_DllName_Window", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Alg_DllName_Window", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Alg_DllName_Window: public Ui_Alg_DllName_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGETOOLWINDOW_H
