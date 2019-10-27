#ifndef OPENCVSHOWWINDOW_H
#define OPENCVSHOWWINDOW_H

#include "opencvshowwindow_global.h"
#include "cvshow.h"
#include "ImageWidget.h"
#include <QWidget>
#include <QImage>
#include <QGraphicsView>
#include <opencv2\opencv.hpp>
#include <QString>
#include <map>
#include <thread>
#include <QApplication>
#include <QTableView>
#include "MItemModel.h"
using namespace cv;
using namespace std;

class OPENCVSHOWWINDOWSHARED_EXPORT OpencvShowWindow :public QWidget
{

public:
    OpencvShowWindow(QWidget *parent = Q_NULLPTR);
    bool addImage(QString name, Mat &img);
    void flush();
    void imageDisp();
private:
    QImage img;
    QGraphicsView *ImageGraphic;
    QGraphicsScene  *qgraphicsScene;
    ImageWidget     *m_Image;
    map<QString, QImage> imgs;
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
