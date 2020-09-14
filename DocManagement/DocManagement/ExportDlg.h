#pragma once

#include "ui_ExportDlg.h"

class ExportDlg :public QDialog
{
    Q_OBJECT
public:
    ExportDlg(QWidget *parent = Q_NULLPTR);
    void setType(QStringList label);
    void getPath();
    void onComboBoxChanged();
    void dealSave();
signals:
    void saveSignal(QStringList info);
public:
    Ui::ExtDlg ui_extDlg;
};
