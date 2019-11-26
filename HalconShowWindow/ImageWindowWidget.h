#pragma once
#include <QWidget>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QHeaderView>
#include "ImageWidget.h"
#include "halconcpp/halconcpp.h"
using namespace HalconCpp;

class ImageWindowWidget :public QWidget
{
    Q_OBJECT
public:
    ImageWindowWidget(QWidget *parent = Q_NULLPTR);
    ImageWidget *img_wnd;
    QTableWidget  *tableWidget;
    void setShowHTuple(HTuple tuple);
protected:
    void resizeEvent(QResizeEvent * event);

signals:

public slots :

private:
    HTuple m_ShowTuple;
    void showMore();
};
