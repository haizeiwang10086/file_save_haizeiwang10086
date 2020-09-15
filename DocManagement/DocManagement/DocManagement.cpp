#include "DocManagement.h"
#include "qfiledialog.h"
#include "qaction.h"
#include "windows.h"
#include "tchar.h"
#include <QMessageBox>
#include <qdebug.h>
#include "CustomTabStyle.h"
#include "QQuestWindowControl.h"
#include "ImageToolDlgControl.h"

DocManagement::DocManagement(QWidget *parent)
    : QMainWindow(parent)
{

    ui.setupUi(this);
    setWindowTitle(QString::fromUtf16(u"������"));
    QIcon icon;
    icon.addFile(":/images/myapp.ico");
    setWindowIcon(icon);
    /*MTabWidget * tabWidget = new MTabWidget(this);
    tabWidget->show();*/
    ui.tabWidget->tabBar()->setStyle(new CustomTabStyle);

    HINSTANCE hDllSech = LoadLibrary(_T("QtSearchWindow.dll"));
    if (NULL == hDllSech)
    {
        QMessageBox::warning(this, "����", "QtSearchWindow.dll����ʧ�ܣ�");
    }

    //btnSign.setParent(this);
    QToolBar *pQtr = addToolBar("tool bar");
    QAction  *pQatAdd = pQtr->addAction("���");
	QAction *pLinkDb = pQtr->addAction("�������ݿ�");
    //pLinkDb->setIcon(QIcon("myapp.ico"));
    connect(pQatAdd,&QAction::triggered,
        [=]() mutable
        {
            QString fileName = QFileDialog::getOpenFileName(this, "���", "../", "doc(*.txt *.doc *.docx);;all(*.*)");
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
    fileManager = new FileManager(this);
    ui.tabWidget->addTab(&batEditWnd, QString::fromUtf16(u"������"));
	ui.tabWidget->addTab(fileManager, QString::fromUtf16(u"�ļ�����"));
    questWnd = new QQuestWindowControl(this);
    ui.tabWidget->addTab(questWnd, QString::fromUtf16(u"�����ѯ"));
    sechWnd = new QSearchWindowControl(this);
    ui.tabWidget->addTab(sechWnd, QString::fromUtf16(u"��Ϣ��ѯ"));
    imgToolWnd = new ImageToolDlgControl(this);
    ui.tabWidget->addTab(imgToolWnd, QString::fromUtf16(u"ͼ�񹤾�"));
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
		QMessageBox::about(this, QStringLiteral("��Ϣ"), desc);
	}
	else
	{
		QMessageBox::warning(this, QStringLiteral("��Ϣ"), desc);
	}
}

void DocManagement::dealTabClick(int idex)
{
    if (idex == 1)
    {
        sechWnd->closeDb();
        questWnd->closeDb();
        fileManager->openDb();
    }
    if (idex == 2)
    {
        fileManager->closeDb();
        sechWnd->closeDb();
        questWnd->openDb();
    }
    if (idex == 3)
    {
        fileManager->closeDb();
        questWnd->closeDb();
        sechWnd->openDb();
    }
}

