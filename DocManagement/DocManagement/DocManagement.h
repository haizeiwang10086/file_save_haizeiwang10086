#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DocManagement.h"
#include "ActiveQt/qaxwidget.h"
#include "QuestionWindowVirtualBase.h"
#include "BatchEditName.h"
#include "DataBaseLinkDialog.h"

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

typedef QuestionWindowVirtualBase*(*QuestionWindow)();
typedef bool(*FreeQuestionWindow)();

class DocManagement : public QMainWindow
{
    Q_OBJECT

public:
    DocManagement(QWidget *parent = Q_NULLPTR);
	void linkDb(QString dbName, QString userName, QString password);
private:
    Ui::DocManagementClass ui;
    QAxWidget *officeContent;
    QuestionWindowVirtualBase *sechWnd;
    QuestionWindow pSearchWindow;
	DataBaseLinkDialog dbDlg;
    BatchEditName batEditWnd;
};
