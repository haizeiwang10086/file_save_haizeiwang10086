#pragma once
#include <QGraphicsView>
#include <opencv2/opencv.hpp>

using namespace cv;

class MGraphicsView :public QGraphicsView
{
public:
    MGraphicsView(QWidget *parent = Q_NULLPTR);
    ~MGraphicsView() {};
    void  mouseMoveEvent(QMouseEvent * event);
    void setShowImage(Mat img);
    Mat showImg;
};
