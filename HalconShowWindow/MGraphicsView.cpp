#include "MGraphicsView.h"
#include <QApplication>
#include <QKeyEvent>
#include <qDebug>
#include <QToolTip>
#include <string>

MGraphicsView::MGraphicsView(QWidget *parent)
{
    QGraphicsView::QGraphicsView(parent);
    setMouseTracking(true);
}

void MGraphicsView::setShowImage(HObject img)
{
	CopyObj(img, &showImg,1,1);
}

void  MGraphicsView::mouseMoveEvent(QMouseEvent * event)
{
    QPoint p = event->pos();
    if (QApplication::keyboardModifiers() == Qt::ControlModifier)
    {
        if (!showImg.IsInitialized())
        {
            std::string str("point: " + std::to_string(p.x()) + " , " + std::to_string(p.y()));
            QToolTip::showText(mapToGlobal(p), QString(str.c_str()));
        }
        else
        {
			HTuple hv_GrayValue;
			GetGrayval(showImg, p.x(), p.y(), &hv_GrayValue);
			;
            std::string str("point: " + std::to_string(p.x()) + " , " + std::to_string(p.y()) + "\n" + "values: " + std::string((char *)hv_GrayValue.S().Text()));
            //int val = ;
            QToolTip::showText(mapToGlobal(p), QString(str.c_str()));
        }
    }
}