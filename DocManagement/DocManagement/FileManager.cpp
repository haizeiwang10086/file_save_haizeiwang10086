#include "FileManager.h"
#include <QMessageBox>
#include <QFile>
#include <QPushButton>
#include <QFileDialog>
#include <QString>
#include <QDate>

FileManager::FileManager(QWidget *parent):isDbOpen(false)
{
    ui_manager.setupUi(this);
    setCentralWidget(ui_manager.widget);
    stanItemModel = new MItemModel();
    newDlg = new NewDlg(this);
    ui_manager.tableView->setModel(stanItemModel);
    ui_manager.tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background:rgb(51, 153, 255);color: black; \
                                                            font-weight: bold;padding-left: 4px;border: 1px solid #6c6c6c;}");

    connect(ui_manager.AddButton, &QPushButton::clicked, this, &FileManager::addFile);
    connect(newDlg, &NewDlg::upload, this, &FileManager::upload);
    connect(ui_manager.btn_empty, &QPushButton::clicked, this, &FileManager::refresh);
    connect(ui_manager.btn_search, &QPushButton::clicked, this, &FileManager::search);

    QDir dir("./temp");
    if (!dir.exists())dir.mkpath("./temp");

}

void FileManager::resizeEvent(QResizeEvent * event)
{
    QSize tableSize = ui_manager.tableView->size();
    ui_manager.tableView->setColumnWidth(0, tableSize.width()-330);
	/*if (!isDbOpen)
	{
		linkDb();
		QString sql("select id,name,label,date from files");
		query->exec(sql);
        searchAll();
		showData();
		isDbOpen = true;
	}*/
}

void FileManager::linkDb()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    QFile file("./config/config.ini");

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
        if (mConf.find("data_base_name") != mConf.end() &&
            mConf.find("user_name") != mConf.end() &&
            mConf.find("db_password") != mConf.end())
        {
            db.setDatabaseName(mConf.find("data_base_name")->second);
            db.setHostName("localhost");
            db.setUserName(mConf.find("user_name")->second);
            db.setPassword(mConf.find("db_password")->second);
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

}

bool FileManager::closeDb()
{
    if (isDbOpen)
    {
        db.close();
        isDbOpen = false;
    }
    return true;
}

bool FileManager::openDb()
{
    if (!isDbOpen)
    {
        linkDb();
        searchAll();
        showData();
        isDbOpen = true;
    }
    return isDbOpen;
}

void FileManager::load()
{
	QPushButton *btn = (QPushButton*)sender();
	QString sql = "select name,file from files where id=" + btn->property("row").toString();
	
	query->exec(sql);
	if (query->next())
	{
		QByteArray rt = query->value(1).toByteArray();
        QString path = QFileDialog::getExistingDirectory(this, QString::fromUtf16(u"路径"), QString::fromUtf16(u"../"));
		QFile file(path+"/"+query->value(0).toString());
		if (!file.open(QIODevice::WriteOnly))
		{
			QMessageBox::warning(this, QString::fromUtf16(u"警告"), QString::fromUtf16(u"下载失败！"));
			return;
		}
		file.write(rt);
		file.close();

        QMessageBox::about(this, QString::fromUtf16(u"提示"), QString::fromUtf16(u"下载成功！"));
	}

}

void FileManager::search()
{
    QString name = ui_manager.lineedit_search_string->text().toLower();
    QString sql("select id,name from files");
    query->exec(sql);
    QString strSql("select id,name,label,date from files where");
    bool isHave = false;
    while (query->next())
    {
        QString dbTitle = query->value(1).toString().toLower();

        if (dbTitle.contains(name))
        {
            strSql += " id=" + query->value(0).toString() + " or";
            isHave = true;
        }

    }
    if (isHave)
    {
        std::string sechSql(strSql.toUtf8());
        std::string sechSql1;
        sechSql1.assign(sechSql.begin(), sechSql.end() - 3);

        query->exec(QString(sechSql1.c_str()));
        showData();
    }
    else
    {
        QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("未查询到相关记录！"));
    }
}
void FileManager::deleteData()
{
    QPushButton* btn = (QPushButton*)sender();
    int ret = QMessageBox::question(this, QStringLiteral("警告"), QStringLiteral("是否删除数据！"));
    if (ret == QMessageBox::Yes)
    {
        QString sql = "delete from files where id=" + btn->property("row").toString();
        query->exec(sql);
        searchAll();
        showData();
    }
}

