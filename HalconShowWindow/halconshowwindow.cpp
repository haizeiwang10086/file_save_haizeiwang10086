#include "halconshowwindow.h"
#include <typeinfo.h>
#include <QPushButton>



HalconShowWindow::HalconShowWindow(QWidget *parent)
{
    resize(QSize(800, 500));
    m_OutWnd = new ImageWindowWidget(this);
    stanItemModel = new QStandardItemModel();
    tableView = new QTableView(this);
    tableView->setModel(stanItemModel);
    tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background:rgb(51, 153, 255);color: black; \
                                                            font-weight: bold;padding-left: 4px;border: 1px solid #6c6c6c;}");
}

bool HalconShowWindow::image_show(QString name, HObject &hobj)
{
    imgs.insert(pair<QString, HObject>(name, hobj));
    return true;
}

bool HalconShowWindow::tuple_show(char* name, HalconCpp::HTuple& tuple)
{
    arrays.insert(pair<QString, HTuple>(name, tuple));
    return true;
}



void HalconShowWindow::flush()
{
    stanItemModel->clear();
    stanItemModel->setColumnCount(1);
    stanItemModel->setHeaderData(0, Qt::Horizontal, QStringLiteral("var"));
    QSize size = tableView->size();
    tableView->setColumnWidth(0, size.width());
	
    for (map<QString, HObject>::iterator it = imgs.begin(); it != imgs.end(); it++)
    {
		QList<QStandardItem*> newRow;
		stanItemModel->appendRow(newRow);
        QPushButton *newVariant = new QPushButton((it->first).toUtf8());
		newVariant->setStyleSheet("background: rgb(255,255,255)");
        //newVariant->resize(QSize(5, newVariant->height()));
        newVariant->setProperty("varName", (it->first).toUtf8());
        newVariant->setProperty("varType", "hobject");
        connect(newVariant, &QPushButton::clicked, this, &HalconShowWindow::disp);
        tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 0), newVariant);
		tableView->setRowHeight(stanItemModel->rowCount() - 1, 25);
    }

    for (map<QString, HTuple>::iterator it = arrays.begin(); it != arrays.end();it++)
    {
        QList<QStandardItem*> newRow;
        stanItemModel->appendRow(newRow);
        QPushButton *newVariant = new QPushButton((it->first).toUtf8());
        newVariant->setStyleSheet("QPushButton{background-color:green}");
        newVariant->setProperty("varName", (it->first).toUtf8());
        newVariant->setProperty("varType", "tuple");
        connect(newVariant, &QPushButton::clicked, this, &HalconShowWindow::disp);
        tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 0), newVariant);
        tableView->setRowHeight(stanItemModel->rowCount() - 1, 25);
    }

}

void HalconShowWindow::disp()
{

	QPushButton *btn = (QPushButton *)sender();
    QString type = btn->property("varType").toString();
    if (!type.compare("hobject"))
    {
        map<QString, HObject>::iterator it = imgs.find(btn->property("varName").toString());
        HObject image = it->second;
        m_OutWnd->tableWidget->hide();
        m_OutWnd->img_wnd->show();
        m_OutWnd->img_wnd->setShowImage(image);
    }
    else if (!type.compare("tuple"))
    {
        map<QString, HTuple>::iterator it = arrays.find(btn->property("varName").toString());
        HTuple tuple = it->second;
        m_OutWnd->img_wnd->hide();
        m_OutWnd->tableWidget->show();
        m_OutWnd->setShowHTuple(tuple);
    }
    
}

void HalconShowWindow::resizeEvent(QResizeEvent * event)
{
	int nwith = this->size().width();
	int nheight = this->size().height();
	tableView->move(0, 0);
	tableView->resize(100, nheight);
    m_OutWnd->move(110, 0);
    m_OutWnd->resize(nwith - 110, nheight);
}


WndManager::WndManager()
{
    int argc = 1;
    char arg[] = { 's' };
    char *argv[] = { arg };
    
    app = new QApplication(argc, argv);
    wnd = new HalconShowWindow;
	
}

void WndManager::openWnd()
{
    wnd->show();
    app->exec();
   
}

void WndManager::setWndName(QString name)
{
    wnd->setWindowTitle(name);
}


//using namespace InnerUi;

using namespace InnerUi;

void Ui::named_window(char* name)
{
    if (manager == NULL)
    {
        manager = new WndManager;
        manager->setWndName(name);
    }
}


void Ui::image_show(char* name, HObject& image)
{
    manager->wnd->image_show(name, image);
}

void Ui::tuple_show(char* name, HalconCpp::HTuple& tuple)
{

    manager->wnd->tuple_show(name, tuple);
}

void Ui::wait_key()
{
	manager->wnd->flush();
    manager->openWnd();
}



