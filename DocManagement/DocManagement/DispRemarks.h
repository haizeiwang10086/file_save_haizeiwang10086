#pragma once

#include "ui_DispRemarks.h"
#include <QDialog>

class DispRemarks :public QDialog
{
    Q_OBJECT  //解决信号无法解析的外部符号
public:
    DispRemarks(QWidget *parent = Q_NULLPTR);
public:
    Ui::DispRemarks ui_DispRemarks;
signals:
};