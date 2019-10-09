#include "DocManagement.h"
#include "qfiledialog.h"
#include "qaction.h"
#include "windows.h"
#include "tchar.h"
#include <QMessageBox>
#include <qdebug.h>

DocManagement::DocManagement(QWidget *parent)
    : QMainWindow(parent)
{
    HINSTANCE hDll = LoadLibrary(_T("QtQuestWindow.dll"));
    if (NULL == hDll)
    {
        QMessageBox::warning(this, "警告", "动态库加载失败！");
    }
    pSearchWindow = (QuestionWindow)GetProcAddress(hDll, "createQuestionWindow");
    if(NULL== pSearchWindow)
    {
        QMessageBox::warning(this, "警告", "动态库内部函数调用失败！");
    }

    sechWnd = pSearchWindow();
    ui.setupUi(this);
    QToolBar *pQtr = addToolBar("tool bar");
    QAction  *pQatAdd = pQtr->addAction("添加");
    QAction  *pQatSearch = pQtr->addAction("查找");
	QAction *batchEditName = pQtr->addAction("批量修改");
	QAction *pLinkDb = pQtr->addAction("链接数据库");

    connect(pQatAdd,&QAction::triggered,
        [=]() mutable
        {
            QString fileName = QFileDialog::getOpenFileName(this, "添加", "../", "doc(*.txt *.doc *.docx);;all(*.*)");
            QStringList nameList=fileName.split("/");
            ui.fileNameLists->setText(nameList[nameList.size()-1]);
            
            if (fileName.endsWith(".docx") || fileName.endsWith(".doc"))
            {
                    //officeContent = new QAxWidget("Word.Document", ui.docDisp);
                    officeContent = new QAxWidget("Word.Application", ui.docDisp); 
                    int width=ui.docDisp->width();
                    int height= ui.docDisp->height();
                    QRect rect=ui.docDisp->rect();
                    officeContent->setGeometry(QRect(20,20,width-20,height-20));
                    officeContent->setControl(fileName);
                    officeContent->show();

 
            }
        });

    connect(pQatSearch,&QAction::triggered,
        [=]()
        {
            hide();
            sechWnd->showData();
            sechWnd->show();
    });
    
    
    connect(batchEditName,&QAction::triggered,
        [=]()
        {
            batEditWnd.show();
        });

	connect(pLinkDb,&QAction::triggered,
		[=]()
		{
			dbDlg.readConfig();
			dbDlg.exec();
		});
	void (DataBaseLinkDialog::*linkSignal)(QString dbName, QString userName, QString password) = &DataBaseLinkDialog::dataBaseLinkSignal;
	connect(&dbDlg, linkSignal, this, &DocManagement::linkDb);

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
