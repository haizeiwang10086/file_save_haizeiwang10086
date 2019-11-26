#include "ImageWidget.h"

//
//#include <QDebug>
//#include <QGraphicsSceneMouseEvent>
//#include <QPointF>
//#include <QGraphicsSceneDragDropEvent>
//#include <QDrag>
//#include <QApplication>
//#include <math.h>
//
//ImageWidget::ImageWidget(QPixmap *pixmap)
//{
//    m_pix = *pixmap;
//    setAcceptDrops(true);//If enabled is true, this item will accept hover events; otherwise, it will ignore them. By default, items do not accept hover events.
//    m_scaleValue = 0;
//    m_scaleDafault = 0;
//    m_isMove = false;
//}
//
//QRectF ImageWidget::boundingRect() const
//{
//    return QRectF(-m_pix.width() / 2, -m_pix.height() / 2,
//        m_pix.width(), m_pix.height());
//}
//
//void ImageWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
//    QWidget *)
//{
//    painter->drawPixmap(-m_pix.width() / 2, -m_pix.height() / 2, m_pix);
//}
//
//void ImageWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    if (event->button() == Qt::LeftButton)
//    {
//        m_startPos = event->pos();//鼠标左击时，获取当前鼠标在图片中的坐标，
//        m_isMove = true;//标记鼠标左键被按下
//    }
//    else if (event->button() == Qt::RightButton)
//    {
//        ResetItemPos();//右击鼠标重置大小
//    }
//
//}
//
//void ImageWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//    if (m_isMove)
//    {
//        QPointF point = (event->pos() - m_startPos)*m_scaleValue;
//        moveBy(point.x(), point.y());
//    }
//}
//
//void ImageWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
//{
//    m_isMove = false;//标记鼠标左键已经抬起
//}
//
////void  ImageWidget::keyPressEvent(QKeyEvent *event)
////{
////    if (event->modifiers() == Qt::ControlModifier && QApplication::mouseButtons() == Qt::LeftButton)
////    {
////        int a = 1;
////        qDebug() << a << endl;
////    }
////}
//
//
//void ImageWidget::wheelEvent(QGraphicsSceneWheelEvent *event)//鼠标滚轮事件
//{
//    if ((event->delta() > 0) && (m_scaleValue >= 50))//最大放大到原始图像的50倍
//    {
//        return;
//    }
//    else if ((event->delta() < 0) && (m_scaleValue <= m_scaleDafault))//图像缩小到自适应大小之后就不继续缩小
//    {
//        ResetItemPos();//重置图片大小和位置，使之自适应控件窗口大小
//    }
//    else
//    {
//        qreal qrealOriginScale = m_scaleValue;
//        if (event->delta() > 0)//鼠标滚轮向前滚动
//        {
//            m_scaleValue *= 1.1;//每次放大10%
//        }
//        else
//        {
//            m_scaleValue *= 0.9;//每次缩小10%
//        }
//        setScale(m_scaleValue);
//        if (event->delta() > 0)
//        {
//            moveBy(-event->pos().x()*qrealOriginScale*0.1, -event->pos().y()*qrealOriginScale*0.1);//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
//        }
//        else
//        {
//            moveBy(event->pos().x()*qrealOriginScale*0.1, event->pos().y()*qrealOriginScale*0.1);//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
//        }
//    }
//}
//
//void ImageWidget::setQGraphicsViewWH(int nwidth, int nheight)//将主界面的控件QGraphicsView的width和height传进本类中，并根据图像的长宽和控件的长宽的比例来使图片缩放到适合控件的大小
//{
//    int nImgWidth = m_pix.width();
//    int nImgHeight = m_pix.height();
//    qreal temp1 = nwidth*1.0 / nImgWidth;
//    qreal temp2 = nheight*1.0 / nImgHeight;
//    if (temp1>temp2)
//    {
//        m_scaleDafault = temp2;
//    }
//    else
//    {
//        m_scaleDafault = temp1;
//    }
//    setScale(m_scaleDafault);
//    m_scaleValue = m_scaleDafault;
//}
//
//void ImageWidget::ResetItemPos()//重置图片位置
//{
//    m_scaleValue = m_scaleDafault;//缩放比例回到一开始的自适应比例
//    setScale(m_scaleDafault);//缩放到一开始的自适应大小
//    setPos(0, 0);
//}
//
//qreal ImageWidget::getScaleValue() const
//{
//    return m_scaleValue;
//}


ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent), m_isMove(false), m_scaleValue(0), m_Init(false)
{
    setMouseTracking(true);

}

void ImageWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(0, 0, m_show_pix);
    QWidget::paintEvent(event);

}

void ImageWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_startPos = event->pos();//鼠标左击时，获取当前鼠标在图片中的坐标，
        m_isMove = true;//标记鼠标左键被按下
    }
    else if (event->button() == Qt::RightButton)
    {
        //ResetItemPos();//右击鼠标重置大小
    }

}


void ImageWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isMove)
    {
        QPointF point = (event->pos() - m_startPos);
        QPointF p = this->pos() + point;
        move(p.x(), p.y());
    }

    if (QApplication::keyboardModifiers() == Qt::ControlModifier)
    {
        QPoint p = mapToGlobal(event->pos());
        QPoint imgP = event->pos();
        if (!m_hobj.IsInitialized())
        {
            std::string str("point: " + std::to_string(imgP.x()) + " , " + std::to_string(imgP.y()));
            QToolTip::showText(p, QString(str.c_str()));
        }
        else
        {
            QSize s = size();
            HTuple hv_Width, hv_Height,hv_Channels;
            GetImageSize(m_hobj, &hv_Width, &hv_Height);
            CountChannels(m_hobj,&hv_Channels);
            int width = hv_Width.I();
            int height = hv_Height.I();
            int chanlsNum = hv_Channels.I();
            int x = 1.0*imgP.x() / m_show_pix.width() *width;
            int y = 1.0*imgP.y() / m_show_pix.height()*height;
            if (x >=width || y >=height)
            {
                std::string str("point: " + std::to_string(imgP.x()) + " , " + std::to_string(imgP.y()));
                QToolTip::showText(p, QString(str.c_str()));
            }
            else
            {
                QString str;
                if (chanlsNum == 3)
                {
                    HObject hv_R, hv_G, hv_B;
                    HTuple hv_RVal, hv_GVal, hv_BVal;
                    Decompose3(m_hobj, &hv_R, &hv_G, &hv_B);
                    GetGrayval(hv_R, y, x,&hv_RVal);
                    GetGrayval(hv_G, y, x, &hv_GVal);
                    GetGrayval(hv_B, y, x, &hv_BVal);
                    str = QString("point: %1 , %2\nvalues: ( %3 %4 %5 )") \
                        .arg(imgP.x()).arg(imgP.y()).arg(hv_RVal.I()).arg(hv_GVal.I()).arg(hv_BVal.I());
                }
                else if (chanlsNum == 1)
                {
                    HTuple hv_GrayVal,hv_Type;
                    GetGrayval(m_hobj, y, x, &hv_GrayVal);
                    GetImageType(m_hobj, &hv_Type);
                    QString type=hv_Type.S().Text();
                    if (!type.compare("float"))
                    {
                        str = QString("point: %1 , %2\nvalues: %3") \
                            .arg(imgP.x()).arg(imgP.y()).arg(hv_GrayVal.D());
                    }
                    else
                    {
                        str = QString("point: %1 , %2\nvalues: %3") \
                            .arg(imgP.x()).arg(imgP.y()).arg(hv_GrayVal.I());
                    }               

                }
                else
                {
                    str = QString("通道未定义");
                }
                QToolTip::showText(p, str);
            }

        }
    }


}
void ImageWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_isMove = false;//标记鼠标左键已经抬起

}

void ImageWidget::wheelEvent(QWheelEvent  *event)
{
    if (m_Init == false)
    {
        setQGraphicsViewWH();
        m_Init = true;
    }
    if ((event->delta() > 0) && (m_scaleValue >= 50))//最大放大到原始图像的50倍
    {
        return;
    }
    else if ((event->delta() < 0) && (m_scaleValue <= m_scaleDafault))//图像缩小到自适应大小之后就不继续缩小
    {
        //ResetItemPos();//重置图片大小和位置，使之自适应控件窗口大小
    }
    else
    {
        qreal qrealOriginScale = m_scaleValue;
        int delta = event->delta();
        if (event->delta() > 0)//鼠标滚轮向前滚动
        {
            m_scaleValue += 0.1;//每次放大10%
        }
        else
        {
            m_scaleValue -= 0.1;//每次缩小10%
        }
        QPointF oriP = event->pos();
        resize((m_scaleValue*m_originSize).toSize());


        if (event->delta() > 0)
        {
            QPointF p = this->pos() - QPointF((oriP.x()*0.1) / (m_scaleValue - 0.1), (oriP.y()*0.1) / (m_scaleValue - 0.1));
            move(p.x(), p.y());//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
        }
        else
        {
            QPointF p = this->pos() + QPointF((oriP.x()*0.1) / (m_scaleValue + 0.1), (oriP.y()*0.1) / (m_scaleValue + 0.1));
            move(p.x(), p.y());//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
        }
    }

}

