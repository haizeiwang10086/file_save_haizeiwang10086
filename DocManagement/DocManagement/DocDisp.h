#pragma once

#include "ui_DocDisp.h"
#include <QWidget>
#include <QResizeEvent>

class DocDisp : public QWidget
{
public:
    DocDisp(QWidget *parent=Q_NULLPTR);
    Ui::DocDispClass DDC;
    void resizeEvent(QResizeEvent *event);

};
