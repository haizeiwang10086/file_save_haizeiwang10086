#pragma once
#include "ImageToolWindowVirtualBase.h"
#include "qstandarditemmodel.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "ui_ImageToolDlg.h"
#include "ResizeWnd.h"
#include "ImageWidget.h"
#include <QPainter>
#include <QPixmap>
#include <QSize>
#include <QMainWindow>
#include <vector>
#include "ImageWindowWidget.h"
#include "SetWndNum.h"

using namespace std;

class ImageToolDlg :public QMainWindow
{
public:
    ImageToolDlg();
    void resizeEvent(QResizeEvent * event);
    void showPsdImage();
    void saveAsTif();
    void saveAsPng();
    void saveAsBmp();
    void saveAsJpg();
    void saveAsPsd();
    void saveImage(cv::Mat & img, QString format);
    void showDetailMessage();
    void imageCompare();
    void setWndNum(int num);
public:
    Ui::ImageToolWindow imgWnd;
    ResizeDlg *resizeWnd;
    QMenuBar *pQMenuBar;
    vector<ImageWindowWidget *> wnds;
    int m_WndNum;
    vector<QPoint> m_WndPoints;
    vector<QSize> m_WndSizes;



};


