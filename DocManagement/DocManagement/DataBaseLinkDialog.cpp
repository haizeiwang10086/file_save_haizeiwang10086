#include "DataBaseLinkDialog.h"
#include "qfile.h"
#include "qtextstream.h"
#include "qmessagebox.h"
#include "qdir.h"
#include "qsqldatabase.h"

DataBaseLinkDialog::DataBaseLinkDialog(QWidget *parent) :QDialog(parent)
{
	dbl.setupUi(this);

	readConfig();

	connect(dbl.okButton, &QPushButton::clicked, this, &DataBaseLinkDialog::onPushButtonOk);
	connect(dbl.btnTest, &QPushButton::clicked, this, &DataBaseLinkDialog::onPushButtonTest);
}

void DataBaseLinkDialog::onPushButtonOk()
{
	QDir dir("./config");
	bool bMkDir= false;
	if (!dir.exists())//判断文件夹是否存在
	{
		bMkDir = dir.mkpath("./config");
		if (!bMkDir)
		{
			QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("目录创建失败，无法保存配置！"));
		}
	}
	else
	{
		bMkDir = true;
	}
	

	QFile file("./config/config.ini");
	QTextStream out(&file);
	if (!file.exists()&& bMkDir)
	{
		if (file.open(QIODevice::WriteOnly))
		{
			QString strDbName("data_base_name=");
			QString strUserName("user_name=");
			QString strPassword("db_password=");
			strDbName += dbl.lineEdit->text();
			strUserName += dbl.lineEdit_2->text();
			strPassword += dbl.lineEdit_3->text();
			out << strDbName.toUtf8() << endl;
			out<<strUserName.toUtf8()<<endl;
			out << strPassword.toUtf8()<< endl;
		}
	}
	else if (!file.exists() && !bMkDir)
	{
		QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("创建文件失败！"));
	}
	else
	{
		QStringList confTxt;
		QFile fileRead("./config/config.ini");
		
		if (fileRead.open(QIODevice::ReadOnly))
		{
			file.close();
			while (!fileRead.atEnd())
			{
				QString str(fileRead.readLine());
				QStringList strList = str.split("=");
				if (!strList[0].compare("data_base_name"))
				{
					str= strList[0]+"="+ dbl.lineEdit->text();
				}
				else if (!strList[0].compare("user_name"))
				{
					str = strList[0] + "=" + dbl.lineEdit_2->text();
				}
				else if (!strList[0].compare("db_password"))
				{
					str = strList[0] + "=" + dbl.lineEdit_3->text();
				}
				confTxt.append(str);
			}	
		}
		fileRead.close();
		file.open(QIODevice::WriteOnly);
		for (int i = 0; i < confTxt.size(); i++)
		{
			out<<confTxt[i].toUtf8();
		}
	}//else end
	file.close();
	emit dataBaseLinkSignal(dbl.lineEdit->text(), dbl.lineEdit_2->text(), dbl.lineEdit_3->text());
	dbl.lineEdit->clear();
	dbl.lineEdit_2->clear();
	dbl.lineEdit_3->clear();
	
}

void DataBaseLinkDialog::onPushButtonTest()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	QString  dbname(dbl.lineEdit->text());
	QString username(dbl.lineEdit_2->text());
	QString pass(dbl.lineEdit_3->text());
	db.setDatabaseName(dbname);
	db.setHostName("localhost");
	db.setUserName(username);
	db.setPassword(pass);
	if (db.open())
	{
		QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("数据库连接成功！"));
		db.close();
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("数据库连接失败！"));
	}
}

void DataBaseLinkDialog::readConfig()
{
	QFile conFile("./config/config.ini");
	if (conFile.open(QIODevice::ReadOnly))
	{
		QByteArray arr;
		while (conFile.atEnd() == false)
		{
			arr = conFile.readLine();
			QString strConf(arr);
			QStringList confKeyValue = strConf.split("=");
			if (!confKeyValue[0].compare("data_base_name"))
			{
				dbl.lineEdit->setText(confKeyValue[1]);
			}
			else if (!confKeyValue[0].compare("user_name"))
			{
				dbl.lineEdit_2->setText(confKeyValue[1]);
			}
			else if (!confKeyValue[0].compare("db_password"))
			{
				dbl.lineEdit_3->setText(confKeyValue[1]);
			}
		}
	}
	else
	{
		QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("数据库配置文件读取失败！"));
	}
	conFile.close();
}