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

void MGraphicsView::setShowImage(Mat img)
{
    showImg = img.clone();
}

void  MGraphicsView::mouseMoveEvent(QMouseEvent * event)
{
    QPoint p = event->pos();
    if (QApplication::keyboardModifiers() == Qt::ControlModifier)
    {
        if (showImg.empty())
        {
            std::string str("point: " + std::to_string(p.x()) + " , " + std::to_string(p.y()));
            QToolTip::showText(mapToGlobal(p), QString(str.c_str()));
        }
        else
        {
            std::string str("point: " + std::to_string(p.x()) + " , " + std::to_string(p.y()) + "\n" + "values: " + std::to_string(showImg.at<long>(p.x(), p.y())));
            //int val = ;
            QToolTip::showText(mapToGlobal(p), QString(str.c_str()));
        }
    }
}