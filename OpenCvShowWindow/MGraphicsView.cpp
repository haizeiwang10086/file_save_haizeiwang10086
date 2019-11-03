#include "MGraphicsView.h"
//#include <iostream>
#include <QKeyEvent>


MGraphicsView::MGraphicsView(QWidget *parent)
{
    QGraphicsView::QGraphicsView(parent);
    setMouseTracking(true);
}

//bool MGraphicsView::eventFilter(QObject *watched, QEvent *event)
//{
//	return false;
//}

//void  MGraphicsView::mouseMoveEvent(QMouseEvent *event)
//{
//
//	int a = 1;
//	std::cout << a << std::endl;
//}


