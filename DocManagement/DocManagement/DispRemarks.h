#pragma once

#include "ui_DispRemarks.h"
#include <QDialog>

class DispRemarks :public QDialog
{
    Q_OBJECT  //����ź��޷��������ⲿ����
public:
    DispRemarks(QWidget *parent = Q_NULLPTR);
public:
    Ui::DispRemarks ui_DispRemarks;
signals:
};