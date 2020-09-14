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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_ExtDlg
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QToolButton *btn_filePath;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ExtDlg)
    {
        if (ExtDlg->objectName().isEmpty())
            ExtDlg->setObjectName(QStringLiteral("ExtDlg"));
        ExtDlg->resize(500, 123);
        ExtDlg->setMinimumSize(QSize(500, 123));
        ExtDlg->setMaximumSize(QSize(500, 123));
        gridLayout = new QGridLayout(ExtDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(ExtDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(45, 20));
        label_2->setMaximumSize(QSize(45, 20));

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(ExtDlg);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(100, 22));
        comboBox->setMaximumSize(QSize(100, 22));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(ExtDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(45, 20));
        label->setMaximumSize(QSize(45, 20));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(ExtDlg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 20));
        lineEdit->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_2->addWidget(lineEdit);

        btn_filePath = new QToolButton(ExtDlg);
        btn_filePath->setObjectName(QStringLiteral("btn_filePath"));
        btn_filePath->setMinimumSize(QSize(37, 20));
        btn_filePath->setMaximumSize(QSize(37, 20));

        horizontalLayout_2->addWidget(btn_filePath);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(ExtDlg);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setMinimumSize(QSize(80, 23));
        okButton->setMaximumSize(QSize(80, 23));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(ExtDlg);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMinimumSize(QSize(80, 23));
        cancelButton->setMaximumSize(QSize(80, 23));

        hboxLayout->addWidget(cancelButton);


        gridLayout->addLayout(hboxLayout, 2, 0, 1, 1);


        retranslateUi(ExtDlg);
        QObject::connect(cancelButton, SIGNAL(clicked()), ExtDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExtDlg);
    } // setupUi

    void retranslateUi(QDialog *ExtDlg)
    {
        ExtDlg->setWindowTitle(QApplication::translate("ExtDlg", "\345\257\274\345\207\272", Q_NULLPTR));
        label_2->setText(QApplication::translate("ExtDlg", "\347\261\273\345\236\213:", Q_NULLPTR));
        label->setText(QApplication::translate("ExtDlg", "\350\267\257\345\276\204:", Q_NULLPTR));
        btn_filePath->setText(QApplication::translate("ExtDlg", "...", Q_NULLPTR));
        okButton->setText(QApplication::translate("ExtDlg", "ok", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("ExtDlg", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExtDlg: public Ui_ExtDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTDLG_H
