#include "SetWndNum.h"
#include <QPushButton>
#include <QMessageBox>
SetWndNum::SetWndNum(QWidget *parent, Qt::WindowFlags f) :QDialog(parent)
{
    setWndNum.setupUi(this);
    setWndNum.line_edit->setValidator(new QIntValidator(1, 99999999, this));
    connect(setWndNum.okButton, &QPushButton::clicked, this, &SetWndNum::onBtnOk);

}

void SetWndNum::onBtnOk()
{
    if (!setWndNum.line_edit->text().compare(""))
    {
        QMessageBox::warning(this, QString::fromUtf16(u"警告"), QString::fromUtf16(u"请输入窗口数量！"));
        return;
    }
    else
    {
        int num = setWndNum.line_edit->text().toInt();
        if (num <= 0 || num > 4)
        {
            QMessageBox::warning(this, QString::fromUtf16(u"警告"), QString::fromUtf16(u"窗口数量为大于0小于4的整数！"));
        }
        else
        {
            emit okSignals(num);
            close();
        }

    }

}