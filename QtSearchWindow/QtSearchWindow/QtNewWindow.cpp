#include "QtNewWindow.h"

QtNewWindow::QtNewWindow(QWidget *parent)
{
    pNWnd.setupUi(this);
    connect(pNWnd.save, &QPushButton::clicked, this, &QtNewWindow::dealSave);

}

void QtNewWindow::dealSave()
{
    QString title = pNWnd.lineEdit->text();
    QString content = pNWnd.textEdit->toPlainText();
    pNWnd.lineEdit->clear();
    pNWnd.textEdit->clear();
    emit saveSignal(title, content);
    close();
}