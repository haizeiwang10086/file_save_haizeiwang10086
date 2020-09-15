/********************************************************************************
** Form generated from reading UI file 'MsgBackupWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGBACKUPWINDOW_H
#define UI_MSGBACKUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MsgBackupWindow
{
public:
    QTableView *tableView;
    QPushButton *AddButton;
    QPushButton *RecoverButton;
    QPushButton *EditButton;

    void setupUi(QWidget *MsgBackupWindow)
    {
        if (MsgBackupWindow->objectName().isEmpty())
            MsgBackupWindow->setObjectName(QStringLiteral("MsgBackupWindow"));
        MsgBackupWindow->resize(517, 375);
        tableView = new QTableView(MsgBackupWindow);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(61, 31, 361, 241));
        AddButton = new QPushButton(MsgBackupWindow);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setGeometry(QRect(80, 300, 75, 23));
        RecoverButton = new QPushButton(MsgBackupWindow);
        RecoverButton->setObjectName(QStringLiteral("RecoverButton"));
        RecoverButton->setGeometry(QRect(290, 300, 75, 23));
        EditButton = new QPushButton(MsgBackupWindow);
        EditButton->setObjectName(QStringLiteral("EditButton"));
        EditButton->setGeometry(QRect(180, 300, 75, 23));
        QIcon icon;
        icon.addFile(QStringLiteral("images/sync.ico"), QSize(), QIcon::Normal, QIcon::Off);
        EditButton->setIcon(icon);

        retranslateUi(MsgBackupWindow);

        QMetaObject::connectSlotsByName(MsgBackupWindow);
    } // setupUi

    void retranslateUi(QWidget *MsgBackupWindow)
    {
        MsgBackupWindow->setWindowTitle(QApplication::translate("MsgBackupWindow", "Form", Q_NULLPTR));
        AddButton->setText(QApplication::translate("MsgBackupWindow", "\346\226\260\345\273\272", Q_NULLPTR));
        RecoverButton->setText(QApplication::translate("MsgBackupWindow", "\346\222\244\345\233\236", Q_NULLPTR));
        EditButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MsgBackupWindow: public Ui_MsgBackupWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGBACKUPWINDOW_H
