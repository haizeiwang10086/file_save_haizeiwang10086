/********************************************************************************
** Form generated from reading UI file 'DispRemarks.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPREMARKS_H
#define UI_DISPREMARKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DispRemarks
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label;

    void setupUi(QDialog *DispRemarks)
    {
        if (DispRemarks->objectName().isEmpty())
            DispRemarks->setObjectName(QStringLiteral("DispRemarks"));
        DispRemarks->resize(400, 300);
        layoutWidget = new QWidget(DispRemarks);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 240, 351, 33));
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

        label = new QLabel(DispRemarks);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 340, 220));
        label->setMinimumSize(QSize(340, 220));
        label->setMaximumSize(QSize(340, 220));
        label->setTextFormat(Qt::AutoText);

        retranslateUi(DispRemarks);
        QObject::connect(okButton, SIGNAL(clicked()), DispRemarks, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), DispRemarks, SLOT(reject()));

        QMetaObject::connectSlotsByName(DispRemarks);
    } // setupUi

    void retranslateUi(QDialog *DispRemarks)
    {
        DispRemarks->setWindowTitle(QApplication::translate("DispRemarks", "Dialog", Q_NULLPTR));
        okButton->setText(QApplication::translate("DispRemarks", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("DispRemarks", "Cancel", Q_NULLPTR));
        label->setText(QApplication::translate("DispRemarks", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DispRemarks: public Ui_DispRemarks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPREMARKS_H
