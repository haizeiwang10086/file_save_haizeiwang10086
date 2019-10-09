#pragma once
#include "QuestionWindowVirtualBase.h"
#include "QtQuestWindow.h"

class QSearchWindowControl :public QuestionWindowVirtualBase
{
public:
	virtual  bool show();
	virtual bool dbInit(QString dbName, QString userName, QString password, QString &desc);
    virtual void showData();
private:
	QtQuestWindow sechWnd;

};


