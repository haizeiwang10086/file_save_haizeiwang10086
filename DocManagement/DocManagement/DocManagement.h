#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DocManagement.h"
#include "ActiveQt/qaxwidget.h"
#include "SearchWindowVirtualBase.h"
#include "ImageToolDlg.h"
#include "BatchEditName.h"
#include "DataBaseLinkDialog.h"
#include "DocDisp.h"
#include "FileManager.h"
#include "QuestionDlg.h"



#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

typedef SearchWindowVirtualBase*(*SechWindow)(QWidget *parent);
typedef bool(*FreeSechWindow)(SearchWindowVirtualBase* sechWnd);


class DocManagement : public QMainWindow
{
    Q_OBJECT

public:
    DocManagement(QWidget *parent = Q_NULLPTR);
	void linkDb(QString dbName, QString userName, QString password);
    /*void resizeEvent(QResizeEvent * event);*/
    void dealTabClick(int idex);
    
private:
    Ui::DocManagementClass ui;
    QAxWidget *officeContent;
    QuestionWindowVirtualBase *questWnd;
    SearchWindowVirtualBase *sechWnd;
    ImageToolWindowVirtualBase *imgToolWnd;
    FreeSechWindow pFreeSechWND;
    SechWindow pSechWindow;
	DataBaseLinkDialog dbDlg;
    BatchEditName batEditWnd;
    DocDisp docDisp;
    FileManager *fileManager;
    
};
