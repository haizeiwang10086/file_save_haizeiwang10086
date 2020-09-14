#include "NewDlg.h"
#include <QFileDialog>

NewDlg::NewDlg(QWidget *parent)
{
    ui_NewDlg.setupUi(this);
    connect(ui_NewDlg.selectButton, &QToolButton::clicked, this, &NewDlg::addFile);
    connect(ui_NewDlg.save, &QPushButton::clicked, this, &NewDlg::dealUpload);
}

void NewDlg::addFile()
{
    path = QFileDialog::getOpenFileName(this, QString::fromUtf16(u"Ñ¡ÔñÎÄ¼þ"), "D:/", tr("Image(*.jpg *.png *.bmp *.jpeg);;Source(*.cpp *.h);;Text(*.txt);;Doc(*.doc);;all(*.*)"));
    QStringList paths = path.split("/");
    ui_NewDlg.lineEdit->setText(paths[paths.size() - 1]);
}

void NewDlg::dealUpload()
{
    emit upload(path,ui_NewDlg.teRemarks->toPlainText());
    ui_NewDlg.lineEdit->clear();
	ui_NewDlg.teRemarks->clear();
    close();

}
