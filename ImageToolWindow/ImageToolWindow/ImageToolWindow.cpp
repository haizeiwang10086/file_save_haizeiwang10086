#include "ImageToolWindow.h"
#include "qmessagebox.h"
#include "qsqlerror.h"
#include "qclipboard.h"
#include "qfile.h"
#include <map>
#include <QMenuBar>
#include <QMenu>
#include <QFileDialog>
#include <QDropEvent>
#include <QMimeData>
#include <QUrl>


ImageToolWindow::ImageToolWindow()
{
    imgWnd.setupUi(this);
    setAcceptDrops(true);
    resize(QSize(800, 500));
    resizeWnd = new ResizeDlg(imgWnd.out_window->img_wnd->m_mat, imgWnd.out_window->img_wnd);
    //resizeWnd.setParent(imgWnd.img_wnd);
    pQMenuBar= menuBar();
    pQMenuBar->setStyleSheet("QMenuBar{background-color:rgb(37,199,254)}");
    QMenu *pQMenu = pQMenuBar->addMenu(QString::fromUtf16(u"功能"));
    QAction *pQActShowPsd = pQMenuBar->addAction(QString::fromUtf16(u"伪彩色图像"));
    QAction *pQAction = pQMenu->addAction(QString::fromUtf16(u"缩放"));
    QMenu *pQTransMenu = pQMenu->addMenu(QString::fromUtf16(u"保存为"));
    QAction *pQActTif = pQTransMenu->addAction(QString::fromUtf16(u"TIF图像"));
    QAction *pQActBmp = pQTransMenu->addAction(QString::fromUtf16(u"BMP图像"));
    QAction *pQActJpg = pQTransMenu->addAction(QString::fromUtf16(u"JPG图像"));
    QAction *pQActPng = pQTransMenu->addAction(QString::fromUtf16(u"PNG图像"));
    QAction *pQActCvt2Psd= pQTransMenu->addAction(QString::fromUtf16(u"伪彩色"));
    connect(pQAction, &QAction::triggered, 
        [=]()
        {
            resizeWnd->m_mat = imgWnd.out_window->img_wnd->m_mat.clone();
            resizeWnd->exec();
        });
    connect(pQActShowPsd, &QAction::triggered, this, &ImageToolWindow::showPsdImage);
    connect(pQActTif, &QAction::triggered, this, &ImageToolWindow::saveAsTif);
    connect(pQActBmp, &QAction::triggered, this, &ImageToolWindow::saveAsBmp);
    connect(pQActJpg, &QAction::triggered, this, &ImageToolWindow::saveAsJpg);
    connect(pQActPng, &QAction::triggered, this, &ImageToolWindow::saveAsPng);
    connect(pQActCvt2Psd, &QAction::triggered, this, &ImageToolWindow::saveAsPsd); 
    connect(imgWnd.out_window->img_wnd,&ImageWidget::newFileSignal, this, &ImageToolWindow::showDetailMessage);
}


void ImageToolWindow::resizeEvent(QResizeEvent * event)
{

    imgWnd.out_window->move(150, 10);
    QSize  s = size();
    imgWnd.out_window->resize(QSize(s.width() - 150, s.height() - 80));
    imgWnd.detailBrowser->move(10, 10);
    imgWnd.detailBrowser->resize(135, s.height() - 80);
}


void ImageToolWindow::saveAsTif()
{
    saveImage(imgWnd.out_window->img_wnd->m_mat,"tif");
}

void ImageToolWindow::saveAsPng()
{
    saveImage(imgWnd.out_window->img_wnd->m_mat,"png");
}
void ImageToolWindow::saveAsBmp()
{
    saveImage(imgWnd.out_window->img_wnd->m_mat,"bmp");
}
void ImageToolWindow::saveAsJpg()
{
    saveImage(imgWnd.out_window->img_wnd->m_mat,"jpg");
}

void ImageToolWindow::saveAsPsd()
{
    if (imgWnd.out_window->img_wnd->m_mat.channels() == 1)
    {

        Mat imgNorm,imgColor, mask,mask1;
        Point minLoc, maxLoc;
        double minVal, maxVal;
        threshold(imgWnd.out_window->img_wnd->m_mat, mask1, 10, 255, THRESH_BINARY);
        mask1.convertTo(mask, CV_8UC1);
        minMaxLoc(imgWnd.out_window->img_wnd->m_mat, &minVal, &maxVal, &minLoc, &maxLoc, mask);
        double scale = 255 / (maxVal - minVal+10);
        Mat img,subImg(imgWnd.out_window->img_wnd->m_mat.size(), imgWnd.out_window->img_wnd->m_mat.type(), Scalar::all(minVal-10));
        img = (imgWnd.out_window->img_wnd->m_mat - subImg)*scale;
        img.convertTo(imgNorm, CV_8UC1);
        
        applyColorMap(imgNorm, imgColor, COLORMAP_HOT);

        saveImage(imgColor, "tif");
    }
}

void ImageToolWindow::saveImage(Mat & img,QString format)
{
    QString imgPath = imgWnd.out_window->img_wnd->m_imgPath;
    QStringList strList = imgPath.split("/");
    QStringList strList2 = strList.at(strList.size() - 1).split(".");
    QString imgName;
    if (strList2.size() > 0)
    {
        imgName = strList2.at(0) + "."+format;
    }
    else
    {
        imgName = "";
    }
    QString fileName = QFileDialog::getSaveFileName(this, QString::fromUtf16(u"保存为"), "D:/" + imgName, tr("Images(*.png);;Images(*.tif);;Images(*.bmp);;Images(*.jpg)"));
    if (fileName.isEmpty())
    {
        return;
    }
    else
    {
        imwrite(fileName.toLatin1().data(), img);
    }
    
}


void ImageToolWindow::showPsdImage()
{
    imgWnd.out_window->img_wnd->convertToPsd();
}

void ImageToolWindow::showDetailMessage()
{
    int width = imgWnd.out_window->img_wnd->m_mat.cols;
    int height = imgWnd.out_window->img_wnd->m_mat.rows;
    QString showText = QString::fromUtf16(u"<font style='font-weight: bold;color:blue;'>图像</font> \
        <hr/><font style='line-height : 150%;font-size : 8pt;'>分辨率</font><br/> \
        <font style='line-height : 100%;font-family:SimHei;font-size : 8pt;'>") + QString::number(width) + \
        "&nbsp;&times;&nbsp;" + QString::number(height) + "</font><hr/>" + \
        QString::fromUtf16(u"<font style='line-height : 150%;font-size : 8pt;'>宽度:") + "&nbsp;&nbsp;" + QString::number(width) + QString::fromUtf16(u"像素</front>") +\
        QString::fromUtf16(u"<font style='line-height : 150%;font-size : 8pt;'>高度:") + "&nbsp;&nbsp;" + QString::number(height) + QString::fromUtf16(u"像素</front><hr/>") \
        + QString::fromUtf16(u"<font style='line-height : 150%;font-size : 8pt;'>位深:") + "&nbsp;&nbsp;" + QString::number(imgWnd.out_window->img_wnd->m_mat.depth()*8) + QString::fromUtf16(u"位</front><hr/>");
    imgWnd.detailBrowser->setText(showText);
}


