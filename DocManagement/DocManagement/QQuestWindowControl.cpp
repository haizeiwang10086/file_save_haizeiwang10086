#include "QQuestWindowControl.h"
#include "qmessagebox.h"
#include "qsqlerror.h"

QQuestWindowControl::QQuestWindowControl(QWidget *parent)
{
    sechWnd.setParent(this);
}
bool QQuestWindowControl::show()
{
    sechWnd.show();
    return true;
}

bool QQuestWindowControl::dbInit(QString dbName, QString userName, QString password, QString &desc)
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

void QQuestWindowControl::showData()
{
    sechWnd.showData();
}

void QQuestWindowControl::resizeEvent(QResizeEvent * event)
{
    sechWnd.resize(this->size());
}

bool QQuestWindowControl::closeDb()
{
    return sechWnd.closeDb();
}

bool QQuestWindowControl::openDb()
{
    return sechWnd.openDb();
}





