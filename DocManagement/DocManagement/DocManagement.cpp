#include "DocManagement.h"
#include "qfiledialog.h"
#include "qaction.h"
#include "windows.h"
#include "tchar.h"
#include <QMessageBox>
#include <qdebug.h>
#include "CustomTabStyle.h"

DocManagement::DocManagement(QWidget *parent)
    : QMainWindow(parent)
{

    ui.setupUi(this);
    setWindowTitle(QString::fromUtf16(u"管理工具"));
    QIcon icon;
    icon.addFile(":/image/myapp.ico");
    setWindowIcon(icon);
    /*MTabWidget * tabWidget = new MTabWidget(this);
    tabWidget->show();*/
    ui.tabWidget->tabBar()->setStyle(new CustomTabStyle);

    HINSTANCE hDllQuest = LoadLibrary(_T("QtQuestWindow.dll"));
    HINSTANCE hDllSech = LoadLibrary(_T("QtSearchWindow.dll"));
    HINSTANCE hDllImgWnd = LoadLibrary(_T("ImageToolWindow.dll"));
    if (NULL == hDllQuest || NULL == hDllSech || NULL==hDllImgWnd)
    {
        QMessageBox::warning(this, "警告", "动态库加载失败！");
    }
    pImgToolWnd = (ImageToolWindow)GetProcAddress(hDllImgWnd, "createImageToolWindow");
    pQuestWindow = (QuestionWindow)GetProcAddress(hDllQuest, "createQuestionWindow");
    pSechWindow = (SechWindow)GetProcAddress(hDllSech, "createSearchWindow");
    pFreeSechWND = (FreeSechWindow)GetProcAddress(hDllSech, "freeSearchWindow");
    pFreeImgWnd = (freeImageToolWindow)GetProcAddress(hDllImgWnd, "freeImageToolWindow");
    if(NULL== pQuestWindow || NULL == pSechWindow || NULL == pImgToolWnd)
    {
        QMessageBox::warning(this, "警告", "动态库内部函数调用失败！");
    }

    //btnSign.setParent(this);
    QToolBar *pQtr = addToolBar("tool bar");
    QAction  *pQatAdd = pQtr->addAction("添加");
	QAction *pLinkDb = pQtr->addAction("链接数据库");
    //pLinkDb->setIcon(QIcon("myapp.ico"));
    connect(pQatAdd,&QAction::triggered,
        [=]() mutable
        {
            QString fileName = QFileDialog::getOpenFileName(this, "添加", "../", "doc(*.txt *.doc *.docx);;all(*.*)");
            QStringList nameList=fileName.split("/");
            //ui.fileNameLists->setText(nameList[nameList.size()-1]);
            
            if (fileName.endsWith(".docx") || fileName.endsWith(".doc"))
            {
                    //officeContent = new QAxWidget("Word.Document", ui.docDisp);
                    officeContent = new QAxWidget("Word.Application", docDisp.DDC.textEdit);
                    int width= docDisp.DDC.textEdit->width();
                    int height= docDisp.DDC.textEdit->height();
                    QRect rect= docDisp.DDC.textEdit->rect();
                    officeContent->setGeometry(QRect(20,20,width-20,height-20));
                    officeContent->setControl(fileName);
                    officeContent->show();

 
            }
        });
       
	connect(pLinkDb,&QAction::triggered,
		[=]()
		{
			dbDlg.readConfig();
			dbDlg.exec();
		});
	void (DataBaseLinkDialog::*linkSignal)(QString dbName, QString userName, QString password) = &DataBaseLinkDialog::dataBaseLinkSignal;
	connect(&dbDlg, linkSignal, this, &DocManagement::linkDb);
    ui.tabWidget->addTab(&docDisp, QString::fromUtf16(u"主窗口"));
    ui.tabWidget->removeTab(0);
    ui.tabWidget->addTab(&batEditWnd, QString::fromUtf16(u"批量改名"));
    questWnd = pQuestWindow(this);
    ui.tabWidget->addTab(questWnd, QString::fromUtf16(u"问题查询"));
    sechWnd = pSechWindow(this);
    ui.tabWidget->addTab(sechWnd, QString::fromUtf16(u"信息查询"));
    imgToolWnd = pImgToolWnd(this);
    ui.tabWidget->addTab(imgToolWnd, QString::fromUtf16(u"图像工具"));
    connect(ui.tabWidget, &QTabWidget::currentChanged, this, &DocManagement::dealTabClick);

    resize(1000, 600);
    setAcceptDrops(true);
}


void DocManagement::linkDb(QString dbName, QString userName, QString password)
{
	QString desc;
	bool isInit=sechWnd->dbInit(dbName, userName, password, desc);
	if (isInit)
	{
		QMessageBox::about(this, QStringLiteral("消息"), desc);
	}
	else
	{
		QMessageBox::warning(this, QStringLiteral("消息"), desc);
	}
}

void DocManagement::resizeEvent(QResizeEvent * event)
{
    QSize size = this->size();
    ui.tabWidget->resize(size.width() - 20, size.height() - 20);
    ui.tabWidget->move(10, 10);
    QSize twSize = ui.tabWidget->size();
    sechWnd->resize(twSize.width()-40, twSize.height()-20);
    questWnd->resize(twSize.width() - 40, twSize.height()-20);
    docDisp.resize(twSize.width() - 40, twSize.height()-20);
    batEditWnd.resize(twSize.width() - 40, twSize.height() - 20);
    imgToolWnd->resize(twSize.width()-80, twSize.height() - 20);
}

void DocManagement::dealTabClick(int idex)
{
    if (idex == 2)
    {
        sechWnd->closeDb();
        questWnd->openDb();
    }
    if (idex == 3)
    {
        questWnd->closeDb();
        sechWnd->openDb();
    }
}
