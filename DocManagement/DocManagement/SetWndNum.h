#pragma once
#include <QDialog>
#include <QObject>
#include "ui_SetWndNum.h"


class SetWndNum :public QDialog
{
    Q_OBJECT
public:
    SetWndNum(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());

signals:
    void okSignals(int num);
    public slots :
    void onBtnOk();
private:

public:
    Ui::SetWndNum setWndNum;

};