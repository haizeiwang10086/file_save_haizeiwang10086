#include "OpenCvShowWindow.h"
#include <QPainter>
#include <QMenuBar>
#include <QAction>
#include <QPixmap>
#include <QGraphicsRectItem>

OpenCvShowWindow::OpenCvShowWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    img.load("E:/workspace/1/1_0_Z.tif");

    QPixmap ConvertPixmap = QPixmap::fromImage(img);//The QPixmap class is an off-screen image representation that can be used as a paint device
    QGraphicsScene  *qgraphicsScene = new QGraphicsScene;//要用QGraphicsView就必须要有QGraphicsScene搭配着用
    m_Image = new ImageWidget(&ConvertPixmap);//实例化类ImageWidget的对象m_Image，该类继承自QGraphicsItem，是自己写的类
    int nwith = ui.ImageGraphic->width();//获取界面控件Graphics View的宽度
    int nheight = ui.ImageGraphic->height();//获取界面控件Graphics View的高度
    m_Image->setQGraphicsViewWH(nwith, nheight);//将界面控件Graphics View的width和height传进类m_Image中
    qgraphicsScene->addItem(m_Image);//将QGraphicsItem类对象放进QGraphicsScene中
    qgraphicsScene->setSceneRect(QRect(0,0,nwith,nheight));
    ui.ImageGraphic->setSceneRect(QRectF(-(nwith / 2), -(nheight / 2), nwith, nheight));//使视窗的大小固定在原始大小，不会随图片的放大而放大（默认状态下图片放大的时候视窗两边会自动出现滚动条，并且视窗内的视野会变大），防止图片放大后重新缩小的时候视窗太大而不方便观察图片
    ui.ImageGraphic->setScene(qgraphicsScene);//Sets the current scene to scene. If scene is already being viewed, this function does nothing.
    ui.ImageGraphic->setFocus();//将界面的焦点设置到当前Graphics View控件
    ui.ImageGraphic->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.ImageGraphic->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

