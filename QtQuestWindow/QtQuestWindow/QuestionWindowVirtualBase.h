#pragma once
#include "qtsearchwindow_global.h"

class  QuestionWindowVirtualBase
{
public:
	virtual bool show() = 0;
	virtual bool dbInit(QString dbName, QString userName, QString password,QString &desc) = 0;
    virtual void showData() = 0;
};

extern "C" QTSEARCHWINDOW_EXPORT QuestionWindowVirtualBase* createQuestionWindow();
extern "C" QTSEARCHWINDOW_EXPORT bool freeQuestionWindow(QuestionWindowVirtualBase* sechWnd);