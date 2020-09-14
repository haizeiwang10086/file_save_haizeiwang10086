#include "QuestionNewDlg.h"
#include "qfile.h"
#include "qmessagebox.h"
#include "qdebug.h"
#include "qfileinfo.h"
#include <map>
#include <QIcon>

QuestionNewDlg::QuestionNewDlg(QWidget *parent)
{
    pNWnd.setupUi(this);
    QIcon icon;
    icon.addFile(":/images/new.ico");
    setWindowIcon(icon);
    connect(pNWnd.save, &QPushButton::clicked, this, &QuestionNewDlg::dealSave);
    connect(pNWnd.btn_modify, &QPushButton::clicked, this, &QuestionNewDlg::dealModify);
    connect(pNWnd.btnT1, &QPushButton::clicked, this, &QuestionNewDlg::setT1);
    connect(pNWnd.btnT2, &QPushButton::clicked, this, &QuestionNewDlg::setT2);
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

void QuestionNewDlg::dealSave()
{
    QString title = pNWnd.lineEdit->text();
    QString content = pNWnd.textEdit->toPlainText();
    QString label = pNWnd.comboBox_label->currentText();
    pNWnd.lineEdit->clear();
    pNWnd.textEdit->clear();
    emit saveSignal(title, content, label);
    close();
}

void QuestionNewDlg::dealModify()
{
    QString title = pNWnd.lineEdit->text();
    QString content = pNWnd.textEdit->toPlainText();
    QString label = pNWnd.comboBox_label->currentText();

    pNWnd.lineEdit->clear();
    pNWnd.textEdit->clear();
    emit modifySignal(title, content, label);
    close();
}

void QuestionNewDlg::setT1()
{
    QString select = pNWnd.textEdit->textCursor().selectedText();
    pNWnd.textEdit->textCursor().insertText("<t1>" + select + "</t1>");
}

void QuestionNewDlg::setT2()
{
    QString select = pNWnd.textEdit->textCursor().selectedText();
    pNWnd.textEdit->textCursor().insertText("<t2>" + select + "</t2>");
}