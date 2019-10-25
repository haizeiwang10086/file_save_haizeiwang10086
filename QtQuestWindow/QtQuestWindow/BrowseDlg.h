#pragma once

#include "ui_Browse.h"

class BrowseDlg :public QDialog
{
    Q_OBJECT
public:
    BrowseDlg(QWidget *parent = Q_NULLPTR);
    void resizeEvent(QResizeEvent * event);

public:
    Ui::BrowseWindow boe;
};
