/********************************************************************************
** Form generated from reading UI file 'Alg_DeepLearning_Window.ui'
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

class Ui_Alg_DeepLearning_Window
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *Alg_DeepLearning_Window)
    {
        if (Alg_DeepLearning_Window->objectName().isEmpty())
            Alg_DeepLearning_Window->setObjectName(QStringLiteral("Alg_DeepLearning_Window"));
        Alg_DeepLearning_Window->resize(517, 375);
        pushButton = new QPushButton(Alg_DeepLearning_Window);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 170, 75, 23));

        retranslateUi(Alg_DeepLearning_Window);

        QMetaObject::connectSlotsByName(Alg_DeepLearning_Window);
    } // setupUi

    void retranslateUi(QWidget *Alg_DeepLearning_Window)
    {
        Alg_DeepLearning_Window->setWindowTitle(QApplication::translate("Alg_DeepLearning_Window", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Alg_DeepLearning_Window", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Alg_DeepLearning_Window: public Ui_Alg_DeepLearning_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGETOOLWINDOW_H
