#pragma once

#include "ui_QuestionBrowse.h"

class QuestionBrowseDlg :public QDialog
{
    Q_OBJECT
public:
    QuestionBrowseDlg(QWidget *parent = Q_NULLPTR);

public:
    Ui::BrowseWindow boe;
};
