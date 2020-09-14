#pragma once
#include "QuestionWindowVirtualBase.h"
#include "QuestionNewDlg.h"
#include "qstandarditemmodel.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "ui_QuestionWindow.h"
#include "QuestionBrowseDlg.h"
#include "ExportDlg.h"
#include <QMainWindow>
#include <QMenuBar>

class QuestionDlg :public QMainWindow
{
public:
    QuestionDlg();

public:
    Ui::QuestionWindow qtnWnd;
    QuestionNewDlg *pQSW;
    QStandardItemModel *stanItemModel;
    QSqlDatabase db;
    QSqlQuery *query;
    QString editSerial;
    QMenuBar *pQMenuBar;
    ExportDlg *pExtDlg;
    QStringList label;
    bool isDbOpen;
    void dealSave(QString title, QString content, QString label);
    void dealModify(QString title, QString content, QString label);
    void dealExport();
    void showData();
    void deleteData();
    void copyData();
    void browse();
    void edit();
    void resizeEvent(QResizeEvent * event);
    void on_button_search();
    void on_button_empty();
    void on_comboBox_changed();
    bool closeDb();
    bool openDb();
    void linkDb();
    void saveAsDoc(QStringList info);
};


