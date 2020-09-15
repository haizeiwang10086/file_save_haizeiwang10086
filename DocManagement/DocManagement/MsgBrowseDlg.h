#pragma once

#include "ui_MsgBrowse.h"

class BrowseDlg :public QDialog
{
    Q_OBJECT
public:
    BrowseDlg(QWidget *parent = Q_NULLPTR);

public:
    Ui::MsgBrowseWindow boe;
};
