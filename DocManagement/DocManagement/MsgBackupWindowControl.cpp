#include "MsgBackupWindowControl.h"
#include "qmessagebox.h"
#include "qsqlerror.h"



QSearchWindowControl::QSearchWindowControl(QWidget *parent)
{
    sechWnd.setParent(this);
}

bool QSearchWindowControl::show()
{
    sechWnd.show();
    return true;
}


bool QSearchWindowControl::dbInit(QString dbName, QString userName, QString password, QString &desc)
{

    sechWnd.db.setHostName("localhost");
    sechWnd.db.setUserName(userName);
    sechWnd.db.setPassword(password);
    sechWnd.db.setDatabaseName(dbName);
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setDatabaseName(dbName);
    db.setHostName("localhost");
    db.setUserName(userName);
    db.setPassword(password);*/

    bool isOpen = sechWnd.db.open();
    if (isOpen)
    {

        sechWnd.query = new QSqlQuery(sechWnd.db);
        desc.append(QStringLiteral("数据库连接成功!"));
    }
    else
    {
        desc.append(sechWnd.db.lastError().text());
    }
    return isOpen;
}

void QSearchWindowControl::showData()
{
    sechWnd.showData();
}


SearchWindowVirtualBase* createSearchWindow(QWidget *parent)
{
    return new QSearchWindowControl(parent);
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

void QSearchWindowControl::resizeEvent(QResizeEvent *event)
{
    QSize size = this->size();
    sechWnd.resize(size.width(), size.height() - 10);
}

bool QSearchWindowControl::closeDb()
{
    return sechWnd.closeDb();
}

bool QSearchWindowControl::openDb()
{
    return sechWnd.openDb();
}

