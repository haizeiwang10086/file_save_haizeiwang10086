#pragma once
#include "QuestionWindowVirtualBase.h"
#include "QtQuestWindow.h"
#include "qtsearchwindow_global.h"

class QQuestWindowControl :public QuestionWindowVirtualBase
{
public:
    QQuestWindowControl(QWidget *parent=Q_NULLPTR);
	virtual  bool show();
	virtual bool dbInit(QString dbName, QString userName, QString password, QString &desc);
    virtual void showData();
    void resizeEvent(QResizeEvent * event);
    virtual bool closeDb();
    virtual bool openDb();
private:
	QtQuestWindow sechWnd;

};

extern "C" QTSEARCHWINDOW_EXPORT QuestionWindowVirtualBase* createQuestionWindow(QWidget *parent);
extern "C" QTSEARCHWINDOW_EXPORT bool freeQuestionWindow(QuestionWindowVirtualBase* sechWnd);


