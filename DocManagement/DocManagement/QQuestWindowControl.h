#pragma once
#include "QuestionWindowVirtualBase.h"
#include "QuestionDlg.h"

class QQuestWindowControl :public QuestionWindowVirtualBase
{
public:
    QQuestWindowControl(QWidget *parent = Q_NULLPTR);
    virtual  bool show();
    virtual bool dbInit(QString dbName, QString userName, QString password, QString &desc);
    virtual void showData();
    void resizeEvent(QResizeEvent * event);
    virtual bool closeDb();
    virtual bool openDb();
private:
    QuestionDlg sechWnd;

};




