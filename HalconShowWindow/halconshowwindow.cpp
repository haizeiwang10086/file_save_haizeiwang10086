#include "halconshowwindow.h"

#include <QPushButton>



HalconShowWindow::HalconShowWindow(QWidget *parent)
{
    ImageGraphic=new MGraphicsView();
    QPixmap ConvertPixmap = QPixmap::fromImage(img);//The QPixmap class is an off-screen image representation that can be used as a paint device
    qgraphicsScene = new QGraphicsScene;//要用QGraphicsView就必须要有QGraphicsScene搭配着用
    m_Image = new ImageWidget(&ConvertPixmap);//实例化类ImageWidget的对象m_Image，该类继承自QGraphicsItem，是自己写的类
	qgraphicsScene->addItem(m_Image);//将QGraphicsItem类对象放进QGraphicsScene中
    
    ImageGraphic->setParent(this);
    stanItemModel = new MItemModel();
    tableView = new QTableView(this);
    tableView->setModel(stanItemModel);
    tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background:rgb(51, 153, 255);color: black; \
                                                            font-weight: bold;padding-left: 4px;border: 1px solid #6c6c6c;}");

    

}

bool HalconShowWindow::image_show(QString name, HObject &mat)
{
    imgs.insert(pair<QString, HObject>(name, mat));
    return true;
}

void HalconShowWindow::hobj2QImage(HObject img,QImage& rgb)
{
    
    HTuple hv_Width,hv_Height,hv_Channels,hv_Types;
    CountChannels(img, &hv_Channels);
    GetImageType(img, &hv_Types);
	GetImageSize(img, &hv_Width, &hv_Height);
    if (1 == hv_Channels)
    {
        if (!strcmp(hv_Types[0].S(), "byte"))
        {
            rgb = QImage(hv_Width.I(), hv_Height.I(), QImage::Format_Grayscale8);
            rgb.setColorCount(256);
            for (int i = 0; i < 256; i++)
            {
                rgb.setColor(i, qRgb(i, i, i));
            }
            HTuple  hv_Pointer, hs_Types;
            GetImagePointer1(img, &hv_Pointer, NULL, NULL, NULL);
            uchar *pSrc = reinterpret_cast<uchar *>(hv_Pointer[0].L());
			int width = hv_Width.I();
			int height = hv_Height.I();
			for (int i = 0; i < height; i++)
			{
				uchar *pDest = rgb.scanLine(i);
				memcpy(pDest, pSrc, width);
				pSrc += width;
			}
        }
        else
        {
            return;
        }
    }
	else if (3 == hv_Channels)
	{
		HTuple  hv_R, hv_G, hv_B;
		int width = hv_Width.I();
		rgb = QImage(width, hv_Height.I(), QImage::Format_RGB888);
		
		GetImagePointer3(img, &hv_R, &hv_G, &hv_B, NULL, NULL, NULL);
		rgb = QImage(width, hv_Height.I(), QImage::Format_RGB888);
		uchar *pR = reinterpret_cast<uchar *>(hv_R[0].L());
		uchar *pG = reinterpret_cast<uchar *>(hv_G[0].L());
		uchar *pB = reinterpret_cast<uchar *>(hv_B[0].L());
		for (int i = 0; i<hv_Height.I(); i++)
		{
			uchar *pDest = rgb.scanLine(i);
			for (int j = 0; j<width; j++)
			{
				pDest[j * 3] = pR[i*width + j];
				pDest[j * 3 + 1] = pG[i*width + j];
				pDest[j * 3 + 2] = pB[i*width + j];
			}
		}
	}
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
        connect(newVariant, &QPushButton::clicked, this, &HalconShowWindow::imageDisp);
        tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 0), newVariant);
		tableView->setRowHeight(stanItemModel->rowCount() - 1, 25);
    }

}

void HalconShowWindow::imageDisp()
{
	QPushButton *btn = (QPushButton *)sender();
    qgraphicsScene->clear();
    map<QString, HObject>::iterator it = imgs.find(btn->property("varName").toString());
    HObject image = it->second;
    QImage qImg;
    hobj2QImage(image, qImg);
    QPixmap ConvertPixmap = QPixmap::fromImage(qImg);//The QPixmap class is an off-screen image representation that can be used as a paint device
    m_Image = new ImageWidget(&ConvertPixmap);//实例化类ImageWidget的对象m_Image，该类继承自QGraphicsItem，是自己写的类
    int nwith = ImageGraphic->width();//获取界面控件Graphics View的宽度
    int nheight = ImageGraphic->height();//获取界面控件Graphics View的高度
    m_Image->setQGraphicsViewWH(nwith, nheight);
    qgraphicsScene->addItem(m_Image);
    ImageGraphic->setShowImage(image);
}

void HalconShowWindow::resizeEvent(QResizeEvent * event)
{
	int nwith = this->size().width();
	int nheight = this->size().height();
	m_Image->setQGraphicsViewWH(nwith - 50, nheight);//将界面控件Graphics View的width和height传进类m_Image中
	ImageGraphic->resize(nwith - 50, nheight);
	qgraphicsScene->setSceneRect(QRect(0, 0, nwith - 50, nheight));
	
	ImageGraphic->setSceneRect(QRectF(-((nwith - 50) / 2), -(nheight / 2), (nwith - 50), nheight));//使视窗的大小固定在原始大小，不会随图片的放大而放大（默认状态下图片放大的时候视窗两边会自动出现滚动条，并且视窗内的视野会变大），防止图片放大后重新缩小的时候视窗太大而不方便观察图片
	ImageGraphic->setScene(qgraphicsScene);//Sets the current scene to scene. If scene is already being viewed, this function does nothing.
	ImageGraphic->setFocus();//将界面的焦点设置到当前Graphics View控件
	ImageGraphic->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ImageGraphic->move(100, 0);

	tableView->move(0, 0);
	tableView->resize(100, nheight);
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

void Ui::wait_key()
{
	manager->wnd->flush();
    manager->openWnd();
}



