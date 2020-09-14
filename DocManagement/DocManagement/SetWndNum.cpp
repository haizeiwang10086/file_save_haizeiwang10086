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
        QMessageBox::warning(this, QString::fromUtf16(u"����"), QString::fromUtf16(u"�����봰��������"));
        return;
    }
    else
    {
        int num = setWndNum.line_edit->text().toInt();
        if (num <= 0 || num > 4)
        {
            QMessageBox::warning(this, QString::fromUtf16(u"����"), QString::fromUtf16(u"��������Ϊ����0С��4��������"));
        }
        else
        {
            emit okSignals(num);
            close();
        }

    }

}