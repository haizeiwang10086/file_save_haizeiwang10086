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


ImageToolWindow::ImageToolWindow():m_WndNum(1)
{
    imgWnd.setupUi(this);
    for (int i = 0; i < 4; i++)
    {
        wnds.push_back(new ImageWindowWidget(this));
        wnds.at(i)->hide();
    }
   
    setAcceptDrops(true);
    resize(QSize(800, 500));
    
    //resizeWnd.setParent(imgWnd.img_wnd);
    pQMenuBar= menuBar();
    pQMenuBar->setStyleSheet("QMenuBar{background-color:rgb(37,199,254)}");
    QMenu *pQMenu = pQMenuBar->addMenu(QString::fromUtf16(u"功能"));
    QAction *pQActShowPsd = pQMenuBar->addAction(QString::fromUtf16(u"伪彩色图像"));
    QAction *pQActCompare = pQMenuBar->addAction(QString::fromUtf16(u"对比"));
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
            if (m_WndNum <= 0)return;
            resizeWnd = new ResizeDlg(wnds.at(0)->img_wnd->m_mat, wnds.at(0)->img_wnd);
            resizeWnd->m_mat = wnds.at(0)->img_wnd->m_mat.clone();
            resizeWnd->exec();
        });
    connect(pQActShowPsd, &QAction::triggered, this, &ImageToolWindow::showPsdImage);
    connect(pQActTif, &QAction::triggered, this, &ImageToolWindow::saveAsTif);
    connect(pQActBmp, &QAction::triggered, this, &ImageToolWindow::saveAsBmp);
    connect(pQActJpg, &QAction::triggered, this, &ImageToolWindow::saveAsJpg);
    connect(pQActPng, &QAction::triggered, this, &ImageToolWindow::saveAsPng);
    connect(pQActCvt2Psd, &QAction::triggered, this, &ImageToolWindow::saveAsPsd); 
    connect(pQActCompare, &QAction::triggered, this, &ImageToolWindow::imageCompare);
    connect(wnds.at(0)->img_wnd,&ImageWidget::newFileSignal, this, &ImageToolWindow::showDetailMessage);
    
}


void ImageToolWindow::resizeEvent(QResizeEvent * event)
{
    QSize  s = size();
    imgWnd.detailBrowser->move(10, 10);
    imgWnd.detailBrowser->resize(135, s.height() - 80);

    m_WndPoints.clear();
    m_WndSizes.clear();
    switch (m_WndNum)
    {
    case 1:
    {
        m_WndPoints.push_back(QPoint(150, 33));
        m_WndSizes.push_back(QSize(s.width() - 150, s.height() - 80));
        break;
    }
    case 2:
    {
        m_WndPoints.push_back(QPoint(150, 33));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80)));
        m_WndPoints.push_back(QPoint(150 + (s.width() - 150) / 2, 33));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, s.height() - 80));
        break;
    }
    case 3:
    {
        m_WndPoints.push_back(QPoint(150, 33));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80) / 2));
        m_WndPoints.push_back(QPoint(150 + (s.width() - 150) / 2, 33));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80) / 2));
        m_WndPoints.push_back(QPoint(150, 33 + (s.height() - 80) / 2));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80) / 2));
        break;
    }
    case 4:
    {
        m_WndPoints.push_back(QPoint(150, 33));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80) / 2));
        m_WndPoints.push_back(QPoint(150 + (s.width() - 150) / 2, 33));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80) / 2));
        m_WndPoints.push_back(QPoint(150, 33 + (s.height() - 80) / 2));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80) / 2));
        m_WndPoints.push_back(QPoint(150 + (s.width() - 150) / 2, 33 + (s.height() - 80) / 2));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80) / 2));
        break;
    }
    default:
        break;
    }


    if (m_WndNum <= 0)return;
    for (int i = 0; i < m_WndNum; i++)
    {
        wnds.at(i)->show();
        wnds.at(i)->move(m_WndPoints.at(i));
        wnds.at(i)->resize(m_WndSizes.at(i));
    }

}


void ImageToolWindow::saveAsTif()
{
    if (m_WndNum <= 0)return;
    
    saveImage(wnds.at(0)->img_wnd->m_mat,"tif");
}

void ImageToolWindow::saveAsPng()
{
    if (m_WndNum <= 0)return;
    saveImage(wnds.at(0)->img_wnd->m_mat,"png");
}
void ImageToolWindow::saveAsBmp()
{
    if (m_WndNum <= 0)return;
    saveImage(wnds.at(0)->img_wnd->m_mat,"bmp");
}
void ImageToolWindow::saveAsJpg()
{
    if (m_WndNum <= 0)return;
    saveImage(wnds.at(0)->img_wnd->m_mat,"jpg");
}

