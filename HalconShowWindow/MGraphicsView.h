#pragma once
#include <QGraphicsView>
#include "halconcpp/halconcpp.h"
using namespace HalconCpp;

class MGraphicsView :public QGraphicsView
{
public:
    MGraphicsView(QWidget *parent = Q_NULLPTR);
    ~MGraphicsView() {};
    void  mouseMoveEvent(QMouseEvent * event);
    void setShowImage(HObject img);
	HObject showImg;
};
