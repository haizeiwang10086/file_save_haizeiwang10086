#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DocManagement.h"
#include "ActiveQt/qaxwidget.h"
#include "TableDisp.h"

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

class DocManagement : public QMainWindow
{
    Q_OBJECT

public:
    DocManagement(QWidget *parent = Q_NULLPTR);
private:
    Ui::DocManagementClass ui;
    TableDisp subWidget;
    QAxWidget *officeContent;
};
