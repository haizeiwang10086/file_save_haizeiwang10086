#pragma once

#include "ui_DataBaseLink.h"
#include <map>

class DataBaseLinkDialog : public QDialog
{
	Q_OBJECT
public:
	DataBaseLinkDialog(QWidget * parent = NULL);
	void onPushButtonTest();
    void editConfig(std::map<QString,QString> &mConf, QString strConfKey, QString strConfValue);
	void onPushButtonOk();
	void readConfig();

public:
	Ui::DataBaseLink dbl;

signals:
	void dataBaseLinkSignal(QString dbName,QString userName,QString password);
};
