#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DocManagement.h"
#include "ActiveQt/qaxwidget.h"
#include "SearchWindowVirtualBase.h"
#include "BatchEditName.h"

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

typedef SearchWindowVirtualBase*(*SearchWindow)();
typedef bool(*FreeSearchWindow)();

class DocManagement : public QMainWindow
{
    Q_OBJECT

public:
    DocManagement(QWidget *parent = Q_NULLPTR);
private:
    Ui::DocManagementClass ui;
    QAxWidget *officeContent;
    SearchWindowVirtualBase *sechWnd;
    SearchWindow pSearchWindow;
    BatchEditName batEditWnd;
};
