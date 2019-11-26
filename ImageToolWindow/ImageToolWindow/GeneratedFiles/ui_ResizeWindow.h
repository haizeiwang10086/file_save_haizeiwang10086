/********************************************************************************
** Form generated from reading UI file 'ResizeWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIZEWINDOW_H
#define UI_RESIZEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResizeDlg
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *save;
    QPushButton *cancelButton;
    QPushButton *routeBtn;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QLabel *height;
    QLineEdit *height_edit;
    QLabel *width;
    QLineEdit *width_edit;
    QWidget *layoutWidget2;
    QFormLayout *formLayout_2;
    QLabel *route;
    QLineEdit *route_edit;
    QRadioButton *aspect_ratio;

    void setupUi(QDialog *ResizeDlg)
    {
        if (ResizeDlg->objectName().isEmpty())
            ResizeDlg->setObjectName(QStringLiteral("ResizeDlg"));
        ResizeDlg->resize(400, 300);
        layoutWidget = new QWidget(ResizeDlg);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 250, 351, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        save = new QPushButton(layoutWidget);
        save->setObjectName(QStringLiteral("save"));

        hboxLayout->addWidget(save);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);

        routeBtn = new QPushButton(ResizeDlg);
        routeBtn->setObjectName(QStringLiteral("routeBtn"));
        routeBtn->setGeometry(QRect(340, 163, 41, 23));
        layoutWidget1 = new QWidget(ResizeDlg);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(70, 105, 171, 51));
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        height = new QLabel(layoutWidget1);
        height->setObjectName(QStringLiteral("height"));

        formLayout->setWidget(0, QFormLayout::LabelRole, height);

        height_edit = new QLineEdit(layoutWidget1);
        height_edit->setObjectName(QStringLiteral("height_edit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, height_edit);

        width = new QLabel(layoutWidget1);
        width->setObjectName(QStringLiteral("width"));

        formLayout->setWidget(1, QFormLayout::LabelRole, width);

        width_edit = new QLineEdit(layoutWidget1);
        width_edit->setObjectName(QStringLiteral("width_edit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, width_edit);

        layoutWidget2 = new QWidget(ResizeDlg);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(70, 163, 261, 22));
        formLayout_2 = new QFormLayout(layoutWidget2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        route = new QLabel(layoutWidget2);
        route->setObjectName(QStringLiteral("route"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, route);

        route_edit = new QLineEdit(layoutWidget2);
        route_edit->setObjectName(QStringLiteral("route_edit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, route_edit);

        aspect_ratio = new QRadioButton(ResizeDlg);
        aspect_ratio->setObjectName(QStringLiteral("aspect_ratio"));
        aspect_ratio->setGeometry(QRect(70, 80, 89, 16));
        aspect_ratio->setChecked(false);

        retranslateUi(ResizeDlg);
        QObject::connect(cancelButton, SIGNAL(clicked()), ResizeDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(ResizeDlg);
    } // setupUi

    void retranslateUi(QDialog *ResizeDlg)
    {
        ResizeDlg->setWindowTitle(QApplication::translate("ResizeDlg", "Dialog", Q_NULLPTR));
        save->setText(QApplication::translate("ResizeDlg", "\344\277\235\345\255\230", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("ResizeDlg", "\345\217\226\346\266\210", Q_NULLPTR));
        routeBtn->setText(QApplication::translate("ResizeDlg", "...", Q_NULLPTR));
        height->setText(QApplication::translate("ResizeDlg", "\351\253\230\345\272\246:", Q_NULLPTR));
        width->setText(QApplication::translate("ResizeDlg", "\345\256\275\345\272\246:", Q_NULLPTR));
        route->setText(QApplication::translate("ResizeDlg", "\350\267\257\345\276\204:", Q_NULLPTR));
        aspect_ratio->setText(QApplication::translate("ResizeDlg", "\344\277\235\346\214\201\351\225\277\345\256\275\346\257\224", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ResizeDlg: public Ui_ResizeDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZEWINDOW_H
