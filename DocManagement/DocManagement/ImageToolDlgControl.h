#pragma once
#include "ImageToolWindowVirtualBase.h"
#include "ImageToolDlg.h"

class ImageToolDlgControl :public ImageToolWindowVirtualBase
{
public:
    ImageToolDlgControl(QWidget *parent = Q_NULLPTR);
    virtual  bool show();
    void resizeEvent(QResizeEvent * event);


private:
    ImageToolDlg sechWnd;

};


