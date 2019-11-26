#include "ImageWindowWidget.h"

ImageWindowWidget::ImageWindowWidget(QWidget *parent):QWidget(parent)
{
    img_wnd = new ImageWidget(this);
}

void ImageWindowWidget::resizeEvent(QResizeEvent * event)
{
    img_wnd->resize(size());
}