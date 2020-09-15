#pragma once
#include "SearchWindowVirtualBase.h"
#include "MsgNewWindow.h"
#include "qstandarditemmodel.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "ui_MsgBackupWindow.h"
#include "MsgBrowseDlg.h"

class  QtSearchWindow :public QWidget
{
    Q_OBJECT
public:
    QtSearchWindow(QWidget *parent = Q_NULLPTR);

public:
    Ui::MsgBackupWindow sechWnd;
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


