#pragma once
#include "ui_New.h"

class QtNewWindow :public QWidget
{
    Q_OBJECT  //����ź��޷��������ⲿ����
public :
    QtNewWindow(QWidget *parent=Q_NULLPTR);
    void dealSave();
public :
    Ui::NewWindow pNWnd;

signals:
    void  saveSignal(QString title, QString content);
    
};