#pragma once
#include "SearchWindowVirtualBase.h"
#include "QtSearchWindow.h"

class QSearchWindowControl :public SearchWindowVirtualBase
{
public:
	virtual  bool show();
	virtual bool dbInit(QString dbName, QString userName, QString password, QString &desc);
    virtual void showData();
private:
	QtSearchWindow sechWnd;

};


