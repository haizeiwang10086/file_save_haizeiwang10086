#include "Utils.h"

using namespace cv;
using namespace std;

void Mat2QImage(cv::Mat &mat, QImage& rgb)
{
    if (mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        image.setColorCount(256);
        for (int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        uchar *pSrc = mat.data;
        for (int row = 0; row < mat.rows; row++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        rgb = image.copy();
    }
    else if (mat.type() == CV_8UC3)
    {
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        rgb = image.rgbSwapped();
    }
    else if (mat.type() == CV_8UC4)
    {

        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        rgb = image.copy();
    }
    else
    {
        Mat dst;

        if (mat.channels() == 1)
        {
            double m, M, scale, shift;
            minMaxLoc(mat, &m, &M, NULL, NULL);
            scale = 255 / (M - m);
            shift = -m*scale;
            dst = mat*scale + shift;
            dst.convertTo(dst, CV_8UC1);
            uchar *pSrc = dst.data;
            QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
            image.setColorCount(256);
            for (int i = 0; i < 256; i++)
            {
                image.setColor(i, qRgb(i, i, i));
            }

            for (int r = 0; r < mat.rows; r++)
            {
                uchar *pDst = image.scanLine(r);
                memcpy(pDst, pSrc, mat.cols);
                pSrc += dst.step;
            }
            rgb = image.copy();


        }
        else
        {
            const uchar *pSrc = (const uchar *)dst.data;
            QImage image(pSrc, mat.cols, mat.rows, dst.step, QImage::Format_BGR30);
            rgb = image.copy();
        }

    }
}

void QImage2Mat(QImage& rgb, Mat &mat)
{
    
    if (rgb.format() == QImage::Format_RGB32)
    {
        void* pSrc = (void*)rgb.bits();
        int w = rgb.width();
        int h = rgb.height();
        Mat img(w, h, CV_8UC3, pSrc);
        mat = img.clone();
    }
}

QString baseName(QString filePath)
{
    string path= filePath.toLatin1().data();
    int loc1=path.find_last_of("/");
    int loc2 = path.find_last_of("\\");
    int loc = max(loc1, loc2);
    string sBaseName(path.begin() + loc, path.end() - 1);
    return sBaseName.c_str();
}