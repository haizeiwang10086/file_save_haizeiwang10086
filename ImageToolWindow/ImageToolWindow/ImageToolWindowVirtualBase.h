#pragma once
#include <QtCore/qglobal.h>
#include <QWidget>

class  ImageToolWindowVirtualBase :public QWidget
{
public:
	virtual bool show() = 0;
};

