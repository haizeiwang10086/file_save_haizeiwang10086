#pragma once

#include "ui_DataBaseLink.h"

class DataBaseLinkDialog : public QDialog
{
	Q_OBJECT
public:
	DataBaseLinkDialog(QWidget * parent = NULL);
	void onPushButtonTest();
	void onPushButtonOk();
	void readConfig();

public:
	Ui::DataBaseLink dbl;

signals:
	void dataBaseLinkSignal(QString dbName,QString userName,QString password);
};
