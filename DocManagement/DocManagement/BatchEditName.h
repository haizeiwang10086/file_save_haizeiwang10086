#pragma once
#include "ui_BatchEditFileName.h"

class BatchEditName : public QWidget
{
    Q_OBJECT

public:
    BatchEditName(QWidget *parent = Q_NULLPTR);

    void searchDirectoryDlg();
    void modifyFilesName();
    void selectImagePath();
    QString selectPath();
    void cvtImageFormat();

private:
    Ui::BatchEditFileName editWidget;

    

};