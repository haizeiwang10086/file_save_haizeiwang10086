#pragma once
#include <QtCore/qglobal.h>
#include <QWidget>

class  DllNameWindowVirtualBase :public QWidget
{
public:
	virtual bool show() = 0;
};

