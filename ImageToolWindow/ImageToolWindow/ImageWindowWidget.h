#pragma once
#include <QWidget>
#include "ImageWidget.h"
class ImageWindowWidget :public QWidget
{
    Q_OBJECT
public:
    ImageWindowWidget(QWidget *parent = Q_NULLPTR);
    ImageWidget *img_wnd;
protected:
    void resizeEvent(QResizeEvent * event);

signals:

public slots :

private:

};
