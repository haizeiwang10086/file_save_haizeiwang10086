#include "QtQuestWindow.h"
#include "MItemModel.h"
#include "qmessagebox.h"
#include "qsqlerror.h"
#include "qclipboard.h"
#include "qfile.h"
#include "qfileinfo.h"
#include <map>


QtQuestWindow::QtQuestWindow():isDbOpen(false)
{
    qtnWnd.setupUi(this);
    pQSW = new QtNewWindow(this);
    resize(QSize(800, 500));
    stanItemModel = new MItemModel();
    QStringList sl=QSqlDatabase::drivers();
    db = QSqlDatabase::addDatabase("QMYSQL");
    QFile file("./config/config.ini");
   /*QFileInfo fileInfo("./config/config.ini");
    QString path = fileInfo.absoluteFilePath();*/
    if (!file.exists())
    {
        QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("配置文档不存在！"));
    }
    else if (file.open(QIODevice::ReadOnly))
    {
        std::map<QString, QString> mConf;
        while (!file.atEnd())
        {
            QString str(file.readLine());
            QStringList strList = str.split("=");
            mConf.insert(std::pair<QString, QString>(strList[0], strList[1].trimmed()));
        }
        if (mConf.find("data_base_name_qu") != mConf.end() &&
            mConf.find("user_name_qu") != mConf.end() &&
            mConf.find("db_password_qu") != mConf.end())
        {
            db.setDatabaseName(mConf.find("data_base_name_qu")->second);
            db.setHostName("localhost");
            db.setUserName(mConf.find("user_name_qu")->second);
            db.setPassword(mConf.find("db_password_qu")->second);
            if (db.open())
            {
                query = new QSqlQuery(db);
                isDbOpen = true;
            }
        }
        else
        {
            QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("请检查配置文档参数！"));
        }
    }
    else
    {
        QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("配置文档打开失败，请检查文档权限！"));
    }
   
        
    connect(qtnWnd.AddButton,&QPushButton::clicked,
        [=]()
        {
            pQSW->pNWnd.save->setEnabled(true);
            pQSW->pNWnd.btn_modify->setEnabled(false);
            pQSW->show();
        });
    connect(pQSW, &QtNewWindow::saveSignal, this, &QtQuestWindow::dealSave);
    connect(pQSW, &QtNewWindow::modifySignal, this, &QtQuestWindow::dealModify);

    qtnWnd.tableView->setModel(stanItemModel);
    qtnWnd.tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background:rgb(51, 153, 255);color: black; \
                                                            font-weight: bold;padding-left: 4px;border: 1px solid #6c6c6c;}");
    
}

void QtQuestWindow::dealSave(QString title, QString content,QString label)
{

    QString sqlStr("insert into question (title,content,label) values('");
    sqlStr.append(title);
    sqlStr.append("' ,");
    sqlStr.append("'");
    sqlStr.append(content);
    sqlStr.append("' ,");
    sqlStr.append("'");
    sqlStr.append(label);
    sqlStr.append("')");
    
    query->exec(sqlStr);
    showData();
}

void QtQuestWindow::dealModify(QString title, QString content, QString remarks)
{

    QString sqlStr("update info set title='");
    sqlStr.append(title);
    sqlStr.append("' ,content=");
    sqlStr.append("'");
    sqlStr.append(content);
    sqlStr.append("' ,remarks=");
    sqlStr.append("'");
    sqlStr.append(remarks);
    sqlStr.append("'where id="+ editSerial);

    query->exec(sqlStr);
    editSerial.clear();
    showData();
}

