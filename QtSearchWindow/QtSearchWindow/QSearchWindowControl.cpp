#include "QSearchWindowControl.h"
#include "qmessagebox.h"
#include "qsqlerror.h"


bool QSearchWindowControl::show()
{
	sechWnd.show();
	return true;
}

bool QSearchWindowControl::dbInit(QString dbName, QString userName, QString password, QString &desc)
{
	
	/*sechWnd.db.setHostName("localhost");
	sechWnd.db.setUserName(userName);
	sechWnd.db.setPassword(password);
	sechWnd.db.setDatabaseName(dbName);*/

	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	
	db.setDatabaseName(dbName);
	db.setHostName("localhost");
	db.setUserName(userName);
	db.setPassword(password);

	bool isOpen = db.open();
	if (isOpen)
	{
		desc.append(QStringLiteral("数据库连接成功!"));
	}
	else
	{
		desc.append(sechWnd.db.lastError().text());
	}
	return isOpen;
}


SearchWindowVirtualBase* createSearchWindow()
{
	return new QSearchWindowControl();
}
bool freeSearchWindow(SearchWindowVirtualBase* sechWnd)
{
	if (sechWnd != NULL)
	{
		delete sechWnd;
		return true;
	}
	else
	{
		return false;
	}

}

