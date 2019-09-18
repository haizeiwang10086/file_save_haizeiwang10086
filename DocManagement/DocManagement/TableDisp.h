#pragma once

#include <QWidget>
#include "ui_TableDisp.h"

class TableDisp : public QWidget
{
    Q_OBJECT

public:
    TableDisp(QWidget *parent = Q_NULLPTR);
    ~TableDisp();

private:
    Ui::TableDisp ui;
};
