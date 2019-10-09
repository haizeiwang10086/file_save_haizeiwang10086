#include "QtNewWindow.h"
#include "qfile.h"
#include "qmessagebox.h"
#include <map>

QtNewWindow::QtNewWindow(QWidget *parent)
{
    pNWnd.setupUi(this);
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
            std::map<QString, QString>::iterator iter;
            if ((iter = mConf.find("label")) != mConf.end())
            {
                QStringList label = iter->second.split(";");
                pNWnd.comboBox_label->addItems(label);
            }
            else
            {
                QMessageBox::warning(this, QStringLiteral("æØ∏Ê"), QStringLiteral("±Í«©º”‘ÿ ß∞‹«ÎºÏ≤È≈‰÷√Œƒµµ£°"));
            }
        }

    }
    else
    {
        QMessageBox::warning(this, QStringLiteral("æØ∏Ê"), QStringLiteral("≈‰÷√Œƒµµ∂¡»° ß∞‹£°"));
    }

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