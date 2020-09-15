/********************************************************************************
** Form generated from reading UI file 'MsgBrowse.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGBROWSE_H
#define UI_MSGBROWSE_H

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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MsgBrowseWindow
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_remarks;
    QTextBrowser *text_content;
    QTextBrowser *text_title;

    void setupUi(QDialog *MsgBrowseWindow)
    {
        if (MsgBrowseWindow->objectName().isEmpty())
            MsgBrowseWindow->setObjectName(QStringLiteral("MsgBrowseWindow"));
        MsgBrowseWindow->resize(400, 300);
        layoutWidget = new QWidget(MsgBrowseWindow);
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

        label = new QLabel(MsgBrowseWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 54, 12));
        label_2 = new QLabel(MsgBrowseWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 54, 12));
        label_3 = new QLabel(MsgBrowseWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 180, 54, 12));
        label_remarks = new QLabel(MsgBrowseWindow);
        label_remarks->setObjectName(QStringLiteral("label_remarks"));
        label_remarks->setGeometry(QRect(80, 180, 211, 51));
        text_content = new QTextBrowser(MsgBrowseWindow);
        text_content->setObjectName(QStringLiteral("text_content"));
        text_content->setGeometry(QRect(71, 69, 281, 101));
        text_title = new QTextBrowser(MsgBrowseWindow);
        text_title->setObjectName(QStringLiteral("text_title"));
        text_title->setGeometry(QRect(70, 26, 281, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        text_title->setFont(font);

        retranslateUi(MsgBrowseWindow);
        QObject::connect(okButton, SIGNAL(clicked()), MsgBrowseWindow, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), MsgBrowseWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(MsgBrowseWindow);
    } // setupUi

    void retranslateUi(QDialog *MsgBrowseWindow)
    {
        MsgBrowseWindow->setWindowTitle(QApplication::translate("MsgBrowseWindow", "Browse", Q_NULLPTR));
        okButton->setText(QApplication::translate("MsgBrowseWindow", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("MsgBrowseWindow", "Cancel", Q_NULLPTR));
        label->setText(QApplication::translate("MsgBrowseWindow", "\346\240\207\351\242\230\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MsgBrowseWindow", "\345\206\205\345\256\271\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("MsgBrowseWindow", "\345\244\207\346\263\250\357\274\232", Q_NULLPTR));
        label_remarks->setText(QApplication::translate("MsgBrowseWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MsgBrowseWindow: public Ui_MsgBrowseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGBROWSE_H
