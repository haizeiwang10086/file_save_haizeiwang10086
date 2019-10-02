#pragma once
#include "SearchWindowVirtualBase.h"
#include "QtNewWindow.h"
#include "qstandarditemmodel.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "ui_SearchWindow.h"


class QTSEARCHWINDOW_EXPORT QtSearchWindow :public QWidget
{
public:
    QtSearchWindow();

public:
	Ui::SearchWindow sechWnd;
	QtNewWindow *pQSW;
	QStandardItemModel *stanItemModel;
	QSqlDatabase db;
	QSqlQuery *query;
    void dealSave(QString title, QString content);
    void showData();
    void deleteData();
    void copyData();
    void recoverData();
    void resizeEvent(QResizeEvent * event);
};


