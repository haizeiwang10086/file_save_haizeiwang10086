#pragma once

#include "ui_FileManager.h"
#include "MItemModel.h"
#include <QMainWindow>
#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "NewDlg.h"
#include "DispRemarks.h"

class FileManager :public QMainWindow
{
public:
    FileManager(QWidget *parent=Q_NULLPTR);
    void resizeEvent(QResizeEvent * event);
    void linkDb();
    bool closeDb();
    bool openDb();
    void refresh();
    void searchAll();
    void showData();
    void load();
    void deleteData();
    void browse();
    void addFile();
    void search();
    void upload(QString path, QString remarks);
private:
    Ui::FileManager ui_manager;
    QStandardItemModel *stanItemModel;
    QSqlDatabase db;
    QSqlQuery *query;
    bool isDbOpen;
    NewDlg *newDlg;

};
