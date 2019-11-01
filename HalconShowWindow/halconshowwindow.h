#ifndef OPENCVSHOWWINDOW_H
#define OPENCVSHOWWINDOW_H

#include "halconshowwindow_global.h"
#include "cvshow.h"
#include "ImageWidget.h"
#include <QWidget>
#include <QImage>
#include <QGraphicsView>
#include <QString>
#include <map>
#include <thread>
#include <QApplication>
#include <QTableView>
#include <QHeaderView>
#include <QTextCodec>
#include "MItemModel.h"
#include "MGraphicsView.h"
#include "halconcpp/halconcpp.h"
using namespace HalconCpp;
using namespace std;

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

class OPENCVSHOWWINDOWSHARED_EXPORT HalconShowWindow :public QWidget
{

public:
    HalconShowWindow(QWidget *parent = Q_NULLPTR);
    bool image_show(QString name, HObject &img);
    void flush();
    void imageDisp();
	void resizeEvent(QResizeEvent * event);
    void hobj2QImage(HObject mat, QImage& rgb);
private:
    QImage img;
    MGraphicsView *ImageGraphic;
    QGraphicsScene  *qgraphicsScene;
    ImageWidget     *m_Image;
    map<QString, HObject> imgs;
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
    HalconShowWindow *wnd;
    void setWndName(QString name);
    void openWnd();
};



namespace InnerUi
{
    static WndManager *manager;
}


#endif // OPENCVSHOWWINDOW_H
