#pragma once
//#include <QWidget>
//#include <QtGui>
//#include <QPixmap>
//#include <QPainter>
//#include <QRectF>
//#include <QMouseEvent>
//#include <QPointF>
//#include <QDragEnterEvent>
//#include <QGraphicsSceneWheelEvent>
//#include <QGraphicsItem>
//#include <QKeyEvent>
//
//class ImageWidget :public QGraphicsItem
//{
//
//public:
//    ImageWidget(QPixmap *pixmap);
//    QRectF  boundingRect() const;
//    void    paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//    void    wheelEvent(QGraphicsSceneWheelEvent *event);
//    void    ResetItemPos();
//    void    mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void    mouseMoveEvent(QGraphicsSceneMouseEvent *event);
//    void    mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
//    
//    qreal   getScaleValue() const;
//    void    setQGraphicsViewWH(int nwidth, int nheight);
//private:
//    qreal       m_scaleValue;
//    qreal       m_scaleDafault;
//    QPixmap     m_pix;
//    int         m_zoomState;
//    bool        m_isMove;
//    QPointF     m_startPos;
//};


#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QDropEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QApplication>
#include <QToolTip>
#include <QMessageBox>
#include "halconcpp/halconcpp.h"
using namespace HalconCpp;
class ImageWidget :public QWidget
{
    Q_OBJECT
public:
    ImageWidget(QWidget *parent = Q_NULLPTR);
    QSizeF m_originSize;
    HObject  m_hobj;
    void setQGraphicsViewWH();
    void convertToPsd();
    void setShowImage(HObject &img);
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent  *event);
    void resizeEvent(QResizeEvent * event);
    void hobj2QImage(HObject mat, QPixmap& rgb);


signals:

public slots :

private:
    QPixmap     m_ori_pix;
    QPixmap     m_show_pix;
    bool        m_isMove;
    bool m_Init;
    QPoint     m_startPos;
    qreal       m_scaleValue;
    qreal       m_scaleDafault;

};