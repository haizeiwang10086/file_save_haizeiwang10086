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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BatchEditFileName
{
public:
    QGroupBox *gbBatchEditName;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *Directory;
    QToolButton *toolButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *preContant;
    QLineEdit *le_NameFormat;
    QPushButton *BtnModify;
    QGroupBox *gbImageFormatTrans;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lName2;
    QComboBox *cbImageFormatList;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *leImageDirectory;
    QToolButton *btnImageDirectory;
    QPushButton *btnCvtFormat;

    void setupUi(QWidget *BatchEditFileName)
    {
        if (BatchEditFileName->objectName().isEmpty())
            BatchEditFileName->setObjectName(QStringLiteral("BatchEditFileName"));
        BatchEditFileName->resize(819, 359);
        gbBatchEditName = new QGroupBox(BatchEditFileName);
        gbBatchEditName->setObjectName(QStringLiteral("gbBatchEditName"));
        gbBatchEditName->setGeometry(QRect(11, 11, 340, 110));
        gbBatchEditName->setMinimumSize(QSize(340, 110));
        gbBatchEditName->setMaximumSize(QSize(340, 110));
        layoutWidget = new QWidget(gbBatchEditName);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 23, 311, 71));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Directory = new QLineEdit(layoutWidget);
        Directory->setObjectName(QStringLiteral("Directory"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Directory->sizePolicy().hasHeightForWidth());
        Directory->setSizePolicy(sizePolicy);
        Directory->setMaxLength(32767);

        horizontalLayout->addWidget(Directory);

        toolButton = new QToolButton(layoutWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        sizePolicy.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(toolButton);

        horizontalLayout->setStretch(0, 8);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        preContant = new QLabel(layoutWidget);
        preContant->setObjectName(QStringLiteral("preContant"));
        sizePolicy.setHeightForWidth(preContant->sizePolicy().hasHeightForWidth());
        preContant->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(preContant);

        le_NameFormat = new QLineEdit(layoutWidget);
        le_NameFormat->setObjectName(QStringLiteral("le_NameFormat"));
        sizePolicy.setHeightForWidth(le_NameFormat->sizePolicy().hasHeightForWidth());
        le_NameFormat->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(le_NameFormat);

        BtnModify = new QPushButton(layoutWidget);
        BtnModify->setObjectName(QStringLiteral("BtnModify"));
        sizePolicy.setHeightForWidth(BtnModify->sizePolicy().hasHeightForWidth());
        BtnModify->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(BtnModify);

        horizontalLayout_2->setStretch(0, 15);
        horizontalLayout_2->setStretch(1, 70);
        horizontalLayout_2->setStretch(2, 15);

        verticalLayout->addLayout(horizontalLayout_2);

        gbImageFormatTrans = new QGroupBox(BatchEditFileName);
        gbImageFormatTrans->setObjectName(QStringLiteral("gbImageFormatTrans"));
        gbImageFormatTrans->setGeometry(QRect(357, 11, 340, 110));
        gbImageFormatTrans->setMinimumSize(QSize(340, 110));
        gbImageFormatTrans->setMaximumSize(QSize(340, 110));
        layoutWidget1 = new QWidget(gbImageFormatTrans);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 20, 128, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lName2 = new QLabel(layoutWidget1);
        lName2->setObjectName(QStringLiteral("lName2"));
        sizePolicy.setHeightForWidth(lName2->sizePolicy().hasHeightForWidth());
        lName2->setSizePolicy(sizePolicy);
        lName2->setMinimumSize(QSize(50, 29));
        lName2->setMaximumSize(QSize(50, 29));

        horizontalLayout_3->addWidget(lName2);

        cbImageFormatList = new QComboBox(layoutWidget1);
        cbImageFormatList->setObjectName(QStringLiteral("cbImageFormatList"));
        cbImageFormatList->setMinimumSize(QSize(70, 29));
        cbImageFormatList->setMaximumSize(QSize(70, 29));

        horizontalLayout_3->addWidget(cbImageFormatList);

        layoutWidget2 = new QWidget(gbImageFormatTrans);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 60, 311, 32));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        leImageDirectory = new QLineEdit(layoutWidget2);
        leImageDirectory->setObjectName(QStringLiteral("leImageDirectory"));
        sizePolicy.setHeightForWidth(leImageDirectory->sizePolicy().hasHeightForWidth());
        leImageDirectory->setSizePolicy(sizePolicy);
        leImageDirectory->setMinimumSize(QSize(268, 30));
        leImageDirectory->setMaximumSize(QSize(268, 30));
        leImageDirectory->setMaxLength(32767);

        horizontalLayout_4->addWidget(leImageDirectory);

        btnImageDirectory = new QToolButton(layoutWidget2);
        btnImageDirectory->setObjectName(QStringLiteral("btnImageDirectory"));
        sizePolicy.setHeightForWidth(btnImageDirectory->sizePolicy().hasHeightForWidth());
        btnImageDirectory->setSizePolicy(sizePolicy);
        btnImageDirectory->setMinimumSize(QSize(35, 30));
        btnImageDirectory->setMaximumSize(QSize(35, 30));

        horizontalLayout_4->addWidget(btnImageDirectory);

        btnCvtFormat = new QPushButton(gbImageFormatTrans);
        btnCvtFormat->setObjectName(QStringLiteral("btnCvtFormat"));
        btnCvtFormat->setGeometry(QRect(290, 20, 44, 29));
        sizePolicy.setHeightForWidth(btnCvtFormat->sizePolicy().hasHeightForWidth());
        btnCvtFormat->setSizePolicy(sizePolicy);

        retranslateUi(BatchEditFileName);

        QMetaObject::connectSlotsByName(BatchEditFileName);
    } // setupUi

    void retranslateUi(QWidget *BatchEditFileName)
    {
        BatchEditFileName->setWindowTitle(QApplication::translate("BatchEditFileName", "Form", Q_NULLPTR));
        gbBatchEditName->setTitle(QApplication::translate("BatchEditFileName", "\346\211\271\351\207\217\346\224\271\345\220\215", Q_NULLPTR));
        Directory->setInputMask(QString());
        Directory->setText(QString());
        toolButton->setText(QApplication::translate("BatchEditFileName", "...", Q_NULLPTR));
        preContant->setText(QApplication::translate("BatchEditFileName", "\346\240\274\345\274\217\357\274\232", Q_NULLPTR));
        le_NameFormat->setInputMask(QString());
        BtnModify->setText(QApplication::translate("BatchEditFileName", "\344\277\256\346\224\271", Q_NULLPTR));
        gbImageFormatTrans->setTitle(QApplication::translate("BatchEditFileName", "\346\211\271\351\207\217\345\233\276\345\203\217\346\240\274\345\274\217\350\275\254\346\215\242", Q_NULLPTR));
        lName2->setText(QApplication::translate("BatchEditFileName", "\350\275\254\346\215\242\344\270\272\357\274\232", Q_NULLPTR));
        leImageDirectory->setInputMask(QString());
        leImageDirectory->setText(QString());
        btnImageDirectory->setText(QApplication::translate("BatchEditFileName", "...", Q_NULLPTR));
        btnCvtFormat->setText(QApplication::translate("BatchEditFileName", "\350\275\254\346\215\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BatchEditFileName: public Ui_BatchEditFileName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATCHEDITFILENAME_H
