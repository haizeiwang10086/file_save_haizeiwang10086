#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OpenCvShowWindow.h"
#include <QImage>
#include <QPaintEvent>
#include <QGraphicsScene>
#include "HighGraphicsView.h"

class OpenCvShowWindow : public QMainWindow
{
    Q_OBJECT

public:
    OpenCvShowWindow(QWidget *parent = Q_NULLPTR);
    //void paintEvent(QPaintEvent *event);

private:
    Ui::OpenCvShowWindowClass ui;
    QImage img;
    //HighGraphicsView *mGraphicsView;
    ImageWidget     *m_Image;
};
