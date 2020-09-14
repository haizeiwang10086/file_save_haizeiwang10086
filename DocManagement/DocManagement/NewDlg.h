#pragma once

#include "ui_NewDlg.h"
#include <QDialog>

class NewDlg :public QDialog
{
    Q_OBJECT  //解决信号无法解析的外部符号
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