void FileManager::browse()
{
    QPushButton *btn = (QPushButton *)sender();
    QString sql("select name,label,date from files where id=" + btn->property("row").toString());
    query->exec(sql);
    if (query->next())
    {
        DispRemarks dr(this);
        QString title = QString::fromUtf16(u"文件名：") + query->value(0).toString() + "\n\n";
        QString label = QString::fromUtf16(u"备注：")+query->value(1).toString() + "\n\n";
        QString date= QString::fromUtf16(u"上传日期：")+ query->value(2).toString();
       
        dr.ui_DispRemarks.label->setText(title + label+date);

        dr.exec();
    }
}

void FileManager::refresh()
{
    searchAll();
    showData();
}

void FileManager::searchAll()
{
    QString sql("select id,name,label,date from files");
    query->exec(sql);
}
void FileManager::showData()
{
    stanItemModel->clear();
    stanItemModel->setColumnCount(5);
    stanItemModel->setHeaderData(0, Qt::Horizontal, QStringLiteral("文件名"));
	stanItemModel->setHeaderData(1, Qt::Horizontal, QStringLiteral("时间"));
    stanItemModel->setHeaderData(2, Qt::Horizontal, QStringLiteral("下载"));
    stanItemModel->setHeaderData(3, Qt::Horizontal, QStringLiteral("删除"));
    stanItemModel->setHeaderData(4, Qt::Horizontal, QStringLiteral("查看"));
    QSize size = ui_manager.tableView->size();
    ui_manager.tableView->setColumnWidth(0, size.width()-330);
    ui_manager.tableView->setColumnWidth(1, 115);
    ui_manager.tableView->setColumnWidth(2, 50);
    ui_manager.tableView->setColumnWidth(3, 50);
    ui_manager.tableView->setColumnWidth(4, 50);

    while (query->next())
    {
        QList<QStandardItem*> newRow;
        QStandardItem * fileName = new QStandardItem(query->value(1).toString());
		QDate dat1 = query->value(3).toDate();
		QStandardItem * date = new QStandardItem(query->value(3).toDateTime().toString("yyyy-MM-dd"));
        newRow.append(fileName);
		newRow.append(date);
        stanItemModel->appendRow(newRow);

        QPushButton *copyBtn = new QPushButton(QStringLiteral("下载"));
        copyBtn->resize(QSize(5, copyBtn->height()));
        copyBtn->setProperty("row", query->value(0).toString());
        connect(copyBtn, &QPushButton::clicked, this, &FileManager::load);
        ui_manager.tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 2), copyBtn);


        QPushButton * btn = new QPushButton(QStringLiteral("删除"));
        btn->resize(QSize(5, btn->height()));
        btn->setProperty("row", query->value(0).toString());
        connect(btn, &QPushButton::clicked, this, &FileManager::deleteData);
        ui_manager.tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 3), btn);

        QPushButton *browseBtn = new QPushButton(QStringLiteral("查看"));
        browseBtn->resize(QSize(5, btn->height()));
        browseBtn->setProperty("row", query->value(0).toString());
        connect(browseBtn, &QPushButton::clicked, this, &FileManager::browse);
        ui_manager.tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 4), browseBtn);

    }
}

void FileManager::addFile()
{
   
    newDlg->exec();
}

void FileManager::upload(QString path, QString remarks)
{
    QFile file(path);
    if (!file.exists())
    {
        QMessageBox::warning(this, QString::fromUtf16(u"警告"), QString::fromUtf16(u"文件不存在！"));
        return;
    }
    QStringList paths = path.split("/");
    QStringList names = paths.at(paths.size() - 1).split(".");
    QDir dir("./temp");
    QString stempFile = dir.absolutePath() + "/1." + names.at(names.size() - 1);
    file.copy(stempFile);

    QString sql = "insert into files(name,file,label) values('" + paths.at(paths.size() - 1) + "'," \
                    +"load_file('"+ stempFile +"'),'"+remarks+"')";
    
    bool flag = query->exec(sql);
    QFile tempFile(stempFile);
    tempFile.remove();
    if (flag)QMessageBox::warning(this, QString::fromUtf16(u"提示"), QString::fromUtf16(u"上传成功！"));
    else  QMessageBox::warning(this, QString::fromUtf16(u"提示"), QString::fromUtf16(u"上传失败！"));
 
    
    
    searchAll();
    showData();
}
