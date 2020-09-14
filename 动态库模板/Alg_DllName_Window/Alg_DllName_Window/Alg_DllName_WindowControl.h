#pragma once
#include "Alg_DllName_WindowVirtualBase.h"
#include "Alg_DllName_Window.h"
#include "qtimagetoolwindow_global.h"

class Alg_DllName_WindowControl :public Alg_DllName_WindowVirtualBase
{
public:
    Alg_DllName_WindowControl(QWidget *parent=Q_NULLPTR);
	virtual  bool show();
    void resizeEvent(QResizeEvent * event);

private:
	Alg_DllName_Window sechWnd;

};

extern "C" QTSEARCHWINDOW_EXPORT Alg_DllName_WindowVirtualBase* createAlg_DllName_Window(QWidget *parent);
extern "C" QTSEARCHWINDOW_EXPORT bool freeAlg_DllName_Window(Alg_DllName_WindowVirtualBase* sechWnd);


