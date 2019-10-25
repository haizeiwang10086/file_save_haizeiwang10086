/********************************************************************************
** Form generated from reading UI file 'BatchEditFileName.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATCHEDITFILENAME_H
#define UI_BATCHEDITFILENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BatchEditFileName
{
public:
    QToolButton *toolButton;
    QLineEdit *Directory;
    QLabel *preContant;
    QLabel *Suffix;
    QLineEdit *lineEditPre;
    QLineEdit *lineEditSuf;
    QLineEdit *lineEditDevName;
    QLabel *DevName;
    QPushButton *BtnModify;

    void setupUi(QWidget *BatchEditFileName)
    {
        if (BatchEditFileName->objectName().isEmpty())
            BatchEditFileName->setObjectName(QStringLiteral("BatchEditFileName"));
        BatchEditFileName->resize(400, 300);
        toolButton = new QToolButton(BatchEditFileName);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(280, 20, 37, 18));
        Directory = new QLineEdit(BatchEditFileName);
        Directory->setObjectName(QStringLiteral("Directory"));
        Directory->setGeometry(QRect(30, 20, 241, 20));
        Directory->setMaxLength(32767);
        preContant = new QLabel(BatchEditFileName);
        preContant->setObjectName(QStringLiteral("preContant"));
        preContant->setGeometry(QRect(30, 50, 41, 21));
        Suffix = new QLabel(BatchEditFileName);
        Suffix->setObjectName(QStringLiteral("Suffix"));
        Suffix->setGeometry(QRect(30, 80, 54, 12));
        lineEditPre = new QLineEdit(BatchEditFileName);
        lineEditPre->setObjectName(QStringLiteral("lineEditPre"));
        lineEditPre->setGeometry(QRect(80, 50, 113, 20));
        lineEditSuf = new QLineEdit(BatchEditFileName);
        lineEditSuf->setObjectName(QStringLiteral("lineEditSuf"));
        lineEditSuf->setGeometry(QRect(80, 80, 113, 20));
        lineEditDevName = new QLineEdit(BatchEditFileName);
        lineEditDevName->setObjectName(QStringLiteral("lineEditDevName"));
        lineEditDevName->setGeometry(QRect(80, 110, 113, 20));
        DevName = new QLabel(BatchEditFileName);
        DevName->setObjectName(QStringLiteral("DevName"));
        DevName->setGeometry(QRect(30, 110, 54, 12));
        BtnModify = new QPushButton(BatchEditFileName);
        BtnModify->setObjectName(QStringLiteral("BtnModify"));
        BtnModify->setGeometry(QRect(240, 80, 75, 23));

        retranslateUi(BatchEditFileName);

        QMetaObject::connectSlotsByName(BatchEditFileName);
    } // setupUi

    void retranslateUi(QWidget *BatchEditFileName)
    {
        BatchEditFileName->setWindowTitle(QApplication::translate("BatchEditFileName", "Form", Q_NULLPTR));
        toolButton->setText(QApplication::translate("BatchEditFileName", "...", Q_NULLPTR));
        Directory->setInputMask(QString());
        Directory->setText(QString());
        preContant->setText(QApplication::translate("BatchEditFileName", "\345\211\215\347\274\200\357\274\232", Q_NULLPTR));
        Suffix->setText(QApplication::translate("BatchEditFileName", "\345\220\216\347\274\200\357\274\232", Q_NULLPTR));
        DevName->setText(QApplication::translate("BatchEditFileName", "\346\213\223\345\261\225\345\220\215\357\274\232", Q_NULLPTR));
        BtnModify->setText(QApplication::translate("BatchEditFileName", "\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BatchEditFileName: public Ui_BatchEditFileName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATCHEDITFILENAME_H