void QtQuestWindow::showData()
{
    stanItemModel->clear();
    stanItemModel->setColumnCount(6);
    stanItemModel->setHeaderData(0, Qt::Horizontal, QStringLiteral("标题"));
    stanItemModel->setHeaderData(1, Qt::Horizontal, QStringLiteral("内容"));
    stanItemModel->setHeaderData(2, Qt::Horizontal, QStringLiteral("复制"));
    stanItemModel->setHeaderData(3, Qt::Horizontal, QStringLiteral("删除"));
    stanItemModel->setHeaderData(4, Qt::Horizontal, QStringLiteral("编辑"));
    stanItemModel->setHeaderData(5, Qt::Horizontal, QStringLiteral("查看"));
    QSize size = qtnWnd.tableView->size();
    qtnWnd.tableView->setColumnWidth(0, size.width() / 5);
    qtnWnd.tableView->setColumnWidth(1, size.width()*4 / 5-250);
    qtnWnd.tableView->setColumnWidth(2, 50);
    qtnWnd.tableView->setColumnWidth(3, 50);
    qtnWnd.tableView->setColumnWidth(4, 50);
    qtnWnd.tableView->setColumnWidth(5, 50);

    query->exec("select * from question");
    while (query->next())
    {
        QList<QStandardItem*> newRow;
        QStandardItem *itemTitle = new QStandardItem(query->value(1).toString());
        QStandardItem *itemContent = new QStandardItem(query->value(2).toString());
        newRow.append(itemTitle);
        newRow.append(itemContent);

        stanItemModel->appendRow(newRow);

        QPushButton *copyBtn = new QPushButton(QStringLiteral("复制"));
        copyBtn->resize(QSize(5, copyBtn->height()));
        copyBtn->setProperty("row", query->value(0).toString());
        connect(copyBtn, &QPushButton::clicked, this, &QtQuestWindow::copyData);
        qtnWnd.tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 2), copyBtn);


        QPushButton * btn = new QPushButton(QStringLiteral("删除"));
        btn->resize(QSize(5, btn->height()));
        btn->setProperty("row", query->value(0).toString());
        connect(btn, &QPushButton::clicked, this, &QtQuestWindow::deleteData);
        qtnWnd.tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 3), btn);

        QPushButton *editBtn = new QPushButton(QStringLiteral("编辑"));
        editBtn->resize(QSize(5, btn->height()));
        editBtn->setProperty("row", query->value(0).toString());
        connect(editBtn, &QPushButton::clicked, this, &QtQuestWindow::edit);
        qtnWnd.tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 4), editBtn);

        QPushButton *browseBtn = new QPushButton(QStringLiteral("查看"));
        browseBtn->resize(QSize(5, btn->height()));
        browseBtn->setProperty("row", query->value(0).toString());
        connect(browseBtn, &QPushButton::clicked, this, &QtQuestWindow::browse);
        qtnWnd.tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 5), browseBtn);
        
    }
}

void QtQuestWindow::deleteData()
{
    int ret=QMessageBox::question(this, QStringLiteral("警告"), QStringLiteral("是否删除数据！"));
    if (ret == QMessageBox::Yes)
    {
        QPushButton* btn = (QPushButton*)sender();//获取产生事件的对象
        QString sql("delete from info where id=" + btn->property("row").toString());
        query->exec(sql);
        showData();
    }
}

void QtQuestWindow::browse()
{
    QPushButton *btn = (QPushButton *)sender();
    QString sql("select * from info where id=" + btn->property("row").toString());
    query->exec(sql);
    if (query->next())
    {
        BrowseDlg boe(this);
        boe.boe.label_title->setText(query->value(1).toString());
        boe.boe.label_content->setText(query->value(2).toString());
        boe.boe.label_remarks->setText(query->value(3).toString());
        boe.exec();
    }
}

void QtQuestWindow::recoverData()
{
    bool b=query->exec("rollback");
    showData();
}

void QtQuestWindow::copyData()
{
    QPushButton* btn = (QPushButton*)sender();
    QString sql("select content from info where id=" + btn->property("row").toString());
    query->exec(sql);
    if (query->next())
    {
        QString content = query->value(0).toString();
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(content);
    }
    else
    {
        QMessageBox::warning(this, "警告", "复制失败");
    }
}

void QtQuestWindow::edit()
{
    QPushButton *btn = (QPushButton*)sender();
    editSerial.clear();
    editSerial.append(btn->property("row").toString());
    QString sql("select * from info where id=" + editSerial);
    query->exec(sql);
    if (query->next())
    {
        pQSW->pNWnd.save->setEnabled(false);
        pQSW->pNWnd.btn_modify->setEnabled(true);
        pQSW->pNWnd.lineEdit->setText(query->value(1).toString());
        pQSW->pNWnd.textEdit->setText(query->value(2).toString());
        pQSW->show();
    }
}


void QtQuestWindow::resizeEvent(QResizeEvent * event)
{
    QSize size = this->size();
    qtnWnd.tableView->move(10, 50);
    qtnWnd.tableView->resize(size.width() - 20, size.height() - 80);
    QSize tableSize = qtnWnd.tableView->size();
    qtnWnd.tableView->setColumnWidth(0, tableSize.width() / 4);
    qtnWnd.tableView->setColumnWidth(1, tableSize.width() *3/ 4-250);
    qtnWnd.AddButton->move(tableSize.width()*9 / 10, 20);
    qtnWnd.btn_search->move(tableSize.width() * 4 / 5, 20);
    qtnWnd.lineedit_search_string->move(10, 20);
    qtnWnd.lineedit_search_string->resize(tableSize.width() * 4 / 5 - 10, qtnWnd.btn_search->size().height());

}
