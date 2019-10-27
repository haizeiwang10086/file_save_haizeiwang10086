#include "opencvshowwindow.h"
#include <QPushButton>



OpencvShowWindow::OpencvShowWindow(QWidget *parent)
{
    img.load("E:/workspace/1/1_0_Z.tif");
    ImageGraphic=new QGraphicsView();
    QPixmap ConvertPixmap = QPixmap::fromImage(img);//The QPixmap class is an off-screen image representation that can be used as a paint device
    qgraphicsScene = new QGraphicsScene;//要用QGraphicsView就必须要有QGraphicsScene搭配着用
    m_Image = new ImageWidget(&ConvertPixmap);//实例化类ImageWidget的对象m_Image，该类继承自QGraphicsItem，是自己写的类
    int nwith = ImageGraphic->width();//获取界面控件Graphics View的宽度
    int nheight = ImageGraphic->height();//获取界面控件Graphics View的高度
    m_Image->setQGraphicsViewWH(nwith-50, nheight);//将界面控件Graphics View的width和height传进类m_Image中
    qgraphicsScene->addItem(m_Image);//将QGraphicsItem类对象放进QGraphicsScene中
    qgraphicsScene->setSceneRect(QRect(0,0,nwith-50,nheight));
    ImageGraphic->setSceneRect(QRectF(-((nwith - 50) / 2), -(nheight / 2), (nwith - 50), nheight));//使视窗的大小固定在原始大小，不会随图片的放大而放大（默认状态下图片放大的时候视窗两边会自动出现滚动条，并且视窗内的视野会变大），防止图片放大后重新缩小的时候视窗太大而不方便观察图片
    ImageGraphic->setScene(qgraphicsScene);//Sets the current scene to scene. If scene is already being viewed, this function does nothing.
    ImageGraphic->setFocus();//将界面的焦点设置到当前Graphics View控件
    ImageGraphic->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ImageGraphic->move(100,0);

    ImageGraphic->setParent(this);
    stanItemModel = new MItemModel();
    tableView = new QTableView(this);
    tableView->setModel(stanItemModel);
    tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background:rgb(51, 153, 255);color: black; \
                                                            font-weight: bold;padding-left: 4px;border: 1px solid #6c6c6c;}");

    tableView->move(0, 0);
    tableView->resize(100, nheight);

}

bool OpencvShowWindow::addImage(QString name,Mat &mat)
{
    QImage rgb;
    if (mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)  
        image.setColorCount(256);
        for (int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat  
        uchar *pSrc = mat.data;
        for (int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        rgb = image.copy();
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3  
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat  
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat  
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        rgb= image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        qDebug() << "CV_8UC4";
        // Copy input Mat  
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat  
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        rgb = image.copy();
    }
    else 
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
    }
        
    imgs.insert(pair<QString,QImage>(name, rgb));
    return true;
}

void OpencvShowWindow::flush()
{
    stanItemModel->clear();
    stanItemModel->setColumnCount(6);
    stanItemModel->setHeaderData(0, Qt::Horizontal, QStringLiteral("变量"));
    QSize size = tableView->size();
    tableView->setColumnWidth(0, size.width());
    
    for (map<QString, QImage>::iterator it = imgs.begin(); it != imgs.end(); it++)
    {
        QPushButton *newVariant = new QPushButton((it->first).toUtf8());
        //newVariant->resize(QSize(5, newVariant->height()));
        newVariant->setProperty("varName", (it->first).toUtf8());
        connect(newVariant, &QPushButton::clicked, this, &OpencvShowWindow::imageDisp);
        tableView->setIndexWidget(stanItemModel->index(stanItemModel->rowCount() - 1, 0), newVariant);
    }

}

void OpencvShowWindow::imageDisp()
{
    qgraphicsScene->clear();
    map<QString, QImage>::iterator it = imgs.find("test");
    QImage image = it->second;
    QPixmap ConvertPixmap = QPixmap::fromImage(image);//The QPixmap class is an off-screen image representation that can be used as a paint device
    m_Image = new ImageWidget(&ConvertPixmap);//实例化类ImageWidget的对象m_Image，该类继承自QGraphicsItem，是自己写的类
    int nwith = ImageGraphic->width();//获取界面控件Graphics View的宽度
    int nheight = ImageGraphic->height();//获取界面控件Graphics View的高度
    m_Image->setQGraphicsViewWH(nwith, nheight);
    qgraphicsScene->addItem(m_Image);
}
WndManager::WndManager()
{
    int argc = 1;
    char arg[] = { 's' };
    char *argv[] = { arg };
    
    app = new QApplication(argc, argv);
    wnd = new OpencvShowWindow;
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


int Ui::image_show()
{
    
    return 1;
}

void Ui::addImage(Mat& image)
{
    manager->wnd->addImage("test", image);
}

void Ui::window_show()
{
    manager->openWnd();
}



