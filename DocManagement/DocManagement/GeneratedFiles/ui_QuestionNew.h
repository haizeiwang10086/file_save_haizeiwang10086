/********************************************************************************
** Form generated from reading UI file 'QuestionNew.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONNEW_H
#define UI_QUESTIONNEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewWindow
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *title;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout;
    QLabel *content;
    QTextEdit *textEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnT1;
    QPushButton *btnT2;
    QPushButton *save;
    QPushButton *btn_modify;
    QComboBox *comboBox_label;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *NewWindow)
    {
        if (NewWindow->objectName().isEmpty())
            NewWindow->setObjectName(QStringLiteral("NewWindow"));
        NewWindow->resize(686, 421);
        NewWindow->setMinimumSize(QSize(600, 400));
        gridLayout_3 = new QGridLayout(NewWindow);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        title = new QLabel(NewWindow);
        title->setObjectName(QStringLiteral("title"));
        title->setMinimumSize(QSize(45, 20));
        title->setMaximumSize(QSize(45, 20));

        horizontalLayout->addWidget(title);

        lineEdit = new QLineEdit(NewWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 20));
        lineEdit->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(lineEdit);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        content = new QLabel(NewWindow);
        content->setObjectName(QStringLiteral("content"));
        content->setMinimumSize(QSize(45, 20));
        content->setMaximumSize(QSize(45, 20));

        gridLayout->addWidget(content, 0, 0, 1, 1);

        textEdit = new QTextEdit(NewWindow);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 0, 1, 2, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnT1 = new QPushButton(NewWindow);
        btnT1->setObjectName(QStringLiteral("btnT1"));
        btnT1->setMinimumSize(QSize(65, 23));
        btnT1->setMaximumSize(QSize(65, 23));

        horizontalLayout_2->addWidget(btnT1);

        btnT2 = new QPushButton(NewWindow);
        btnT2->setObjectName(QStringLiteral("btnT2"));
        btnT2->setMinimumSize(QSize(65, 23));
        btnT2->setMaximumSize(QSize(65, 23));

        horizontalLayout_2->addWidget(btnT2);

        save = new QPushButton(NewWindow);
        save->setObjectName(QStringLiteral("save"));
        save->setMinimumSize(QSize(65, 23));
        save->setMaximumSize(QSize(65, 23));

        horizontalLayout_2->addWidget(save);

        btn_modify = new QPushButton(NewWindow);
        btn_modify->setObjectName(QStringLiteral("btn_modify"));
        btn_modify->setMinimumSize(QSize(65, 23));
        btn_modify->setMaximumSize(QSize(65, 23));

        horizontalLayout_2->addWidget(btn_modify);

        comboBox_label = new QComboBox(NewWindow);
        comboBox_label->setObjectName(QStringLiteral("comboBox_label"));
        comboBox_label->setMinimumSize(QSize(100, 22));
        comboBox_label->setMaximumSize(QSize(100, 22));

        horizontalLayout_2->addWidget(comboBox_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(NewWindow);

        QMetaObject::connectSlotsByName(NewWindow);
    } // setupUi

    void retranslateUi(QWidget *NewWindow)
    {
        NewWindow->setWindowTitle(QApplication::translate("NewWindow", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("NewWindow", "\346\240\207\351\242\230\357\274\232", Q_NULLPTR));
        content->setText(QApplication::translate("NewWindow", "\345\206\205\345\256\271\357\274\232", Q_NULLPTR));
        btnT1->setText(QApplication::translate("NewWindow", "\344\270\200\347\272\247\346\240\207\351\242\230", Q_NULLPTR));
        btnT2->setText(QApplication::translate("NewWindow", "\344\272\214\347\272\247\346\240\207\351\242\230", Q_NULLPTR));
        save->setText(QApplication::translate("NewWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        btn_modify->setText(QApplication::translate("NewWindow", "\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewWindow: public Ui_NewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONNEW_H
