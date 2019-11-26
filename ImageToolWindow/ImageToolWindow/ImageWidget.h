#pragma once
#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QDropEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QApplication>
#include <QToolTip>
#include <opencv2\opencv.hpp>
#include <QMessageBox>
using namespace cv;
class ImageWidget :public QWidget
{
    Q_OBJECT
public:
    ImageWidget(QWidget *parent = Q_NULLPTR);
    QSizeF m_originSize;
    Mat  m_mat;
    QString   m_imgPath;
    void setQGraphicsViewWH();
    void convertToPsd();
protected:
    void paintEvent(QPaintEvent *event);
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent  *event);
    void resizeEvent(QResizeEvent * event);
    

signals:
    void newFileSignal();
public slots :

private:
    QPixmap     m_ori_pix;
    QPixmap     m_psd_pix;
    QPixmap     m_show_pix;
    bool        m_isMove;
    bool b_show_psd;
    bool m_Init;
    QPoint     m_startPos;
    qreal       m_scaleValue;
    qreal       m_scaleDafault;
    
};
