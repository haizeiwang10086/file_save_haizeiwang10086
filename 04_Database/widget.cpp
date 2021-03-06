#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QGraphicsScene>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //打印QT支持的数据库驱动
    qDebug()<<QSqlDatabase::drivers();
    //添加Mysql数据库
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    //连接数据库
    db.setHostName("localhost");//数据库服务器Ip
    db.setUserName("root");
    db.setPassword("root123");
    db.setDatabaseName("mymemorandum");//使用哪个数据库
    //打开数据库
    if(!db.open())
    {
        QMessageBox::warning(this,"警告",db.lastError().text());
        return;
    }

    //专门对Sql操作的类
    QSqlQuery query;
    //query.exec("create table info (id int primary key auto_increment,title varchar(255),content varchar(255));");

    //query.exec("insert into info(title, content) values('速盘激活码','F9EA0F22-F6E5-3FF5-BDDA-AB7EDD0B7B3B')");

    //批量插入
    query.prepare("insert into info(title, content) values(?,?)")
    //QSqlDatabase db1=QSqlDatabase::addDatabase("QMYSQL","a");//第二个参数是名字,没有任何意义，创建QSqlQuery query（db1）;必须制定db1

    QGraphicsScene qg;
}

Widget::~Widget()
{
    delete ui;
}
