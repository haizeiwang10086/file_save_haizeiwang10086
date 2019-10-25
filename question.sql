/*
Navicat MySQL Data Transfer

Source Server         : dh
Source Server Version : 50560
Source Host           : localhost:3306
Source Database       : test

Target Server Type    : MYSQL
Target Server Version : 50560
File Encoding         : 65001

Date: 2019-10-19 11:00:38
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `question`
-- ----------------------------
DROP TABLE IF EXISTS `question`;
CREATE TABLE `question` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `title` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `content` text CHARACTER SET utf8,
  `label` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=39 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of question
-- ----------------------------
INSERT INTO `question` VALUES ('2', 'VS工作目录', '属性-》调试-》工作目录', 'c++');
INSERT INTO `question` VALUES ('3', '不能使用默认构造函数', '类中有其它复杂的类成员，且该类成员没有默认的构造函数，此时无法调用这个类的默认的构造函数（默认的构造函数时已删除的函数） ', 'c++');
INSERT INTO `question` VALUES ('4', '数据库占位符的使用', 'query->prepare(\"select * from question where id=?\")；\nquery->addBindValue(0,3)\n', 'qt');
INSERT INTO `question` VALUES ('6', 'qt连接数据库', '#include \"qsqldatabase.h\"\n#include \"qsqlquery.h\"\n\nQSqlDatabase db;\nQSqlQuery *query;\ndb.setDatabaseName(mConf.find(\"data_base_name\")->second);\n            db.setHostName(\"localhost\");\n            db.setUserName(mConf.find(\"user_name\")->second);\n            db.setPassword(mConf.find(\"db_password\")->second);\n            if (db.open())\n            {\n                query = new QSqlQuery(db);\n                isDbOpen = true;\n            }\nquery->exec(\"select * from info\");\n', 'qt');
INSERT INTO `question` VALUES ('7', 'QMainWindow', 'QMainWindow主要在windows下使用 ', 'qt');
INSERT INTO `question` VALUES ('8', 'QWidget', 'QWidget常用基类。窗口类的基类 ', 'qt');
INSERT INTO `question` VALUES ('9', 'QPushButton ', 'QPushButton b; \n    b.setText(\"lll\");//给按钮设置内容 \n    //b.show(); \n    /*如果不指定父对象，对象和对象（窗口和窗口）是没有关系的 \n    1.setParent（父对象显示，子对象自动显示） \n    2.通过构造杉树传参*/ \n    b.setParent(&w); \n    b.move(100,100); \n    b.show(); \n    QPushButton b1(&w);//通过构造函数传参 \n    b1.setText(\"bcd\"); \nb1.show(); ', 'qt');
INSERT INTO `question` VALUES ('10', '信号与槽函数', '/*&b1 信号发出者，指针类型 \n     * &QPushButton::pressed  处理的信号， 发送者的类名::处理的信号 \n     * this 信号接收者，指针类型 \n     * &MyWidget::close      槽函数 信号处理函数   接受者的类名::槽函数名 \n     */ \nQT4槽函数必须有slots关键字来修饰 \nconnect(&b1,&QPushButton::pressed,this,&MyWidget::close); \n  \n/*自定义槽函数，普通函数的用法 \n     * Qt5: 任意的成员函数，普通全局函数，静态函数 \n     * 槽函数需要和信号一致（参数，返回值） \n     * 由于信号都是没有返回值，所以槽函数一定没有返回值 \n    */ \nvoid mySlot(); \nconnect(&b1,&QPushButton::released,this,&MyWidget::mySlot); \n/*信号必须有signals关键字来声明 \n     * 信号没有返回值，但可以有参数 \n     * 信号就是函数的声明，只需声明无需定义 \n     * 使用 emit mySignal(); \n     * 信号可以重载 \n     */ \nsignals: \n    void mySignal(); \nvoid mySignal(int,QString); ', 'qt');
INSERT INTO `question` VALUES ('11', 'QDebug qt打印输出', '和c++  cout的用法一样，用的时候qDebug()<<a<<str; ', 'qt');
INSERT INTO `question` VALUES ('12', '函数指针和函数多态', '函数指针  void (*p)(int)=fun; \n信号多态处理  void (SubWidget::*testWidget)(int,QString)=SubWidget::mySignal; ', 'c++');
INSERT INTO `question` VALUES ('13', 'qt lambda表达式 需要.pro文件添加c++11', 'CONFIG+=C++11 \n    connect(b3,&QPushButton::released, \n         [b3,a,b]()//a,b为只读，加关键字后可以修改[b3,a,b]() mutable \n            { \n               b3->setText(\"~_~\"); \n            }); \n[=]()lambda表达式中等号表示把外部所有局部变量、类中所有成员以值传递方式传入或者可可以自己写需要传递的值[b3,a,b] \n[&]()引用方式传入 ', 'qt');
INSERT INTO `question` VALUES ('14', '坐标系统', '1)对于窗口坐标原点在屏幕左上角，对于按钮坐标原点在窗口白色区域左上角 \n2)子窗口原点为相对于父窗口', 'qt');
INSERT INTO `question` VALUES ('15', 'qt内存管理机制', '直接或间接继承于QObject的类，指定父对象后，子对象如果是动态分配控件的new，不需要手动释放delete,系统会自动释放', 'qt');
INSERT INTO `question` VALUES ('16', 'QMenuBar 菜单条', 'QMenuBar *mBar=menuBar(); \n//添加菜单选项 \nQMenu *pFile=mBar->addMenu(\"文件\"); \n//添加菜单动作 \nQAction *pAction=pFile->addAction(\"new\"); ', 'qt');
INSERT INTO `question` VALUES ('17', 'QToolBar 工具栏', 'QAction *pAction;\nQToolBar *toolBar=addToolBar(\"tool Bar\"); \n    //工具栏添加快捷键,使用前面的指针就可以 \ntoolBar->addAction(pAction); \nQPushButton *b=new QPushButton; \nb->setText(\"1_1\"); \ntoolBar->addWidget(b); ', 'qt');
INSERT INTO `question` VALUES ('18', 'QStatusBar 状态栏', 'QStatusBar *statBar=statusBar(); \nQLabel *label=new QLabel(this); \nlabel->setText(\"Normal text file\"); \nstatBar->addWidget(label);//从左向右添加 \nstatBar->addWidget(new QLabel(\"3\",this)); \nstatBar->addPermanentWidget(new QLabel(\"6\",this));//从右向左添加 ', 'qt');
INSERT INTO `question` VALUES ('19', '#include <QAxWidget> 找不到文件', '修改pro文件，添加 QT += axcontainer ', 'qt');
INSERT INTO `question` VALUES ('20', 'MySql 动态库放置路径libmySQL.dll', 'D:QT5.9.2mingw53_32in ', 'qt');
INSERT INTO `question` VALUES ('21', 'release模式下无法调试', '属性页-》c/c++ -> 常规-》调试信息格式：程序数据（/Zi）\n         连接器-》调试-》生成调试信息：优化以便于调试(/DEBUG)', 'qt');
INSERT INTO `question` VALUES ('22', 'qt快捷键', 'F4跳到对应的.cpp', 'qt');
INSERT INTO `question` VALUES ('23', '中心控件', 'QTextEdit *qte=new QTextEdit(this);文本编辑 \nsetCentralWidget(qte);设置中心控件 ', 'qt');
INSERT INTO `question` VALUES ('24', '浮动窗口', 'QDockWidget *dock=new QDockWidget(this);//浮动窗口 \naddDockWidget(Qt::RightDockWidgetArea,dock);//主窗口增加浮动窗口 \nQTextEdit *dockQte=new QTextEdit(this);//文本编辑窗口 \ndock->setWidget(dockQte);//浮动窗口增加文本编辑器 ', 'qt');
INSERT INTO `question` VALUES ('25', '模态对话框', ' QDialog dlg;\ndlg.exec();//阻塞对话框', 'qt');
INSERT INTO `question` VALUES ('26', '非模态对话框', 'QDialog dlg; \n//  dlg.show(); //显示对话框不阻塞,函数运行完变量删除，对话框一闪消失 ', 'qt');
INSERT INTO `question` VALUES ('27', 'QDialog 对话框', 'QDialog dlg; \ndlg.show(); //显示对话框不阻塞,函数运行完变量删除，对话框一闪消失 \ndlg.exec();//阻塞对话框\nQDialog *dlg=new QDialog(this); \ndlg->setAttribute(Qt::WA_DeleteOnClose);//文本框关闭后删除 \n                   dlg->show(); ', 'qt');
INSERT INTO `question` VALUES ('28', 'QMessageBox 消息对话框', 'QMessageBox::about(this,\"关于QT\",\"对话框测试\");//消息对话框 \n                int ret=QMessageBox::question(this,\"question\",\"Are you ok?\"); ', 'qt');
INSERT INTO `question` VALUES ('29', 'QFileDialog 文件对话框', ' QString path=QFileDialog::getOpenFileName( \n                            this, \n                            \"open\", \n                            \"../\", \n                            tr(\"source(*.cpp *.h);;Text(*.txt);;all(*.*)\")); ', 'qt');
INSERT INTO `question` VALUES ('30', '消息对话框中文乱码', 'QStringLiteral类用于解决qt中的乱码问题\nQStringLiteral(\"中文信息\"); \n\n窗口标题乱码\n\nsetWindowTitle(QString::fromUtf16(u\"管理工具\"));', 'qt');
INSERT INTO `question` VALUES ('31', 'vs运行qt 中文乱码问题', '1.  //在头文件前面加上下面几行代码 \n2.  #ifdef WIN32  \n3.  #pragma execution_character_set(\"utf-8\")  \n4.  #endif ', 'qt');
INSERT INTO `question` VALUES ('32', 'resizeEvent重写窗口大小改变事件', '.h文件中添加声明\npublic:\nvoid resizeEvent(QResizeEvent * event)\n.cpp文件中重写这个函数', 'qt');
INSERT INTO `question` VALUES ('35', 'QTabWidget 主窗口左侧功能栏', '需要功能菜单显示在左侧，且文字水平，需要重写QProxyStyle（见最下面）\n\n最后再 ui.tabWidget->tabBar()->setStyle(new CustomTabStyle);\n\n用法：ui.tabWidget->addTab(&docDisp, \"Main\");增加新的窗口docDisp 是一个QWidget类\n标签切换触发事件：connect(ui.tabWidget, &QTabWidget::currentChanged, this, &DocManagement::dealTabClick);\nclass CustomTabStyle : public QProxyStyle\n{\npublic:\n    QSize sizeFromContents(ContentsType type, const QStyleOption *option,\n        const QSize &size, const QWidget *widget) const;\n\n    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const;\n \n};\n\n\ncpp文件\n\n#include \"CustomTabStyle.h\"\n\n\n\nQSize CustomTabStyle::sizeFromContents(ContentsType type, const QStyleOption *option,\n    const QSize &size, const QWidget *widget) const\n{\n    QSize s = QProxyStyle::sizeFromContents(type, option, size, widget);\n    if (type == QStyle::CT_TabBarTab)\n    {\n        s.transpose();\n        s.rwidth() = 70;\n        s.rheight() = 30;\n    }\n    return s;\n}\n\nvoid CustomTabStyle::drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const\n{\n    if (element == CE_TabBarTabLabel) {\n        if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option)) {\n            QRect allRect = tab->rect;\n\n            if (tab->state & QStyle::State_Selected) {\n                painter->save();\n                painter->setPen(0x89cfff);\n                painter->setBrush(QBrush(0x89cfff));\n                painter->drawRect(allRect.adjusted(1, 3, -1, -6));\n                painter->restore();\n            }\n            QTextOption option;\n            option.setAlignment(Qt::AlignCenter);\n            if (tab->state & QStyle::State_Selected) {\n                painter->setPen(0xf8fcff);\n            }\n            else {\n                painter->setPen(0x5d5d5d);\n            }\n            painter->drawText(allRect, tab->text, option);\n            return;\n        }\n    }\n\n    if (element == CE_TabBarTab) {\n        QProxyStyle::drawControl(element, option, painter, widget);\n    }\n}\n\n', 'qt');
INSERT INTO `question` VALUES ('38', 'vs qt 修改左上角图标', '在项目目录中添加XXX.qrc，添加内容：\n<RCC>\n    <qresource>\n      <file>image/myapp.ico</file>\n    </qresource>\n</RCC>\n新建文件夹image,并将myapp.ico文件放到文件夹中，项目上右键-》添加现有项-》选择XXX.qrc文件\n项目中添加代码\nQIcon icon;\nicon.addFile(\":/image/myapp.ico\");\nsetWindowIcon(icon);', 'qt');
