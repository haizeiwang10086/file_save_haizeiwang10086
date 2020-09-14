#include "BatchEditName.h"
#include "Utils.h"
#include <QToolButton>
#include <qfiledialog.h>
#include <qdir.h>
#include <qlist.h>
#include <opencv2/opencv.hpp>
#include <QMessageBox>

using namespace cv;
using namespace std;
BatchEditName::BatchEditName(QWidget *parent)
{
    editWidget.setupUi(this);
    editWidget.Directory->setText("E:/images");
    editWidget.le_NameFormat->setText("demo_*.png");
    editWidget.cbImageFormatList->addItems(QStringList({"bmp","jpg","png"}));
    connect(editWidget.toolButton, &QToolButton::clicked, this, &BatchEditName::searchDirectoryDlg);
    connect(editWidget.BtnModify, &QPushButton::clicked, this, &BatchEditName::modifyFilesName);
    connect(editWidget.btnImageDirectory, &QToolButton::clicked, this, &BatchEditName::selectImagePath);
    connect(editWidget.btnCvtFormat, &QPushButton::clicked, this, &BatchEditName::cvtImageFormat);
}

void BatchEditName::searchDirectoryDlg()
{
    editWidget.Directory->setText(selectPath());

}

void BatchEditName::modifyFilesName()
{
    QString dirPath=editWidget.Directory->text();
    QString nameModel = editWidget.le_NameFormat->text();
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
        QString fileNewPath = dirPath + "/" + nameModel;
        fileNewPath.replace("*", strNum);
        
        bool isSuccess=QFile::rename(filePath, fileNewPath);
        list.append(fileNewPath);
        nameI++;
    }
    
}

void BatchEditName::selectImagePath()
{
     editWidget.leImageDirectory->setText(selectPath());
}

QString BatchEditName::selectPath()
{
    QFileDialog *fileDlg = new QFileDialog(this);
    fileDlg->setDirectory("D:/");
    fileDlg->setFileMode(QFileDialog::Directory);
    QString dirPath;
    return fileDlg->getExistingDirectory();
}

void BatchEditName::cvtImageFormat()
{
    QString path = editWidget.leImageDirectory->text();

    if (path.isEmpty())
    {
        QMessageBox::warning(this, QString::fromUtf16(u"警告"), QString::fromUtf16(u"路径不能为空"));
        return;
    }
    vector<String> imagesPath;

    vector<String> tmpPath;
    QString tmpFilePath = path + "/*.bmp";
    glob(tmpFilePath.toLatin1().data(), tmpPath);
    imagesPath.insert(imagesPath.end(), tmpPath.begin(), tmpPath.end());

    tmpFilePath = path + "/*.jpg";
    glob(tmpFilePath.toLatin1().data(), tmpPath);
    imagesPath.insert(imagesPath.end(), tmpPath.begin(), tmpPath.end());

    tmpFilePath = path + "/*.png";
    glob(tmpFilePath.toLatin1().data(), tmpPath);
    imagesPath.insert(imagesPath.end(), tmpPath.begin(), tmpPath.end());

    for (int i = 0; i < imagesPath.size(); i++)
    {
        String imagePath = imagesPath[i];
        Mat image = imread(imagePath, IMREAD_UNCHANGED);
        QString bsName = baseName(imagePath.c_str());
        QStringList names = bsName.split(".");
        QString ext = editWidget.cbImageFormatList->currentText().trimmed();
        QString newPath = path + "/" + names[0] + "." + ext;
        imwrite(newPath.toLatin1().data(),image);
    }

}