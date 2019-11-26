#pragma once
#include "DllNameWindowVirtualBase.h"
#include "DllNameWindow.h"
#include "qtimagetoolwindow_global.h"

class DllNameWindowControl :public DllNameWindowVirtualBase
{
public:
    DllNameWindowControl(QWidget *parent=Q_NULLPTR);
	virtual  bool show();
    void resizeEvent(QResizeEvent * event);

private:
	DllNameWindow sechWnd;

};

extern "C" QTSEARCHWINDOW_EXPORT DllNameWindowVirtualBase* createDllNameWindow(QWidget *parent);
extern "C" QTSEARCHWINDOW_EXPORT bool freeDllNameWindow(DllNameWindowVirtualBase* sechWnd);


