#include "BatchEditName.h"
#include <QToolButton>
#include <qfiledialog.h>
#include <qdir.h>
#include <qlist.h>
BatchEditName::BatchEditName(QWidget *parent)
{
    editWidget.setupUi(this);

    connect(editWidget.toolButton, &QToolButton::clicked, this, &BatchEditName::searchDirectoryDlg);
    connect(editWidget.BtnModify, &QPushButton::clicked, this, &BatchEditName::modifyFilesName);
}

void BatchEditName::searchDirectoryDlg()
{
    QFileDialog *fileDlg=new QFileDialog(this);
    fileDlg->setDirectory("D:/");
    fileDlg->setFileMode(QFileDialog::Directory);
    QString dirPath;
    dirPath = fileDlg->getExistingDirectory();
    
    editWidget.Directory->setText(dirPath);

}

void BatchEditName::modifyFilesName()
{
    QString dirPath=editWidget.Directory->text();
    QString preName = editWidget.lineEditPre->text();
    QString sufName = editWidget.lineEditSuf->text();
    QString devName = editWidget.lineEditDevName->text();
    QDir dir(dirPath);
    if (!dir.exists())return;
    int nameI = 0;
    QList<QString> list;
    for (int i = 0; i < dir.count(); i++)
    {
        QString fileName = dir[i];
        if (!fileName.compare("."))continue;
        if (!fileName.compare(".."))continue;
       
        QString filePath = dirPath +"/"+ fileName;
        QString strNum = QString::number(nameI,10);
        QString fileNewPath = dirPath + "/" + preName + "_" + strNum + "_" + sufName + devName;
        bool isSuccess=QFile::rename(filePath, fileNewPath);
        list.append(fileNewPath);
        nameI++;
    }
    
}