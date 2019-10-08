#pragma once
#include "SearchWindowVirtualBase.h"
#include "QtNewWindow.h"
#include "qstandarditemmodel.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "ui_SearchWindow.h"
#include "BrowseDlg.h"


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
    QString editSerial;
    void dealSave(QString title, QString content, QString remarks);
    void dealModify(QString title, QString content, QString remarks);
    void showData();
    void deleteData();
    void copyData();
    void recoverData();
    void browse();
    void edit();
    void resizeEvent(QResizeEvent * event);
};


