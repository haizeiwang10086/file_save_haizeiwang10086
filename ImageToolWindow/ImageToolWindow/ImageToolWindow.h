#pragma once
#include "ImageToolWindowVirtualBase.h"
#include "qstandarditemmodel.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "ui_ImageToolWindow.h"
#include "qtimagetoolwindow_global.h"
#include "ResizeWnd.h"
#include "ImageWidget.h"
#include <QPainter>
#include <QPixmap>
#include <QSize>
#include <QMainWindow>

class QTSEARCHWINDOW_EXPORT ImageToolWindow :public QMainWindow
{
public:
    ImageToolWindow();
    void resizeEvent(QResizeEvent * event);
    void showPsdImage();
    void saveAsTif();
    void saveAsPng();
    void saveAsBmp();
    void saveAsJpg();
    void saveAsPsd();
    void saveImage(Mat & img, QString format);
    void showDetailMessage();
public:
	Ui::ImageToolWindow imgWnd;
    ResizeDlg *resizeWnd;
    QMenuBar *pQMenuBar;



};


