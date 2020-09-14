#include "QuestionDlg.h"
#include "qmessagebox.h"
#include "qsqlerror.h"
#include "qclipboard.h"
#include "qfile.h"
#include "MItemModel.h"
#include <map>
#include <QMenu>
#include <QTextStream>
#include <ActiveQt/QAxObject>

QuestionDlg::QuestionDlg() :isDbOpen(false)
{
    qtnWnd.setupUi(this);
    setCentralWidget(qtnWnd.widget);
    pQSW = new QuestionNewDlg(this);
    pExtDlg = new ExportDlg(this);
    resize(QSize(800, 500));
    stanItemModel = new MItemModel();

    pQMenuBar = menuBar();
    pQMenuBar->setStyleSheet("QMenuBar{background-color:rgb(37,199,254)}");
    QMenu *pQMenu = pQMenuBar->addMenu(QString::fromUtf16(u"功能"));
    QAction *pExt = pQMenu->addAction(QString::fromUtf16(u"导出"));
    connect(qtnWnd.AddButton, &QPushButton::clicked,
        [=]()
    {
        pQSW->pNWnd.save->setEnabled(true);
        pQSW->pNWnd.btn_modify->setEnabled(false);
        pQSW->show();
    });
    connect(pQSW, &QuestionNewDlg::saveSignal, this, &QuestionDlg::dealSave);
    connect(pQSW, &QuestionNewDlg::modifySignal, this, &QuestionDlg::dealModify);
    connect(qtnWnd.btn_search, &QPushButton::clicked, this, &QuestionDlg::on_button_search);
    connect(qtnWnd.btn_empty, &QPushButton::clicked, this, &QuestionDlg::on_button_empty);
    connect(qtnWnd.comboBox_label, &QComboBox::currentTextChanged, this, &QuestionDlg::on_comboBox_changed);
    connect(pExt, &QAction::triggered, this, &QuestionDlg::dealExport);
    connect(pExtDlg, &ExportDlg::saveSignal, this, &QuestionDlg::saveAsDoc);


    qtnWnd.tableView->setModel(stanItemModel);
    qtnWnd.tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background:rgb(51, 153, 255);color: black; \
                                                            font-weight: bold;padding-left: 4px;border: 1px solid #6c6c6c;}");

}

void QuestionDlg::linkDb()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    QFile file("./config/config.ini");
    /*QFileInfo fileInfo("./config/config.ini");
    QString path = fileInfo.absoluteFilePath();
    qDebug() << path << endl;*/
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

        std::map<QString, QString>::iterator iter;
        if ((iter = mConf.find("label")) != mConf.end())
        {
            label = iter->second.split(";");
            label.push_front("all");
            qtnWnd.comboBox_label->addItems(label);
        }
        else
        {
            QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("标签加载失败请检查配置文档！"));
        }


    }
    else
    {
        QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("配置文档打开失败，请检查文档权限！"));
    }

}

void QuestionDlg::dealSave(QString title, QString content, QString label)
{
    if (title.contains("\""))title.replace("\"", "\\\"");
    if (title.contains("\'"))title.replace("\'", "\\\'");
    if (content.contains("\""))content.replace("\"", "\\\"");
    if (content.contains("\'"))content.replace("\'", "\\\'");
    QString sqlStr("insert into question (title,content,label) values('");
    sqlStr.append(title);
    sqlStr.append("' ,");
    sqlStr.append("'");
    sqlStr.append(content);
    sqlStr.append("' ,");
    sqlStr.append("'");
    label.replace("\n", "");
    sqlStr.append(label);
    sqlStr.append("')");

    query->exec(sqlStr);
    QString sql("select * from question order by id desc");
    query->exec(sql);
    showData();
}

void QuestionDlg::dealModify(QString title, QString content, QString label)
{
    if (title.contains("\""))title.replace("\"", "\\\"");
    if (title.contains("\'"))title.replace("\'", "\\\'");
    if (content.contains("\""))content.replace("\"", "\\\"");
    if (content.contains("\'"))content.replace("\'", "\\\'");
    QString sqlStr("update question set title='");
    sqlStr.append(title);
    sqlStr.append("' ,content=");
    sqlStr.append("'");
    sqlStr.append(content);
    sqlStr.append("' ,label=");
    sqlStr.append("'");
    sqlStr.append(label);
    sqlStr.append("'where id=" + editSerial);

    query->exec(sqlStr);
    editSerial.clear();
    QString sql("select * from question order by id desc");
    query->exec(sql);
    showData();
}

void QuestionDlg::dealExport()
{
    pExtDlg->ui_extDlg.lineEdit->clear();
    pExtDlg->setType(label);
    pExtDlg->exec();
}
#include <fstream>
void QuestionDlg::saveAsDoc(QStringList info)
{
    if (info.size() != 2)
    {
        QMessageBox::warning(this, QString::fromUtf16(u"警告"), QString::fromUtf16(u"参数有误！"));
        return;
    }
    QFile outFile(info.at(0));
    outFile.open(QIODevice::WriteOnly);
    QTextStream outStream(&outFile);
    QString sql = "select * from question where label='" + info.at(1) + "' order by id desc";
    query->exec(sql);
    while (query->next())
    {
        QString text = QString::fromUtf16(u"标题： ") + query->value(1).toString() + "\n\n" + QString(query->value(2).toString()) + "\n\n\n";
        outStream << text;
    }
    outFile.close();
}

