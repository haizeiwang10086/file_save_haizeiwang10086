/********************************************************************************
** Form generated from reading UI file 'QuestionBrowse.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONBROWSE_H
#define UI_QUESTIONBROWSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_BrowseWindow
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QTextBrowser *text_content;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *BrowseWindow)
    {
        if (BrowseWindow->objectName().isEmpty())
            BrowseWindow->setObjectName(QStringLiteral("BrowseWindow"));
        BrowseWindow->resize(400, 300);
        gridLayout_2 = new QGridLayout(BrowseWindow);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        text_content = new QTextBrowser(BrowseWindow);
        text_content->setObjectName(QStringLiteral("text_content"));

        gridLayout->addWidget(text_content, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(BrowseWindow);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setMinimumSize(QSize(75, 23));
        okButton->setMaximumSize(QSize(75, 23));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(BrowseWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMinimumSize(QSize(75, 23));
        cancelButton->setMaximumSize(QSize(75, 23));

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(BrowseWindow);
        QObject::connect(okButton, SIGNAL(clicked()), BrowseWindow, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), BrowseWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(BrowseWindow);
    } // setupUi

    void retranslateUi(QDialog *BrowseWindow)
    {
        BrowseWindow->setWindowTitle(QApplication::translate("BrowseWindow", "Browse", Q_NULLPTR));
        okButton->setText(QApplication::translate("BrowseWindow", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("BrowseWindow", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BrowseWindow: public Ui_BrowseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONBROWSE_H
