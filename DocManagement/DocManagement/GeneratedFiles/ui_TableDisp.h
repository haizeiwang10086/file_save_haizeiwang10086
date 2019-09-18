/********************************************************************************
** Form generated from reading UI file 'TableDisp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEDISP_H
#define UI_TABLEDISP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableDisp
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *TableDisp)
    {
        if (TableDisp->objectName().isEmpty())
            TableDisp->setObjectName(QStringLiteral("TableDisp"));
        TableDisp->resize(400, 300);
        tableWidget = new QTableWidget(TableDisp);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(80, 40, 291, 231));

        retranslateUi(TableDisp);

        QMetaObject::connectSlotsByName(TableDisp);
    } // setupUi

    void retranslateUi(QWidget *TableDisp)
    {
        TableDisp->setWindowTitle(QApplication::translate("TableDisp", "TableDisp", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TableDisp: public Ui_TableDisp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEDISP_H
