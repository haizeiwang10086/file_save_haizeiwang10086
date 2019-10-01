#pragma once
#include "ui_New.h"

class QtNewWindow :public QWidget
{
    Q_OBJECT  //解决信号无法解析的外部符号
public :
    QtNewWindow(QWidget *parent=Q_NULLPTR);
    void dealSave();
public :
    Ui::NewWindow pNWnd;

signals:
    void  saveSignal(QString title, QString content);
    
};