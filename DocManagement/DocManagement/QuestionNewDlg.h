#pragma once
#include "ui_QuestionNew.h"

class QuestionNewDlg :public QWidget
{
    Q_OBJECT  //����ź��޷��������ⲿ����
public:
    QuestionNewDlg(QWidget *parent = Q_NULLPTR);
    void dealSave();
    void dealModify();
    void setT1();
    void setT2();
public:
    Ui::NewWindow pNWnd;

signals:
    void  saveSignal(QString title, QString content, QString label);
    void  modifySignal(QString title, QString content, QString label);

};