void ImageWidget::setQGraphicsViewWH()//将主界面的控件QGraphicsView的width和height传进本类中，并根据图像的长宽和控件的长宽的比例来使图片缩放到适合控件的大小
{
    QSize s = size();
    int nwidth = s.width();
    int nheight = s.height();
    int nImgWidth = m_show_pix.width();
    int nImgHeight = m_show_pix.height();
    qreal temp1 = nwidth*1.0 / nImgWidth;
    qreal temp2 = nheight*1.0 / nImgHeight;
    if (temp1>temp2)
    {
        m_scaleDafault = temp2;
    }
    else
    {
        m_scaleDafault = temp1;
    }
    resize(m_scaleDafault*size());
    m_scaleValue = m_scaleDafault;
    m_originSize = size();
}

void ImageWidget::resizeEvent(QResizeEvent * event)
{

    QSize s = size();
    m_show_pix = m_ori_pix.scaled(s, Qt::KeepAspectRatio);

}
//
//void ImageWidget::convertToPsd()
//{
//    if (m_mat.channels() == 1)
//    {
//
//        Mat imgNorm, imgColor, mask, mask1;
//        Point minLoc, maxLoc;
//        double minVal, maxVal;
//        threshold(m_mat, mask1, 10, 255, THRESH_BINARY);
//        mask1.convertTo(mask, CV_8UC1);
//        minMaxLoc(m_mat, &minVal, &maxVal, &minLoc, &maxLoc, mask);
//        double scale = 255 / (maxVal - minVal + 10);
//        Mat img, subImg(m_mat.size(), m_mat.type(), Scalar::all(minVal - 10));
//        img = (m_mat - subImg)*scale;
//        img.convertTo(imgNorm, CV_8UC1);
//
//        applyColorMap(imgNorm, imgColor, COLORMAP_HOT);
//        const uchar *pSrc = (const uchar*)imgColor.data;
//        //?Create?QImage?with?same?dimensions?as?input?Mat??
//        QImage image(pSrc, imgColor.cols, imgColor.rows, imgColor.step, QImage::Format_RGB888);
//        m_psd_pix = QPixmap::fromImage(image.rgbSwapped());
//        m_show_pix = m_psd_pix.scaled(size(), Qt::KeepAspectRatio);
//
//        b_show_psd = true;
//
//        repaint();
//
//    }
//    else
//    {
//        QMessageBox::warning(this, QString::fromUtf16(u"提示"), QString::fromUtf16(u"多通道图像无法转换为伪彩色图像"));
//    }
//
//
//}

