#pragma once
#include "SearchWindowVirtualBase.h"
#include "MsgBackupWindow.h"
#include <qwidget.h>

class QSearchWindowControl :public SearchWindowVirtualBase
{
public:
    QSearchWindowControl(QWidget *parent = Q_NULLPTR);
    virtual  bool show();
    virtual bool dbInit(QString dbName, QString userName, QString password, QString &desc);
    virtual void showData();
    void resizeEvent(QResizeEvent *event);
    virtual bool closeDb();
    virtual bool openDb();
private:
    QtSearchWindow sechWnd;
};


