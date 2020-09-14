#pragma once
#include <QtCore/qglobal.h>
#include <QWidget>

class  Alg_DeepLearning_WindowVirtualBase :public QWidget
{
public:
	virtual bool show() = 0;
};

