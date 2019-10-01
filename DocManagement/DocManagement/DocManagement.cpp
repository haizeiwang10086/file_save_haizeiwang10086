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
    HINSTANCE hDll = LoadLibrary(_T("QtSearchWindow.dll"));
    if (NULL == hDll)
    {
        QMessageBox::warning(this, "����", "��̬�����ʧ�ܣ�");
    }
    pSearchWindow = (SearchWindow)GetProcAddress(hDll, "createSearchWindow");
    if(NULL== pSearchWindow)
    {
        QMessageBox::warning(this, "����", "��̬���ڲ���������ʧ�ܣ�");
    }

    sechWnd = pSearchWindow();
    ui.setupUi(this);
    QToolBar *pQtr = addToolBar("tool bar");
    QAction  *pQatAdd = pQtr->addAction("���");
    QAction  *pQatSearch = pQtr->addAction("����");

    connect(pQatAdd,&QAction::triggered,
        [=]() mutable
        {
            QString fileName = QFileDialog::getOpenFileName(this, "���", "../", "doc(*.txt *.doc *.docx);;all(*.*)");
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
            sechWnd->show();
    });
    
    QAction *batchEditName = pQtr->addAction("�����޸�");
    connect(batchEditName,&QAction::triggered,
        [=]()
        {
           
            batEditWnd.show();
            
        });
    
}
