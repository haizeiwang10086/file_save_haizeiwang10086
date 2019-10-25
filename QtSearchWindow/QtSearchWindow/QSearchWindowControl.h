#pragma once
#include "SearchWindowVirtualBase.h"
#include "QtSearchWindow.h"
#include <qwidget.h>

class QSearchWindowControl :public SearchWindowVirtualBase
{
public:
    QSearchWindowControl(QWidget *parent=Q_NULLPTR);
	virtual  bool show();
	virtual bool dbInit(QString dbName, QString userName, QString password, QString &desc);
    virtual void showData();
    void resizeEvent(QResizeEvent *event);
    virtual bool closeDb();
    virtual bool openDb();
private:
    QtSearchWindow sechWnd;
};

extern "C" QTSEARCHWINDOW_EXPORT SearchWindowVirtualBase* createSearchWindow(QWidget *parent);
extern "C" QTSEARCHWINDOW_EXPORT bool freeSearchWindow(SearchWindowVirtualBase* sechWnd);


