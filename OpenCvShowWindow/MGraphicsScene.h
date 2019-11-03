#pragma once
#include <QGraphicsScene>


class MGraphicsScene : public QGraphicsScene
{
public :
	void    mouseMoveEvent(QGraphicsSceneMouseEvent *event);
protected:
	bool eventFilter(QObject *watched, QEvent *event);
	



};
