#pragma once
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
//#include <QMouseEvent>


class MGraphicsView :public QGraphicsView
{
public:
    MGraphicsView(QWidget *parent = Q_NULLPTR);
    ~MGraphicsView() {};
	//bool eventFilter(QObject *watched, QEvent *event);
	//void   mouseMoveEvent(QMouseEvent *event);

};

