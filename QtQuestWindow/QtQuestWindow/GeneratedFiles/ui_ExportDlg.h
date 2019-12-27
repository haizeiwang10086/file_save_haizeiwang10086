/********************************************************************************
** Form generated from reading UI file 'ExportDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTDLG_H
#define UI_EXPORTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExtDlg
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QToolButton *btn_filePath;
    QComboBox *comboBox;

    void setupUi(QDialog *ExtDlg)
    {
        if (ExtDlg->objectName().isEmpty())
            ExtDlg->setObjectName(QStringLiteral("ExtDlg"));
        ExtDlg->resize(400, 300);
        layoutWidget = new QWidget(ExtDlg);
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

        label = new QLabel(ExtDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 153, 31, 16));
        lineEdit = new QLineEdit(ExtDlg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 153, 191, 20));
        label_2 = new QLabel(ExtDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 129, 31, 16));
        btn_filePath = new QToolButton(ExtDlg);
        btn_filePath->setObjectName(QStringLiteral("btn_filePath"));
        btn_filePath->setGeometry(QRect(299, 153, 37, 20));
        comboBox = new QComboBox(ExtDlg);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(100, 127, 69, 22));

        retranslateUi(ExtDlg);
        QObject::connect(cancelButton, SIGNAL(clicked()), ExtDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExtDlg);
    } // setupUi

    void retranslateUi(QDialog *ExtDlg)
    {
        ExtDlg->setWindowTitle(QApplication::translate("ExtDlg", "\345\257\274\345\207\272", Q_NULLPTR));
        okButton->setText(QApplication::translate("ExtDlg", "ok", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("ExtDlg", "Cancel", Q_NULLPTR));
        label->setText(QApplication::translate("ExtDlg", "\350\267\257\345\276\204:", Q_NULLPTR));
        label_2->setText(QApplication::translate("ExtDlg", "\347\261\273\345\236\213:", Q_NULLPTR));
        btn_filePath->setText(QApplication::translate("ExtDlg", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExtDlg: public Ui_ExtDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTDLG_H
