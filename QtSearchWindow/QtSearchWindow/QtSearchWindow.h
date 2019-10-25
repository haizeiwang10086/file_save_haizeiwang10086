#pragma once
#include "SearchWindowVirtualBase.h"
#include "QtNewWindow.h"
#include "qstandarditemmodel.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "ui_SearchWindow.h"
#include "BrowseDlg.h"
#include "qtsearchwindow_global.h"

class QTSEARCHWINDOW_EXPORT QtSearchWindow :public QWidget
{
    Q_OBJECT
public:
    QtSearchWindow(QWidget *parent=Q_NULLPTR);

public:
	Ui::SearchWindow sechWnd;
	QtNewWindow *pQSW;
	QStandardItemModel *stanItemModel;
	QSqlDatabase db;
    bool isDbOpen;
	QSqlQuery *query;
    QString editSerial;
    QPushButton *signBtn;
    void dealSave(QString title, QString content, QString remarks);
    void dealModify(QString title, QString content, QString remarks);
    void showData();
    void deleteData();
    void copyData();
    void recoverData();
    void browse();
    void edit();
    void resizeEvent(QResizeEvent * event);
    bool closeDb();
    bool openDb();
    void linkDb();
};


