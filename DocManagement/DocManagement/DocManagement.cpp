#include "DocManagement.h"
#include "qfiledialog.h"
#include "qaction.h"


DocManagement::DocManagement(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QToolBar *pQtr = addToolBar("tool bar");
    QAction  *pQatAdd = pQtr->addAction("Ìí¼Ó");
    QAction  *pQatSearch = pQtr->addAction("²éÕÒ");

    connect(pQatAdd,&QAction::triggered,
        [=]() mutable
        {
            QString fileName = QFileDialog::getOpenFileName(this, "Ìí¼Ó", "../", "doc(*.txt *.doc *.docx);;all(*.*)");
            QStringList nameList=fileName.split("/");
            ui.fileNameLists->setText(nameList[nameList.size()-1]);
            
            if (fileName.endsWith(".docx") || fileName.endsWith(".doc"))
            {
                try
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
                catch (const std::exception& e)
                {
                    int a = 1;
                }
               
            }
        });

    connect(pQatSearch,&QAction::triggered,
        [=]()
        {
            hide();
            subWidget.show();
    });
    
    
    
}
