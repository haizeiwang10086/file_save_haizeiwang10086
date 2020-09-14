#pragma once
#include <QDialog>
#include "ui_ResizeWindow.h"
#include <opencv2/opencv.hpp>



class ResizeDlg :public QDialog
{
    Q_OBJECT
public:
    ResizeDlg(cv::Mat& img, QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());

signals:
    public slots :
        void getFilePath();
    void keepAspectRatio();
    void dealSave();
    void normalText();
private:

public:
    Ui::ResizeDlg resizeWnd;
    cv::Mat m_mat;

};