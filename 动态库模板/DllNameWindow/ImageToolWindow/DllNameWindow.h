#pragma once
#include "DllNameWindowVirtualBase.h"
#include "qstandarditemmodel.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "ui_DllNameWindow.h"
#include "qtimagetoolwindow_global.h"

class QTSEARCHWINDOW_EXPORT DllNameWindow :public QWidget
{
public:
    DllNameWindow();

public:
	Ui::DllNameWindow qtnWnd;
	
};


