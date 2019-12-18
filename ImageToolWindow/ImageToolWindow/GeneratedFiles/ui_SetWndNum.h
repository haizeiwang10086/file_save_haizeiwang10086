/********************************************************************************
** Form generated from reading UI file 'SetWndNum.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETWNDNUM_H
#define UI_SETWNDNUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetWndNum
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLineEdit *line_edit;
    QLabel *label;

    void setupUi(QDialog *SetWndNum)
    {
        if (SetWndNum->objectName().isEmpty())
            SetWndNum->setObjectName(QStringLiteral("SetWndNum"));
        SetWndNum->resize(400, 300);
        layoutWidget = new QWidget(SetWndNum);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 250, 351, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);

        line_edit = new QLineEdit(SetWndNum);
        line_edit->setObjectName(QStringLiteral("line_edit"));
        line_edit->setGeometry(QRect(142, 95, 113, 20));
        label = new QLabel(SetWndNum);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 100, 54, 12));

        retranslateUi(SetWndNum);
        QObject::connect(okButton, SIGNAL(clicked()), SetWndNum, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), SetWndNum, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetWndNum);
    } // setupUi

    void retranslateUi(QDialog *SetWndNum)
    {
        SetWndNum->setWindowTitle(QApplication::translate("SetWndNum", "Dialog", Q_NULLPTR));
        okButton->setText(QApplication::translate("SetWndNum", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("SetWndNum", "Cancel", Q_NULLPTR));
        label->setText(QApplication::translate("SetWndNum", "\347\252\227\345\217\243\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetWndNum: public Ui_SetWndNum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETWNDNUM_H
