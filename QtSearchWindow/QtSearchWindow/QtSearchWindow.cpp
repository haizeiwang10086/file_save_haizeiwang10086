#include "QtSearchWindow.h"
#include "MItemModel.h"
#include "qmessagebox.h"
#include "qsqlerror.h"
#include "qclipboard.h"

QtSearchWindow::QtSearchWindow()
{
    sechWnd.setupUi(this);
    pQSW = new QtNewWindow(this);
    stanItemModel = new MItemModel();
    QStringList sl=QSqlDatabase::drivers();
    db = QSqlDatabase::addDatabase("QMYSQL");
       
    query = new QSqlQuery(db);
        
    connect(sechWnd.AddButton,&QPushButton::clicked,
        [=]()
        {
            pQSW->show();
        });
    connect(pQSW, &QtNewWindow::saveSignal, this, &QtSearchWindow::dealSave);
    connect(sechWnd.RecoverButton, &QPushButton::clicked, this, &QtSearchWindow::recoverData);

    sechWnd.tableView->setModel(stanItemModel);
    sechWnd.tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background:rgb(51, 153, 255);color: black; \
                                                            font-weight: bold;padding-left: 4px;border: 1px solid #6c6c6c;}");
    
    showData();
    
}

void QtSearchWindow::dealSave(QString title, QString content)
{

    QString sqlStr("insert into info (title,content) values('");
    sqlStr.append(title);
    sqlStr.append("' ,");
    sqlStr.append("'");
    sqlStr.append(content);
    sqlStr.append("')");
    
    query->exec(sqlStr);
    showData();
}

void QtSearchWindow::showData()
{
    stanItemModel->clear();
    stanItemModel->setColumnCount(4);
    stanItemModel->setHeaderData(0, Qt::Horizontal, QStringLiteral("标题"));
    stanItemModel->setHeaderData(1, Qt::Horizontal, QStringLiteral("内容"));
    stanItemModel->setHeaderData(2, Qt::Horizontal, QStringLiteral("复制"));
    stanItemModel->setHeaderData(3, Qt::Horizontal, QStringLiteral("删除"));
    QSize size = sechWnd.tableView->size();
    sechWnd.tableView->setColumnWidth(0, size.width() / 4);
    sechWnd.tableView->setColumnWidth(1, size.width()*3 / 4-150);
    sechWnd.tableView->setColumnWidth(2, 50);
    sechWnd.tableView->setColumnWidth(3, 50);

    query->exec("select * from info");
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
        connect(copyBtn, &QPushButton::clicked, this, &QtSearchWindow::copyData);
        sechWnd.tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 2), copyBtn);


        QPushButton * btn = new QPushButton(QStringLiteral("删除"));
        btn->resize(QSize(5, btn->height()));
        btn->setProperty("row", query->value(0).toString());
        connect(btn, &QPushButton::clicked, this, &QtSearchWindow::deleteData);
        
        sechWnd.tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount()-1,3),btn);
    }
}

void QtSearchWindow::deleteData()
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

void QtSearchWindow::recoverData()
{
    bool b=query->exec("rollback");
    showData();
}

void QtSearchWindow::copyData()
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


void QtSearchWindow::resizeEvent(QResizeEvent * event)
{
    QSize size = this->size();
    sechWnd.tableView->move(10, 20);
    sechWnd.tableView->resize(size.width() - 20, size.height() - 80);
    QSize tableSize = sechWnd.tableView->size();
    sechWnd.tableView->setColumnWidth(0, tableSize.width() / 4);
    sechWnd.tableView->setColumnWidth(1, tableSize.width() *3/ 4-150);
    sechWnd.AddButton->move(size.width()*5 / 20, size.height() - 50);
    sechWnd.EditButton->move(size.width() * 2 / 5, size.height() - 50);
    sechWnd.RecoverButton->move(size.width() * 11 / 20, size.height() - 50);
}
