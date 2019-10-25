#pragma once
#include <QtCore/qglobal.h>
#include <QWidget>

class  QuestionWindowVirtualBase:public QWidget
{
public:
	virtual bool show() = 0;
	virtual bool dbInit(QString dbName, QString userName, QString password,QString &desc) = 0;
    virtual void showData() = 0;
    virtual bool closeDb() = 0;
    virtual bool openDb() = 0;
};

