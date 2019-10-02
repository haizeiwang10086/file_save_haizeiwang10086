#pragma once
#include "qtsearchwindow_global.h"

class  SearchWindowVirtualBase
{
public:
	virtual bool show() = 0;
	virtual bool dbInit(QString dbName, QString userName, QString password,QString &desc) = 0;
};

extern "C" QTSEARCHWINDOW_EXPORT SearchWindowVirtualBase* createSearchWindow();
extern "C" QTSEARCHWINDOW_EXPORT bool freeSearchWindow(SearchWindowVirtualBase* sechWnd);