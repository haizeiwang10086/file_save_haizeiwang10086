#include "MGraphicsScene.h"
#include <QGraphicsSceneMouseEvent>
#include <QToolTip>
bool MGraphicsScene::eventFilter(QObject *watched, QEvent *event)
{
	return false;
}

void   MGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	QPoint p = event->scenePos().toPoint();
	QRect rect=this->sceneRect().toRect();
	std::string str("point: " + std::to_string(p.x()+ rect.width()/2) + " , " + std::to_string(p.y()+rect.height()/2));
	QToolTip::showText(QPoint(p.x() + rect.width() / 2, p.y() + rect.height() / 2), QString(str.c_str()));
	QGraphicsScene::mouseMoveEvent(event);
}