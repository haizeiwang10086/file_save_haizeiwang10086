#include "QtNewWindow.h"

QtNewWindow::QtNewWindow(QWidget *parent)
{
    pNWnd.setupUi(this);
    connect(pNWnd.save, &QPushButton::clicked, this, &QtNewWindow::dealSave);
    connect(pNWnd.btn_modify, &QPushButton::clicked, this, &QtNewWindow::dealModify);

}

void QtNewWindow::dealSave()
{
    QString title = pNWnd.lineEdit->text();
    QString content = pNWnd.textEdit->toPlainText();
    QString remarks = pNWnd.textEdit_remarks->toPlainText();
    pNWnd.lineEdit->clear();
    pNWnd.textEdit->clear();
    pNWnd.textEdit_remarks->clear();
    emit saveSignal(title, content, remarks);
    close();
}

void QtNewWindow::dealModify()
{
    QString title = pNWnd.lineEdit->text();
    QString content = pNWnd.textEdit->toPlainText();
    QString remarks = pNWnd.textEdit_remarks->toPlainText();
    
    pNWnd.lineEdit->clear();
    pNWnd.textEdit->clear();
    pNWnd.textEdit_remarks->clear();
    emit modifySignal(title, content, remarks);
    close();
}