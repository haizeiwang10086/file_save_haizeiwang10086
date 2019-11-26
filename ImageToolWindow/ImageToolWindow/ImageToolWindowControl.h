#pragma once
#include "ImageToolWindowVirtualBase.h"
#include "ImageToolWindow.h"
#include "qtimagetoolwindow_global.h"

class ImageToolWindowControl :public ImageToolWindowVirtualBase
{
public:
    ImageToolWindowControl(QWidget *parent=Q_NULLPTR);
	virtual  bool show();
    void resizeEvent(QResizeEvent * event);
    

private:
	ImageToolWindow sechWnd;

};

extern "C" QTSEARCHWINDOW_EXPORT ImageToolWindowVirtualBase* createImageToolWindow(QWidget *parent);
extern "C" QTSEARCHWINDOW_EXPORT bool freeImageToolWindow(ImageToolWindowVirtualBase* sechWnd);


