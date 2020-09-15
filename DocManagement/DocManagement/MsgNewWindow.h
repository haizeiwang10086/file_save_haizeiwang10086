#pragma once
#include "ui_MsgNew.h"

class QtNewWindow :public QWidget
{
    Q_OBJECT  //����ź��޷��������ⲿ����
public:
    QtNewWindow(QWidget *parent = Q_NULLPTR);
    void dealSave();
    void dealModify();
public:
    Ui::MsgNewWindow pNWnd;

signals:
    void  saveSignal(QString title, QString content, QString remarks);
    void  modifySignal(QString title, QString content, QString remarks);

};