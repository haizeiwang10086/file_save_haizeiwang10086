#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DocManagement.h"
#include "ActiveQt/qaxwidget.h"
#include "QuestionWindowVirtualBase.h"
#include "SearchWindowVirtualBase.h"
#include "BatchEditName.h"
#include "DataBaseLinkDialog.h"
#include "DocDisp.h"

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

typedef QuestionWindowVirtualBase*(*QuestionWindow)(QWidget *parent);
typedef bool(*FreeQuestionWindow)();
typedef SearchWindowVirtualBase*(*SechWindow)(QWidget *parent);
typedef bool(*FreeSechWindow)(SearchWindowVirtualBase* sechWnd);


class DocManagement : public QMainWindow
{
    Q_OBJECT

public:
    DocManagement(QWidget *parent = Q_NULLPTR);
	void linkDb(QString dbName, QString userName, QString password);
    void resizeEvent(QResizeEvent * event);
    void dealTabClick(int idex);
private:
    Ui::DocManagementClass ui;
    QAxWidget *officeContent;
    QuestionWindowVirtualBase *questWnd;
    SearchWindowVirtualBase *sechWnd;
    FreeSechWindow pFreeSechWND;
    QuestionWindow pQuestWindow;
    SechWindow pSechWindow;
	DataBaseLinkDialog dbDlg;
    BatchEditName batEditWnd;
    DocDisp docDisp;
    
};