void ImageWidget::setShowImage(HObject &img)
{
    CopyObj(img, &m_hobj, 1, 1);
    hobj2QImage(m_hobj, m_ori_pix);
    m_show_pix = m_ori_pix.scaled(size(), Qt::KeepAspectRatio);
    repaint();
}
void ImageWidget::hobj2QImage(HObject img, QPixmap& qImg)
{

    HTuple hv_Width, hv_Height, hv_Channels, hv_Types;
    CountChannels(img, &hv_Channels);
    GetImageType(img, &hv_Types);
    GetImageSize(img, &hv_Width, &hv_Height);
    QImage rgb;
    if (1 == hv_Channels)
    {
        HObject hv_CvtImage;
        if (strcmp(hv_Types[0].S(), "byte"))
        {
            HTuple hv_Max, hv_Min, hv_Cols, hv_Type, hv_Rows, hv_GrayVals,hv_Step, hv_Min1, hv_Max1, hv_Range;
            HTuple hv_Indices, hv_AbsoluteHisto, hv_Length, hv_NewVals, hv_Mean, hv_Deviation;
            HObject hv_Region,hv_ScaleImg, hv_ConstImg, hv_ImageReducedImg, hv_Region2;
            HObject hv_SubImage, hv_ImageReducedCImg;
            Threshold(img, &hv_Region, 2, 999999999);
            GrayHistoAbs(hv_Region, img, 1, &hv_AbsoluteHisto);
            MinMaxGray(hv_Region, img, 0, &hv_Min1, &hv_Max, &hv_Range);
            hv_Step = hv_Max / 255;
            TupleInt(hv_Step, &hv_Step);
            if (hv_Step < 1)hv_Step = 1;
            double t = 0.005*hv_Width*hv_Height;
            TupleLength(hv_AbsoluteHisto, &hv_Length);
            for (int i = 0; i < hv_Length; )
            {
                HTuple hv_Sum,hv_Temp= hv_AbsoluteHisto.TupleSelectRange(0, i);
                TupleSum(hv_Temp, &hv_Sum);
                if (hv_Sum > t)
                {
                    hv_Min = i;
                    break;
                }
                i =i+ hv_Step;
            }
            //Intensity(hv_Region, img, &hv_Mean, &hv_Deviation);
            //Threshold(img, &hv_Region2, 10, hv_Mean);
            //AreaCenter(hv_Region2,)
            GetRegionPoints(hv_Region, &hv_Rows, &hv_Cols);
            /*GetGrayval(img, hv_Rows, hv_Cols, &hv_GrayVals);
            TupleSortIndex(hv_GrayVals, &hv_Indices);
            TupleLength(hv_GrayVals, &hv_Length);
            hv_Index = hv_Length*0.005;
            TupleInt(hv_Index, &hv_Index);
            hv_Min= HTuple(hv_GrayVals[HTuple(hv_Indices[hv_Index - 1])]);*/
            /*hv_Max = HTuple(hv_GrayVals[HTuple(hv_Indices[hv_Length - 1])]);*/
            double scale = 255.0 / (hv_Max-hv_Min + 10);
            GetImageType(img, &hv_Type);
            GenImageConst(&hv_ConstImg, hv_Type, hv_Width, hv_Height);
            TupleGenConst(hv_Rows.Length(), hv_Min, &hv_NewVals);
            SetGrayval(hv_ConstImg, hv_Rows, hv_Cols, hv_NewVals);
            ReduceDomain(img, hv_Region, &hv_ImageReducedImg);
            ReduceDomain(hv_ConstImg, hv_Region, &hv_ImageReducedCImg);
            SubImage(hv_ImageReducedImg, hv_ImageReducedCImg, &hv_SubImage,1,0);
            ScaleImage(hv_SubImage, &hv_ScaleImg, scale, 0);
            ConvertImageType(hv_ScaleImg, &hv_CvtImage, "byte");


        }
        else
        {
            CopyObj(img, &hv_CvtImage, 1, 1);
        }

        rgb = QImage(hv_Width.I(), hv_Height.I(), QImage::Format_Grayscale8);
        rgb.setColorCount(256);
        for (int i = 0; i < 256; i++)
        {
            rgb.setColor(i, qRgb(i, i, i));
        }
        HTuple  hv_Pointer, hs_Types;
        GetImagePointer1(hv_CvtImage, &hv_Pointer, NULL, NULL, NULL);
        uchar *pSrc = reinterpret_cast<uchar *>(hv_Pointer[0].L());
        int width = hv_Width.I();
        int height = hv_Height.I();
        for (int i = 0; i < height; i++)
        {
            uchar *pDest = rgb.scanLine(i);
            memcpy(pDest, pSrc, width);
            pSrc += width;
        }
        
        
    }
    else if (3 == hv_Channels)
    {
        HTuple  hv_R, hv_G, hv_B;
        int width = hv_Width.I();
        rgb = QImage(width, hv_Height.I(), QImage::Format_RGB888);

        GetImagePointer3(img, &hv_R, &hv_G, &hv_B, NULL, NULL, NULL);
        rgb = QImage(width, hv_Height.I(), QImage::Format_RGB888);
        uchar *pR = reinterpret_cast<uchar *>(hv_R[0].L());
        uchar *pG = reinterpret_cast<uchar *>(hv_G[0].L());
        uchar *pB = reinterpret_cast<uchar *>(hv_B[0].L());
        for (int i = 0; i<hv_Height.I(); i++)
        {
            uchar *pDest = rgb.scanLine(i);
            for (int j = 0; j<width; j++)
            {
                pDest[j * 3] = pR[i*width + j];
                pDest[j * 3 + 1] = pG[i*width + j];
                pDest[j * 3 + 2] = pB[i*width + j];
            }
        }
    }

    qImg = QPixmap::fromImage(rgb);
}
