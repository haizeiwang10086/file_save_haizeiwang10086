/********************************************************************************
** Form generated from reading UI file 'NewDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDLG_H
#define UI_NEWDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddWindow
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *title;
    QLineEdit *lineEdit;
    QToolButton *selectButton;
    QGridLayout *gridLayout;
    QLabel *lblRemarks;
    QTextEdit *teRemarks;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *save;
    QPushButton *cancleButton;

    void setupUi(QWidget *AddWindow)
    {
        if (AddWindow->objectName().isEmpty())
            AddWindow->setObjectName(QStringLiteral("AddWindow"));
        AddWindow->setEnabled(true);
        AddWindow->resize(400, 200);
        AddWindow->setMinimumSize(QSize(400, 200));
        AddWindow->setMaximumSize(QSize(400, 200));
        gridLayout_2 = new QGridLayout(AddWindow);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        title = new QLabel(AddWindow);
        title->setObjectName(QStringLiteral("title"));
        title->setMinimumSize(QSize(65, 20));
        title->setMaximumSize(QSize(65, 20));

        horizontalLayout->addWidget(title);

        lineEdit = new QLineEdit(AddWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setMinimumSize(QSize(0, 20));
        lineEdit->setMaximumSize(QSize(16777215, 20));
        lineEdit->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(lineEdit);

        selectButton = new QToolButton(AddWindow);
        selectButton->setObjectName(QStringLiteral("selectButton"));
        selectButton->setMinimumSize(QSize(37, 20));
        selectButton->setMaximumSize(QSize(37, 20));

        horizontalLayout->addWidget(selectButton);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblRemarks = new QLabel(AddWindow);
        lblRemarks->setObjectName(QStringLiteral("lblRemarks"));
        lblRemarks->setMinimumSize(QSize(65, 20));
        lblRemarks->setMaximumSize(QSize(65, 20));

        gridLayout->addWidget(lblRemarks, 0, 0, 1, 1);

        teRemarks = new QTextEdit(AddWindow);
        teRemarks->setObjectName(QStringLiteral("teRemarks"));

        gridLayout->addWidget(teRemarks, 0, 1, 2, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        save = new QPushButton(AddWindow);
        save->setObjectName(QStringLiteral("save"));
        save->setMinimumSize(QSize(65, 23));
        save->setMaximumSize(QSize(65, 23));

        horizontalLayout_2->addWidget(save);

        cancleButton = new QPushButton(AddWindow);
        cancleButton->setObjectName(QStringLiteral("cancleButton"));
        cancleButton->setMinimumSize(QSize(65, 23));
        cancleButton->setMaximumSize(QSize(65, 23));

        horizontalLayout_2->addWidget(cancleButton);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(AddWindow);

        QMetaObject::connectSlotsByName(AddWindow);
    } // setupUi

    void retranslateUi(QWidget *AddWindow)
    {
        AddWindow->setWindowTitle(QApplication::translate("AddWindow", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("AddWindow", "\346\226\207\344\273\266\345\220\215\357\274\232", Q_NULLPTR));
        selectButton->setText(QApplication::translate("AddWindow", "...", Q_NULLPTR));
        lblRemarks->setText(QApplication::translate("AddWindow", "\345\244\207\346\263\250:", Q_NULLPTR));
        save->setText(QApplication::translate("AddWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        cancleButton->setText(QApplication::translate("AddWindow", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddWindow: public Ui_AddWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDLG_H
