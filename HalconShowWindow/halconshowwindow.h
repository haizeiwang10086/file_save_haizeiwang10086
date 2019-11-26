#ifndef OPENCVSHOWWINDOW_H
#define OPENCVSHOWWINDOW_H

#include "halconshowwindow_global.h"
#include "hshow.h"
#include "ImageWidget.h"
#include <QWidget>
#include <QImage>
#include <QString>
#include <map>
#include <thread>
#include <QApplication>
#include <QTableView>
#include <QHeaderView>
#include <QTextCodec>
#include <QStandardItem>
#include "ImageWindowWidget.h"
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
    bool image_show(QString name, HObject &hobj);
    bool tuple_show(char* name, HalconCpp::HTuple& tuple);
    void flush();
    void disp();
	void resizeEvent(QResizeEvent * event);
    
private:
    ImageWindowWidget     *m_OutWnd;
    map<QString, HObject> imgs;
    map<QString, HTuple> arrays;
    QTableView  *tableView;
    QStandardItemModel *stanItemModel;
};

class WndManager
{
public:
    WndManager();
    ~WndManager()
    {
    }

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
