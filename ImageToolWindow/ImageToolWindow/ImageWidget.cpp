#include "ImageWidget.h"
#include <QMimeData>
#include <QUrl>
#include <QMessageBox>

ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent), m_isMove(false), b_show_psd(false)
{
    setAcceptDrops(true);
    m_scaleValue = 0;
    m_imgPath = ":/images/start.jpg";
    m_ori_pix.load(m_imgPath);
    m_mat = imread(m_imgPath.toLatin1().data(), 1);
    m_Init = false;
    setMouseTracking(true);
    
}

void ImageWidget::dragEnterEvent(QDragEnterEvent *event)
{
    //如果为文件，则支持拖放
    if (event->mimeData()->hasFormat("text/uri-list"))
        event->acceptProposedAction();
}

void ImageWidget::dropEvent(QDropEvent *event)
{
    QList<QUrl> files=event->mimeData()->urls();

    if (files.size() < 1)
    {
        return;
    }

    QString fileName=files.at(0).toLocalFile();
    QString expNames("tif,bmp,jpg,png");
    QList<QString> nlist = fileName.split(".");
    QString str = nlist.at(nlist.size()-1);
    if (expNames.contains(str.toLower()))
    {
        m_ori_pix.load(fileName);
        m_imgPath = fileName;
        m_mat = imread(fileName.toLatin1().data(), -1);
        m_show_pix = m_ori_pix.scaled(size(), Qt::KeepAspectRatio);
        b_show_psd = false;
        repaint();
        emit newFileSignal();
    }

}

void ImageWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(0,0, m_show_pix);
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
        if (m_mat.empty())
        {
            std::string str("point: " + std::to_string(imgP.x()) + " , " + std::to_string(imgP.y()));
            QToolTip::showText(p, QString(str.c_str()));
        }
        else
        {
            QSize s = size();
            int x =  1.0*imgP.x() / m_show_pix.width() *m_mat.cols;
            int y = 1.0*imgP.y() / m_show_pix.height()*m_mat.rows;
            if (x > m_mat.cols || y > m_mat.rows)
            {
                std::string str("point: " + std::to_string(imgP.x()) + " , " + std::to_string(imgP.y()));
                QToolTip::showText(p, QString(str.c_str()));
            }
            else
            {
                QString str;
                if (m_mat.channels() == 3)
                {
                    Vec3b v = m_mat.at<Vec3b>(y,x);
                    str = QString("point: %1 , %2\nvalues: ( %3 %4 %5 )") \
                        .arg(imgP.x()).arg(imgP.y()).arg(v[0]).arg(v[1]).arg(v[2]);
                }
                else if (m_mat.channels() == 1)
                {
                    int type = m_mat.type();
                   
                    if (m_mat.type() == CV_8UC1)
                    {
                        uchar d = m_mat.at<uchar>(y, x);
                        str = QString("point: %1 , %2\nvalues: %3") \
                            .arg(imgP.x()).arg(imgP.y()).arg(d);
                    }
                    else if(m_mat.type() == CV_16UC1)
                    {
                        ushort d = m_mat.at<ushort>(y, x);
                        str = QString("point: %1 , %2\nvalues: %3") \
                            .arg(imgP.x()).arg(imgP.y()).arg(d);
                    }
                    else if (m_mat.type() == CV_16SC1)
                    {
                        short d = m_mat.at<short>(y, x);
                        str = QString("point: %1 , %2\nvalues: %3") \
                            .arg(imgP.x()).arg(imgP.y()).arg(d);
                    }
                    else if (m_mat.type() == CV_32S)
                    {
                        int d = m_mat.at<int>(y, x);
                        str = QString("point: %1 , %2\nvalues: %3") \
                            .arg(imgP.x()).arg(imgP.y()).arg(d);
                    }
                    else if (m_mat.type() == CV_32F)
                    {
                        float d = m_mat.at<float>(y, x);
                        str = QString("point: %1 , %2\nvalues: %3") \
                            .arg(imgP.x()).arg(imgP.y()).arg(d);
                    }
                    else if (m_mat.type() == CV_64F)
                    {
                        double d = m_mat.at<double>(y, x);
                        str = QString("point: %1 , %2\nvalues: %3") \
                            .arg(imgP.x()).arg(imgP.y()).arg(d);
                    }
                    else
                    {
                        str = QString("point: %1 , %2\nvalues: %3") \
                            .arg(imgP.x()).arg(imgP.y()).arg("数据类型未解析");
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
        QPointF oriP= event->pos();
        resize((m_scaleValue*m_originSize).toSize());
        

        if (event->delta() > 0)
        {
            QPointF p = this->pos() - QPointF((oriP.x()*0.1) / (m_scaleValue - 0.1), (oriP.y()*0.1) / (m_scaleValue - 0.1));
            move(p.x(),p.y() );//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
        }
        else
        {
            QPointF p = this->pos() + QPointF((oriP.x()*0.1) / (m_scaleValue +0.1), (oriP.y()*0.1) / (m_scaleValue + 0.1));
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
    if(!b_show_psd)
        m_show_pix = m_ori_pix.scaled(s, Qt::KeepAspectRatio);
    else
        m_show_pix = m_psd_pix.scaled(s, Qt::KeepAspectRatio);
}

void ImageWidget::convertToPsd()
{
    if (m_mat.channels() == 1)
    {

        Mat imgNorm, imgColor, mask, mask1;
        Point minLoc, maxLoc;
        double minVal, maxVal;
        threshold(m_mat, mask1, 10, 255, THRESH_BINARY);
        mask1.convertTo(mask, CV_8UC1);
        minMaxLoc(m_mat, &minVal, &maxVal, &minLoc, &maxLoc, mask);
        double scale = 255 / (maxVal - minVal + 10);
        Mat img, subImg(m_mat.size(), m_mat.type(), Scalar::all(minVal - 10));
        img = (m_mat - subImg)*scale;
        img.convertTo(imgNorm, CV_8UC1);

        applyColorMap(imgNorm, imgColor, COLORMAP_HOT);
        const uchar *pSrc = (const uchar*)imgColor.data;
        //?Create?QImage?with?same?dimensions?as?input?Mat??
        QImage image(pSrc, imgColor.cols, imgColor.rows, imgColor.step, QImage::Format_RGB888);
        m_psd_pix = QPixmap::fromImage(image.rgbSwapped());
        m_show_pix = m_psd_pix.scaled(size(), Qt::KeepAspectRatio);

        b_show_psd = true;

        repaint();

    }
    else
    {
        QMessageBox::warning(this, QString::fromUtf16(u"提示"), QString::fromUtf16(u"多通道图像无法转换为伪彩色图像"));
    }

    
}
