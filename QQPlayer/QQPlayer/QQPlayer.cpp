#include "QQPlayer.h"
#include <QStatusBar>
#include <QAction>


QQPlayer::QQPlayer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this); 
    
    QStatusBar *statBar = statusBar();
    QAction *act = new QAction("tool",statBar);
    statBar->addAction(act);
    statBar->insertAction(act,act);
    QToolBar *toolBar = new QToolBar("test");
    QMenu *menu = new QMenu("menu");
    menu->addAction(act);

    toolBar->addAction(act);
    toolBar->addWidget(menu);
        addToolBar(Qt::BottomToolBarArea, toolBar);
    
    /*tool = new QPushButton("",statBar);
    tool->setIcon(QIcon(":/images/tool.ico"));
    tool->setStyleSheet("QPushButton::hover{background-color:blue}QPushButton{background-color:black}");*/
    //statBar->addPermanentWidget(tool);
    //QPushButton *btn = new QPushButton("123w");
    //statBar->addWidget(btn);
   // statBar->setStyleSheet("QStatusBar{background-color:black}");
   /* QPoint p = statBar->pos();
    menu = new QMenu("¹¤¾ß", statBar);
    menu->setStyleSheet("QPushButton::hover{background-color:blue}QPushButton{background-color:black}");
    statBar->addPermanentWidget(menu);
    menu->show();*/
}