void QuestionDlg::showData()
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
    qtnWnd.tableView->setColumnWidth(1, size.width() * 4 / 5 - 275);
    qtnWnd.tableView->setColumnWidth(2, 50);
    qtnWnd.tableView->setColumnWidth(3, 50);
    qtnWnd.tableView->setColumnWidth(4, 50);
    qtnWnd.tableView->setColumnWidth(5, 50);

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
        connect(copyBtn, &QPushButton::clicked, this, &QuestionDlg::copyData);
        qtnWnd.tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 2), copyBtn);


        QPushButton * btn = new QPushButton(QStringLiteral("删除"));
        btn->resize(QSize(5, btn->height()));
        btn->setProperty("row", query->value(0).toString());
        connect(btn, &QPushButton::clicked, this, &QuestionDlg::deleteData);
        qtnWnd.tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 3), btn);

        QPushButton *editBtn = new QPushButton(QStringLiteral("编辑"));
        editBtn->resize(QSize(5, btn->height()));
        editBtn->setProperty("row", query->value(0).toString());
        connect(editBtn, &QPushButton::clicked, this, &QuestionDlg::edit);
        qtnWnd.tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 4), editBtn);

        QPushButton *browseBtn = new QPushButton(QStringLiteral("查看"));
        browseBtn->resize(QSize(5, btn->height()));
        browseBtn->setProperty("row", query->value(0).toString());
        connect(browseBtn, &QPushButton::clicked, this, &QuestionDlg::browse);
        qtnWnd.tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 5), browseBtn);

    }
}

void QuestionDlg::deleteData()
{
    int ret = QMessageBox::question(this, QStringLiteral("警告"), QStringLiteral("是否删除数据！"));
    if (ret == QMessageBox::Yes)
    {
        QPushButton* btn = (QPushButton*)sender();//获取产生事件的对象
        QString sql("delete from question where id=" + btn->property("row").toString());
        query->exec(sql);
        query->exec("select * from question order by id desc");
        showData();
    }
}

void QuestionDlg::browse()
{
    QPushButton *btn = (QPushButton *)sender();
    QString sql("select * from question where id=" + btn->property("row").toString());
    query->exec(sql);
    if (query->next())
    {
        QuestionBrowseDlg boe(this);
        QString title = "<font style='color:red;font-weight:border;font-size:15pt;'>" + query->value(1).toString() + "</font><br/><br/>";
        QString content = query->value(2).toString();
        content.replace("<t1>", "<font style='color:blue;font-size:13pt;'>");
        content.replace("</t1>", "</font>");
        content.replace("<t2>", "<font style='color:blue;font-size:10pt;'>");
        content.replace("</t2>", "</font>");
        content.replace("\n", "<br/>");
        boe.boe.text_content->setText(title + content + "\n\n\n");

        boe.boe.text_content->append(QString::fromUtf16(u"备注：") + query->value(3).toString());
        boe.exec();
    }
}

void QuestionDlg::on_button_search()
{
    QString title = qtnWnd.lineedit_search_string->text().toLower();
    QString sql("select id,title from question");
    query->exec(sql);
    QString strSql("select * from question where");
    bool isHave = false;
    while (query->next())
    {
        QString dbTitle = query->value(1).toString().toLower();

        if (dbTitle.contains(title))
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

void QuestionDlg::on_comboBox_changed()
{
    QString sql("select * from question");
    QString comText = qtnWnd.comboBox_label->currentText();
    if (comText.toLower().compare("all"))
    {
        sql = sql + QString(" where label = '" + comText.trimmed() + "' order by id desc");
    }

    query->exec(sql);

    if (0 != query->size())
    {
        showData();
    }
    else
    {
        QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("未查询到相关记录！"));
    }
}

void QuestionDlg::on_button_empty()
{
    query->exec("select * from question order by id desc");
    showData();
}

void QuestionDlg::copyData()
{
    QPushButton* btn = (QPushButton*)sender();
    QString sql("select content from question where id=" + btn->property("row").toString());
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

void QuestionDlg::edit()
{
    QPushButton *btn = (QPushButton*)sender();
    editSerial.clear();
    editSerial.append(btn->property("row").toString());
    QString sql("select * from question where id=" + editSerial);
    query->exec(sql);
    if (query->next())
    {
        pQSW->pNWnd.save->setEnabled(false);
        pQSW->pNWnd.btn_modify->setEnabled(true);
        pQSW->pNWnd.lineEdit->setText(query->value(1).toString());
        pQSW->pNWnd.textEdit->setText(query->value(2).toString());
        pQSW->pNWnd.comboBox_label->setCurrentText(query->value(3).toString());
        pQSW->show();
    }
}


void QuestionDlg::resizeEvent(QResizeEvent * event)
{
    QSize tableSize = qtnWnd.tableView->size();
    qtnWnd.tableView->setColumnWidth(0, tableSize.width() / 4);
    qtnWnd.tableView->setColumnWidth(1, tableSize.width() * 3 / 4 - 275);
}

bool QuestionDlg::closeDb()
{
    if (isDbOpen)
    {
        db.close();
        isDbOpen = false;
    }
    return true;
}

bool QuestionDlg::openDb()
{
    if (!isDbOpen)
    {
        linkDb();
        QString sql("select * from question order by id desc");
        query->exec(sql);
        showData();
        isDbOpen = true;
    }
    return isDbOpen;
}
