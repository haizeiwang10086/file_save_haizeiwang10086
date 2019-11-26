#pragma once
#include <QWidget>
#include <QtGui>
#include <QPixmap>
#include <QPainter>
#include <QRectF>
#include <QMouseEvent>
#include <QPointF>
#include <QDragEnterEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <opencv2/opencv.hpp>
#include <QPoint>
#include <qDebug>
#include <QToolTip>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QGraphicsItem>
using namespace cv;

class ImageWidget :public QGraphicsItem
{

public:
	ImageWidget(QPixmap *pixmap);
	QRectF  boundingRect() const;
	void    paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void    wheelEvent(QGraphicsSceneWheelEvent *event);
	void    ResetItemPos();
	void    mousePressEvent(QGraphicsSceneMouseEvent *event);
	void    mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void    mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void    setShowImage(Mat img);
    bool event(QEvent *e);

	qreal   getScaleValue() const;
	void    setQGraphicsViewWH(int nwidth, int nheight);
private:
	qreal       m_scaleValue;
	qreal       m_scaleDafault;
	QPixmap     m_pix;
	int         m_zoomState;
	bool        m_isMove;
	QPointF     m_startPos;
	Mat showImg;
};