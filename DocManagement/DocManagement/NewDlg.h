#pragma once

#include "ui_NewDlg.h"
#include <QDialog>

class NewDlg :public QDialog
{
    Q_OBJECT  //����ź��޷��������ⲿ����
public:
    NewDlg(QWidget *parent = Q_NULLPTR);
    void addFile();
    void dealUpload();
public:
    Ui::AddWindow ui_NewDlg;
    QString path;
signals:
    void upload(QString path,QString remarks);
};
