#pragma once
#include <QtCore/qglobal.h>
#include <QWidget>

class  Alg_DllName_WindowVirtualBase :public QWidget
{
public:
	virtual bool show() = 0;
};

