#ifndef OPENCVSHOWWINDOW_H
#define OPENCVSHOWWINDOW_H

#include "opencvshowwindow_global.h"
#include "cvshow.h"
#include "ImageWidget.h"
#include <QWidget>
#include <QImage>
#include <QGraphicsView>
#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>
#include <QString>
#include <map>
#include <thread>
#include <QApplication>
#include <QTableView>
#include <QHeaderView>
#include <QTextCodec>
#include <QGraphicsScene>
#include "MItemModel.h"
#include "MGraphicsView.h"
#include "ImageWidget.h"
#include "MGraphicsScene.h"
using namespace cv;
using namespace std;

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

class OPENCVSHOWWINDOWSHARED_EXPORT OpencvShowWindow :public QWidget
{

public:
    OpencvShowWindow(QWidget *parent = Q_NULLPTR);
    bool image_show(QString name, Mat &img);
    void flush();
    void imageDisp();
	void resizeEvent(QResizeEvent * event);
    void mat2QImage(Mat mat, QImage& rgb);
private:
    QImage img;
    MGraphicsView *ImageGraphic;
	MGraphicsScene  *qgraphicsScene;
    ImageWidget     *m_Image;
    map<QString, Mat> imgs;
    QTableView  *tableView;
    QStandardItemModel *stanItemModel;
};

class WndManager
{
public:
    WndManager();
    ~WndManager()
    {
        if (wndThread != NULL)
        {
            delete wndThread;
        }
    }

    std::thread *wndThread;
    QApplication *app;
    OpencvShowWindow *wnd;
    void setWndName(QString name);
    void openWnd();
};



namespace InnerUi
{
    static WndManager *manager;
}


#endif // OPENCVSHOWWINDOW_H
