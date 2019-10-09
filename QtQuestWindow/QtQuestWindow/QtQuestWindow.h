#pragma once
#include "QuestionWindowVirtualBase.h"
#include "QtNewWindow.h"
#include "qstandarditemmodel.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "ui_QuestionWindow.h"
#include "BrowseDlg.h"


class QTSEARCHWINDOW_EXPORT QtQuestWindow :public QWidget
{
public:
    QtQuestWindow();

public:
	Ui::QuestionWindow qtnWnd;
	QtNewWindow *pQSW;
	QStandardItemModel *stanItemModel;
	QSqlDatabase db;
	QSqlQuery *query;
    QString editSerial;
    bool isDbOpen;
    void dealSave(QString title, QString content, QString label);
    void dealModify(QString title, QString content, QString remarks);
    void showData();
    void deleteData();
    void copyData();
    void recoverData();
    void browse();
    void edit();
    void resizeEvent(QResizeEvent * event);
};


