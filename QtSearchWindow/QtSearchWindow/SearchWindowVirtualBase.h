#pragma once
#include <QtCore/qglobal.h>
#include <qobject.h>
#include <qwidget.h>

class  SearchWindowVirtualBase : public QWidget
{
    
public:
    //SignClass closeSign;
    virtual bool show() = 0;
    virtual bool dbInit(QString dbName, QString userName, QString password, QString &desc) = 0;
    virtual void showData() = 0;
    virtual bool closeDb() = 0; 
    virtual bool openDb() = 0;

};


