#pragma once

//#include <QGraphicsView>
//#include <QMouseEvent>
//#include <QWheelEvent>
//#include <QImage>
//#include <QScrollBar>

//class HighGraphicsView :public QGraphicsView
//{
//    Q_OBJECT
//
//public:
//    HighGraphicsView(QWidget *parent);
//    ~HighGraphicsView();
//
//    void setImage(QImage image);
//
//protected:
//    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
//    void paintEvent(QPaintEvent * event) Q_DECL_OVERRIDE;
//    void magnify();
//    void shrink();
//    void scaling(qreal scaleFactor);
//    
//
//
//private:
//    qreal m_scalingOffset;
//    QImage img;
//
//};


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

enum Enum_ZoomState {
    NO_STATE,
    RESET,
    ZOOM_IN,
    ZOOM_OUT
};
// class ImageWidget :public QObject, QGraphicsItem
class ImageWidget :public QGraphicsItem
{
    //Q_OBJECT
public:
    ImageWidget(QPixmap *pixmap);
    QRectF  boundingRect() const;
    void    paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void    wheelEvent(QGraphicsSceneWheelEvent *event);
    void    ResetItemPos();
    void    mousePressEvent(QGraphicsSceneMouseEvent *event);
    void    mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void    mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    qreal   getScaleValue() const;
    void    setQGraphicsViewWH(int nwidth, int nheight);
private:
    qreal       m_scaleValue;
    qreal       m_scaleDafault;
    QPixmap     m_pix;
    int         m_zoomState;
    bool        m_isMove;
    QPointF     m_startPos;
};