#include "ExportDlg.h"
#include <QFileDialog>
#include <QMessageBox>

ExportDlg::ExportDlg(QWidget *parent)
{
    ui_extDlg.setupUi(this);
    connect(ui_extDlg.btn_filePath, &QToolButton::clicked, this, &ExportDlg::getPath);
    connect(ui_extDlg.comboBox, &QComboBox::currentTextChanged, this, &ExportDlg::onComboBoxChanged);
    connect(ui_extDlg.okButton, &QPushButton::clicked, this, &ExportDlg::dealSave);
}

void ExportDlg::setType(QStringList label)
{
    ui_extDlg.comboBox->clear();
    ui_extDlg.comboBox->addItems(label);
}

void ExportDlg::getPath()
{
    QString path = QFileDialog::getExistingDirectory(this, QString::fromUtf16(u"保存"), "../");
    ui_extDlg.lineEdit->setText(path + "/" + ui_extDlg.comboBox->currentText() + ".txt");
}

void ExportDlg::onComboBoxChanged()
{
    if (ui_extDlg.comboBox->currentText().trimmed().isEmpty() || !ui_extDlg.comboBox->currentText().trimmed().compare("all"))
    {
        return;
    }
    QString filePath1 = ui_extDlg.lineEdit->text();
    QStringList nList = filePath1.split("/");
    nList.pop_back();

    QString filePath;
    for (int i = 0; i < nList.size(); i++)
    {
        filePath.append(nList.at(i)).append("/");
    }
    filePath.append(ui_extDlg.comboBox->currentText() + ".txt");
    ui_extDlg.lineEdit->setText(filePath);
}

void ExportDlg::dealSave()
{
    if (!ui_extDlg.comboBox->currentText().trimmed().compare("all"))
    {
        QMessageBox::warning(this, QString::fromUtf16(u"警告"), QString::fromUtf16(u"请选择标签类型！"));
        return;
    }
    QStringList mList = ui_extDlg.lineEdit->text().split("/");
    if (ui_extDlg.lineEdit->text().isEmpty() || mList.size() == 1)
    {
        QMessageBox::warning(this, QString::fromUtf16(u"警告"), QString::fromUtf16(u"请选择保存路径！"));
        return;
    }

    QString filePath = ui_extDlg.lineEdit->text();
    QStringList info;
    info.push_back(filePath);
    info.push_back(ui_extDlg.comboBox->currentText().trimmed());
    emit saveSignal(info);
    close();
}
