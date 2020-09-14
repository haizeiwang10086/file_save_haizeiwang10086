#include "ResizeWnd.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDateTime>
#include <QRadioButton>
#include <QLineEdit>

using namespace cv;

ResizeDlg::ResizeDlg(Mat& img, QWidget *parent, Qt::WindowFlags f) :QDialog(parent), m_mat(img)
{
    resizeWnd.setupUi(this);
    resizeWnd.width_edit->setValidator(new QIntValidator(1, 99999999, this));
    resizeWnd.height_edit->setValidator(new QIntValidator(1, 99999999, this));;
    connect(resizeWnd.save, &QPushButton::clicked, this, &ResizeDlg::dealSave);
    connect(resizeWnd.aspect_ratio, &QRadioButton::clicked, this, &ResizeDlg::keepAspectRatio);
    connect(resizeWnd.routeBtn, &QPushButton::clicked, this, &ResizeDlg::getFilePath);
    connect(resizeWnd.width_edit, &QLineEdit::textChanged, this, &ResizeDlg::normalText);
}

void ResizeDlg::dealSave()
{
    QString height = resizeWnd.height_edit->text();
    QString width = resizeWnd.width_edit->text();
    QString path = resizeWnd.route_edit->text();
    if (height.isEmpty() || width.isEmpty() || path.isEmpty())
    {
        QMessageBox::warning(this, QString::fromUtf16(u"警告"), QString::fromUtf16(u"请输入：高度、宽度和保存路径！"));
        return;
    }
    Mat scaleImg;
    cv::resize(m_mat, scaleImg, Size(width.toInt(), height.toInt()));
    imwrite(path.toLatin1().data(), scaleImg);
    resizeWnd.height_edit->clear();
    resizeWnd.width_edit->clear();
    resizeWnd.route_edit->clear();
    close();
}

void ResizeDlg::getFilePath()
{
    QString path = QFileDialog::getExistingDirectory(this, QString::fromUtf16(u"路径"), "D:/");
    QDateTime currentDataTime = QDateTime::currentDateTime();
    QString imgName = currentDataTime.toString("yyyy_MM_dd_hh_mm_ss.jpg");
    path.append("/").append(imgName);
    resizeWnd.route_edit->setText(path);
}

void ResizeDlg::keepAspectRatio()
{
    if (resizeWnd.aspect_ratio->isChecked())
    {
        if (resizeWnd.width_edit->text().isEmpty())
        {
            resizeWnd.height_edit->setEnabled(false);
            return;
        }
        else
        {
            resizeWnd.height_edit->setEnabled(false);
            double width = m_mat.cols;
            double height = m_mat.rows;
            double ratio = width / height;
            int resizeH = resizeWnd.width_edit->text().toInt() / ratio;
            resizeWnd.height_edit->setText(QString::number(resizeH));
        }
    }
    else
    {
        resizeWnd.height_edit->setEnabled(true);
    }
}

void ResizeDlg::normalText()
{
    if (resizeWnd.width_edit->text().isEmpty())
    {
        return;
    }
    else if (resizeWnd.aspect_ratio->isChecked())
    {
        double width = m_mat.cols;
        double height = m_mat.rows;
        double ratio = width / height;
        int resizeH = resizeWnd.width_edit->text().toInt() / ratio;
        resizeWnd.height_edit->setText(QString::number(resizeH));
    }
    else
    {
        return;
    }
}