void ImageToolWindow::saveAsPsd()
{
    if (m_WndNum <= 0)return;
    if (wnds.at(0)->img_wnd->m_mat.channels() == 1)
    {

        Mat imgNorm,imgColor, mask,mask1;
        Point minLoc, maxLoc;
        double minVal, maxVal;
        threshold(wnds.at(0)->img_wnd->m_mat, mask1, 10, 255, THRESH_BINARY);
        mask1.convertTo(mask, CV_8UC1);
        minMaxLoc(wnds.at(0)->img_wnd->m_mat, &minVal, &maxVal, &minLoc, &maxLoc, mask);
        double scale = 255 / (maxVal - minVal+10);
        Mat img,subImg(wnds.at(0)->img_wnd->m_mat.size(), wnds.at(0)->img_wnd->m_mat.type(), Scalar::all(minVal-10));
        img = (wnds.at(0)->img_wnd->m_mat - subImg)*scale;
        img.convertTo(imgNorm, CV_8UC1);
        
        applyColorMap(imgNorm, imgColor, COLORMAP_HOT);

        saveImage(imgColor, "tif");
    }
}

void ImageToolWindow::saveImage(Mat & img,QString format)
{
    if (m_WndNum <= 0)return;
    QString imgPath = wnds.at(0)->img_wnd->m_imgPath;
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

void ImageToolWindow::setWndNum(int num)
{
    m_WndNum = num;
}

void ImageToolWindow::imageCompare()
{
    int maxWndNum = 4;
    SetWndNum *dlg = new SetWndNum(this);
    connect(dlg, &SetWndNum::okSignals, this, &ImageToolWindow::setWndNum);
    dlg->exec();
    if (m_WndNum <= 0)return;
    QSize s = size();
    m_WndPoints.clear();
    m_WndSizes.clear();
    switch (m_WndNum)
    {
    case 1:
    {
        wnds.at(1)->hide();
        wnds.at(2)->hide();
        wnds.at(3)->hide();
        m_WndPoints.push_back(QPoint(150, 33));
        m_WndSizes.push_back(QSize(s.width() - 150, s.height() - 80));
        break;
    }
    case 2:
    {
        wnds.at(2)->hide();
        wnds.at(3)->hide();
        m_WndPoints.push_back(QPoint(150, 33));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80)));
        m_WndPoints.push_back(QPoint(150 + (s.width() - 150) / 2, 33));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, s.height() - 80));
        break;
    }
    case 3:
    {
        wnds.at(3)->hide();
        m_WndPoints.push_back(QPoint(150, 33));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80) / 2));
        m_WndPoints.push_back(QPoint(150 + (s.width() - 150) / 2, 33));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80) / 2));
        m_WndPoints.push_back(QPoint(150, 33 + (s.height() - 80) / 2));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80) / 2));
        break;
    }
    case 4:
    {
        m_WndPoints.push_back(QPoint(150, 33));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80) / 2));
        m_WndPoints.push_back(QPoint(150 + (s.width() - 150) / 2, 33));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80) / 2));
        m_WndPoints.push_back(QPoint(150, 33 + (s.height() - 80) / 2));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80) / 2));
        m_WndPoints.push_back(QPoint(150 + (s.width() - 150) / 2, 33 + (s.height() - 80) / 2));
        m_WndSizes.push_back(QSize((s.width() - 150) / 2, (s.height() - 80) / 2));
        break;
    }
    default:
        break;
    }

    for (int i = 0; i < m_WndNum; i++)
    {
        wnds.at(i)->show();
        wnds.at(i)->move(m_WndPoints.at(i));
        wnds.at(i)->resize(m_WndSizes.at(i));
    }

}


void ImageToolWindow::showPsdImage()
{
    if (wnds.size() <= 0)return;
    wnds.at(0)->img_wnd->convertToPsd();
}

void ImageToolWindow::showDetailMessage()
{
    if (wnds.size() <= 0)return;
    int width = wnds.at(0)->img_wnd->m_mat.cols;
    int height = wnds.at(0)->img_wnd->m_mat.rows;
    int depth = wnds.at(0)->img_wnd->m_mat.depth();
    int bits = 0;
    if (depth == CV_8U || depth == CV_8S)
    {
        bits = 8;
    }
    else if (depth == CV_16U || depth == CV_16S)
    {
        bits = 16;
    }
    else if (depth == CV_32S || depth == CV_32F)
    {
        bits = 32;
    }
    QString showText = QString::fromUtf16(u"<font style='font-weight: bold;color:blue;'>图像</font> \
        <hr/><font style='line-height : 150%;font-size : 8pt;'>分辨率</font><br/> \
        <font style='line-height : 100%;font-family:SimHei;font-size : 8pt;'>") + QString::number(width) + \
        "&nbsp;&times;&nbsp;" + QString::number(height) + "</font><hr/>" + \
        QString::fromUtf16(u"<font style='line-height : 150%;font-size : 8pt;'>宽度:") + "&nbsp;&nbsp;" + QString::number(width) + QString::fromUtf16(u"像素</front>") +\
        QString::fromUtf16(u"<font style='line-height : 150%;font-size : 8pt;'>高度:") + "&nbsp;&nbsp;" + QString::number(height) + QString::fromUtf16(u"像素</front><hr/>") \
        + QString::fromUtf16(u"<font style='line-height : 150%;font-size : 8pt;'>位深:") + "&nbsp;&nbsp;" + QString::number(bits) + QString::fromUtf16(u"位</front><hr/>");
    
    imgWnd.detailBrowser->setText(showText);
}


