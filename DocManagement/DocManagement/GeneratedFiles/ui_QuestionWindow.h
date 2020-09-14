/********************************************************************************
** Form generated from reading UI file 'QuestionWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONWINDOW_H
#define UI_QUESTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionWindow
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineedit_search_string;
    QPushButton *btn_search;
    QComboBox *comboBox_label;
    QPushButton *btn_empty;
    QPushButton *AddButton;
    QTableView *tableView;

    void setupUi(QWidget *QuestionWindow)
    {
        if (QuestionWindow->objectName().isEmpty())
            QuestionWindow->setObjectName(QStringLiteral("QuestionWindow"));
        QuestionWindow->resize(906, 555);
        gridLayout_3 = new QGridLayout(QuestionWindow);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        widget = new QWidget(QuestionWindow);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineedit_search_string = new QLineEdit(widget);
        lineedit_search_string->setObjectName(QStringLiteral("lineedit_search_string"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineedit_search_string->sizePolicy().hasHeightForWidth());
        lineedit_search_string->setSizePolicy(sizePolicy);
        lineedit_search_string->setMinimumSize(QSize(191, 20));
        lineedit_search_string->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(lineedit_search_string);

        btn_search = new QPushButton(widget);
        btn_search->setObjectName(QStringLiteral("btn_search"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_search->sizePolicy().hasHeightForWidth());
        btn_search->setSizePolicy(sizePolicy1);
        btn_search->setMinimumSize(QSize(30, 23));
        btn_search->setMaximumSize(QSize(30, 23));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/search.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_search->setIcon(icon);

        horizontalLayout->addWidget(btn_search);

        comboBox_label = new QComboBox(widget);
        comboBox_label->setObjectName(QStringLiteral("comboBox_label"));
        sizePolicy.setHeightForWidth(comboBox_label->sizePolicy().hasHeightForWidth());
        comboBox_label->setSizePolicy(sizePolicy);
        comboBox_label->setMinimumSize(QSize(100, 22));
        comboBox_label->setMaximumSize(QSize(100, 22));

        horizontalLayout->addWidget(comboBox_label);

        btn_empty = new QPushButton(widget);
        btn_empty->setObjectName(QStringLiteral("btn_empty"));
        sizePolicy.setHeightForWidth(btn_empty->sizePolicy().hasHeightForWidth());
        btn_empty->setSizePolicy(sizePolicy);
        btn_empty->setMinimumSize(QSize(35, 23));
        btn_empty->setMaximumSize(QSize(41, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/sync.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_empty->setIcon(icon1);

        horizontalLayout->addWidget(btn_empty);

        AddButton = new QPushButton(widget);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        sizePolicy.setHeightForWidth(AddButton->sizePolicy().hasHeightForWidth());
        AddButton->setSizePolicy(sizePolicy);
        AddButton->setMinimumSize(QSize(60, 23));
        AddButton->setMaximumSize(QSize(75, 23));

        horizontalLayout->addWidget(AddButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableView = new QTableView(widget);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(QuestionWindow);

        QMetaObject::connectSlotsByName(QuestionWindow);
    } // setupUi

    void retranslateUi(QWidget *QuestionWindow)
    {
        QuestionWindow->setWindowTitle(QApplication::translate("QuestionWindow", "Form", Q_NULLPTR));
        btn_search->setText(QString());
        btn_empty->setText(QString());
        AddButton->setText(QApplication::translate("QuestionWindow", "\346\226\260\345\273\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QuestionWindow: public Ui_QuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONWINDOW_H
