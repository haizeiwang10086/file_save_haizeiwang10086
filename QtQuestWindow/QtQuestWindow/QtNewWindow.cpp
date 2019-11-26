#include "QtNewWindow.h"
#include "qfile.h"
#include "qmessagebox.h"
#include "qdebug.h"
#include "qfileinfo.h"
#include <map>
#include <QIcon>

QtNewWindow::QtNewWindow(QWidget *parent)
{
    pNWnd.setupUi(this);
	QIcon icon;
	icon.addFile(":/images/new.ico");
	setWindowIcon(icon);
    connect(pNWnd.save, &QPushButton::clicked, this, &QtNewWindow::dealSave);
    connect(pNWnd.btn_modify, &QPushButton::clicked, this, &QtNewWindow::dealModify);
    QFile file("./config/config.ini");
    if (file.open(QIODevice::ReadOnly))
    {
        std::map<QString, QString> mConf;
        while (!file.atEnd())
        {
            QString str(file.readLine());
            QStringList strList = str.split("=");
            if (strList.size() == 2)
            {
                mConf.insert(std::pair<QString, QString>(strList[0], strList[1]));
            }
            else
            {
                QMessageBox::warning(this, QStringLiteral("æØ∏Ê"), QStringLiteral("≈‰÷√Œƒµµ”–ŒÛ£°"));
            }
           
        }
        std::map<QString, QString>::iterator iter;
        if ((iter = mConf.find("label")) != mConf.end())
        {
            QStringList label = iter->second.split(";");
            label.last().replace("\n", "");
            pNWnd.comboBox_label->addItems(label);
        }
        else
        {
            QMessageBox::warning(this, QStringLiteral("æØ∏Ê"), QStringLiteral("±Í«©º”‘ÿ ß∞‹«ÎºÏ≤È≈‰÷√Œƒµµ£°"));
        }
    }
    else
    {
        QMessageBox::warning(this, QStringLiteral("æØ∏Ê"), QStringLiteral("≈‰÷√Œƒµµ∂¡»° ß∞‹£°"));
    }

    resize(800, 500);
}

void QtNewWindow::dealSave()
{
    QString title = pNWnd.lineEdit->text();
    QString content = pNWnd.textEdit->toPlainText();
    QString label = pNWnd.comboBox_label->currentText();
    pNWnd.lineEdit->clear();
    pNWnd.textEdit->clear();
    emit saveSignal(title, content, label);
    close();
}

void QtNewWindow::dealModify()
{
    QString title = pNWnd.lineEdit->text();
    QString content = pNWnd.textEdit->toPlainText();
    QString label = pNWnd.comboBox_label->currentText();
    
    pNWnd.lineEdit->clear();
    pNWnd.textEdit->clear();
    emit modifySignal(title, content, label);
    close();
}

void QtNewWindow::resizeEvent(QResizeEvent * event)
{
    QSize size = this->size();
    pNWnd.title->move(size.width() / 10, size.height() / 10);
    pNWnd.content->move(size.width() / 10, size.height() / 10 + 30);
    pNWnd.lineEdit->move(size.width() / 10 + 40, size.height() / 10);
    pNWnd.lineEdit->resize(size.width() * 9 / 10 - 100, 25);
    pNWnd.textEdit->move(size.width() / 10 + 40, size.height() / 10 + 30);
    pNWnd.textEdit->resize(size.width() * 9 / 10 - 100, size.height()*9/10-100);
    pNWnd.save->move(size.width() / 2 - 100, size.height() - 50);
    pNWnd.btn_modify->move(size.width() / 2 - 20, size.height() - 50);
    pNWnd.comboBox_label->move(size.width() / 2 + 65, size.height() - 50);
    QSize btnSize = pNWnd.save->size();
    pNWnd.comboBox_label->resize(btnSize);

}