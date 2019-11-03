/*
Navicat MySQL Data Transfer

Source Server         : dh
Source Server Version : 50560
Source Host           : localhost:3306
Source Database       : test

Target Server Type    : MYSQL
Target Server Version : 50560
File Encoding         : 65001

Date: 2019-11-03 23:12:48
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `question`
-- ----------------------------
DROP TABLE IF EXISTS `question`;
CREATE TABLE `question` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `title` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `content` longtext CHARACTER SET utf8,
  `label` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=52 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of question
-- ----------------------------
INSERT INTO `question` VALUES ('2', 'VS工作目录', '属性-》调试-》工作目录', 'c++');
INSERT INTO `question` VALUES ('3', '不能使用默认构造函数', '类中有其它复杂的类成员，且该类成员没有默认的构造函数，此时无法调用这个类的默认的构造函数（默认的构造函数时已删除的函数） ', 'c++');
INSERT INTO `question` VALUES ('4', '数据库占位符的使用', 'query->prepare(\"select * from question where id=?\")；\nquery->addBindValue(0,3)\n', 'qt');
INSERT INTO `question` VALUES ('6', 'qt连接数据库', '#include \"qsqldatabase.h\"\n#include \"qsqlquery.h\"\n\nQSqlDatabase db;\nQSqlQuery *query;\ndb.setDatabaseName(mConf.find(\"data_base_name\")->second);\n            db.setHostName(\"localhost\");\n            db.setUserName(mConf.find(\"user_name\")->second);\n            db.setPassword(mConf.find(\"db_password\")->second);\n            if (db.open())\n            {\n                query = new QSqlQuery(db);\n                isDbOpen = true;\n            }\nquery->exec(\"select * from info\");\n', 'qt');
INSERT INTO `question` VALUES ('7', 'QMainWindow', 'QMainWindow主要在windows下使用 ', 'qt');
INSERT INTO `question` VALUES ('8', 'QWidget', 'QWidget常用基类。窗口类的基类 ', 'qt');
INSERT INTO `question` VALUES ('9', 'QPushButton ', 'QPushButton b; \n    b.setText(\"lll\");//给按钮设置内容 \n    //b.show(); \n    /*如果不指定父对象，对象和对象（窗口和窗口）是没有关系的 \n    1.setParent（父对象显示，子对象自动显示） \n    2.通过构造杉树传参*/ \n    b.setParent(&w); \n    b.move(100,100); \n    b.show(); \n    QPushButton b1(&w);//通过构造函数传参 \n    b1.setText(\"bcd\"); \nb1.show(); \nb1.setStyleSheet(\"background: rgb(0,255,0));设置按钮背景颜色', 'qt');
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
INSERT INTO `question` VALUES ('38', 'vs qt 修改左上角图标', '在项目目录中添加XXX.qrc，添加内容：\n<RCC>\n    <qresource>\n      	  <file>images/sync.ico</file>\n	  <file>images/search.ico</file>\n	  <file>images/new.ico</file>\n    </qresource>\n</RCC>\n新建文件夹image,并将myapp.ico文件放到文件夹中，多个图标，添加多个路径即可，项目上右键-》添加现有项-》选择XXX.qrc文件\n项目中添加代码\nQIcon icon;\nicon.addFile(\":/image/myapp.ico\");\nsetWindowIcon(icon);\n\n按钮可以在ui界面设置图标，选择资源方式添加，选择对应的qrc文件', 'qt');
INSERT INTO `question` VALUES ('39', 'MFC空项目创建', '新建项目-》Visual C++ ->MFC->MFC 应用程序-》下一步-》基于对话框-》完成', 'MFC\n');
INSERT INTO `question` VALUES ('40', 'MessageBox', 'HWND hWnd = ::FindWindow(NULL, _T(\"新建文本文档 (2).txt - 记事本\"));//获取了一个窗口\n\nMessageBox(_T(\"第一个对话框\"), _T(\"提示\"),  MB_YESNOCANCEL|MB_ICONERROR);; //（对话框显示内容，对话框标题，对话框按钮类型）\nMB_ICONERROR图标类型\n该函数返回值为ok,no等按钮的宏定义（IDOK）。\n\n\nF12转到定义', 'MFC\n');
INSERT INTO `question` VALUES ('41', '图标|资源|对话框', '工程上点右键-》添加-》新建项-》资源-》资源文件（.rc）\n资源视图中找到刚才创建的.rc文件->右键-》添加资源（包括位图资源，光标资源，图标资源，等等）-》Icon(导入)/Dialog(对话框)-》编译（一般使用id最小的图标，在Resource.h里查看）\n\n\n资源：图标，光标，对话框...', 'MFC\n');
INSERT INTO `question` VALUES ('42', 'coding', '进入项目：\n任务-》里程碑（创建里程碑）\n       任务列表（创建任务）\n代码-》浏览代码，管理分支\n项目设置-》退出项目', 'windows\n');
INSERT INTO `question` VALUES ('43', 'OpenCv模板匹配', '    Mat img = imread(\"../images/tmp.tif\",1);\n    Mat img1 = imread(\"../images/2019_10_17_9_8_3_426_Z.tif\", 1);\n    if (img.empty()| img1.empty())\n    {\n        cout << \"load image failed...\" << endl;\n    }\n\n    Mat result;\n    matchTemplate(img1, img, result,4);\n    normalize(result, result, 0, 1, CV_MINMAX);\n    Point minLoc, maxLoc;\n    double minVal,maxVal;\n    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());\n    rectangle(img1, Rect(maxLoc.x, maxLoc.y, img.cols, img.rows), Scalar(0, 255, 255), 2, 8);\n    namedWindow(\"result\", CV_NORMAL);\n    imshow(\"result\", img1);\n    \n    waitKey(0);\n\n    TM_SQDIFF        = 0\n    TM_SQDIFF_NORMED = 1\n    TM_CCORR         = 2\n    TM_CCORR_NORMED  = 3\n    TM_CCOEFF        = 4\n    TM_CCOEFF_NORMED = 5', 'opencv');
INSERT INTO `question` VALUES ('44', 'QImage用法', 'cv::Mat mat(1024,800,CV_8UC1);\nuchar *pSrc=mat.data;\nQImage image(mat.cols,mat.rows,QImage::Format_Indexed8)\n//QImage::Format_Indexed8  显示灰度图像\n\nimage.setColorCount(256);\nfor(int i=0;i<256;i++)\n{\n   image.setColor(i,qRgb(i,i,i));\n}\nfor(int r=0;r<mat.rows;r++)\n{\n   uchar *pDst=image.scanLine(r)//行数据首地址\n   memcpy(pDst,pSrc,mat.cols);\n   pSrc+=mat.step;\n}\n', 'qt');
INSERT INTO `question` VALUES ('45', 'Edit Control', '对.rc文件中的Dialog ui界面给Edit Control控件添加变量，在*Dlg.h文件中将变量类型修改为CEditEx（自定义的一个类）,实现这个类，在类中对编辑框输入的内容进行定义\n\n//头文件\n#pragma once\n\n\n// CEditEx 对话框\nclass CEditEx : public CEdit\n{\n    DECLARE_DYNAMIC(CEditEx)\n\npublic:\n    CEditEx();\n    virtual ~CEditEx();\n\nprotected:\n    DECLARE_MESSAGE_MAP()\npublic:\n    afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);\n    afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);\n};\n\n//cpp文件\n\n// EditEx.cpp : 实现文件\n//\n#include \"stdafx.h\"\n#include \"EditEx.h\"\n\n// CEditEx\n\nIMPLEMENT_DYNAMIC(CEditEx, CEdit)\n\nCEditEx::CEditEx()\n{\n}\n\nCEditEx::~CEditEx()\n{\n    \n}\n//algstitchcheck项目中查看', 'MFC\n');
INSERT INTO `question` VALUES ('47', '编辑框背景颜色', '.rc文件中找到对话框，右键-》类向导-》消息-》WM_CTLCOLOR->添加处理程序-》编辑代码，cpp文件中函数里添加如下代码：\n\nHBRUSH CPropDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)\n{\n    HBRUSH hbr = CBCGPDialog::OnCtlColor(pDC, pWnd, nCtlColor);\n\n    if (nCtlColor == CTLCOLOR_EDIT &&\n            (pWnd->GetDlgCtrlID() == IDC_EDIT1 || \n                pWnd->GetDlgCtrlID() == IDC_EDIT2))\n    {\n        pDC->SetTextColor(RGB(255, 255, 255));\n        pDC->SetBkColor(RGB(0, 120, 215));//文本背景\n        hbr = CreateSolidBrush(RGB(37, 37, 37));//编辑框背景\n    }\n        \n\n     \n    return hbr;\n}', 'MFC\n');
INSERT INTO `question` VALUES ('48', 'DialogBox', '设置字体-》窗口初始化-》显示。。。。。\n需要支持拖动文件，将Accept Files设置为true（添加消息判断if(WM_DROPFILES==uMsg){}）\n//消息=消息号码+附加数据\nBOOL CALLBACK MainProc\n(\n	HWND hwndDlg,//本对话框句柄,修改消息的标题，移动窗口\n	UINT uMsg,//消息句柄，消息号码\n	WPARAM wParam,//uMsg携带的数据\n	LPARAM lParam//第二个参数\n	)\n{\n	CString s;\n	s.Format(_T(\"uMsg=%d,wParam=%d,lParam=%d\"), uMsg, wParam, lParam);\n\n	OutputDebugString(s);//可以在输出窗口输出\n	if (WM_COMMAND == uMsg)//WM windows 开头的都是windows信号，附带的消息，wParam,lParam\n	{\n		if (LOWORD(wParam) == IDCANCEL)//取低字节数据\n		{\n			EndDialog(hwndDlg, IDCANCEL);\n		}\n		if (LOWORD(wParam) == IDOK)\n		{\n		            int nLeft = GetDlgItemInt(hwndDlg, IDC_EDIT1,NULL,TRUE);//最后一个参数bSigned 是否有符号的数据类型标识\n			int nMid = GetDlgItemInt(hwndDlg, IDC_EDIT2, NULL, TRUE);\n			int nResut = nLeft + nMid;\n			SetDlgItemInt(hwndDlg, IDC_EDIT3, nResut, TRUE);\n		}\n	}\n	//截获按钮的操作\n	return false;\n}\nDialogBox(NULL, (LPCWSTR)IDD_CAP2_DIALOG, NULL, MainProc);//HINSTANCE ,LPCWSTR, ,回调函数', 'MFC\n');
INSERT INTO `question` VALUES ('49', 'UItralSO制作启动盘', '文件-》打开-》选择ISO镜像文件\n启动-》写入硬盘镜像\n\n USB-HDD （ USB Hard Drives 的缩写，硬盘模式）： 硬盘仿真模式，启动后U盘的盘符是C。（注意：这个模式在安装系统时容易混淆U盘和硬盘的C分区）。\n\n        USB-HDD+：增强的USB-HDD模式，DOS启动后显示C盘，兼容性高于USB-HDD模式。但对仅支持USB-ZIP的电脑无法启动。\n\n        USB-HDD + v2：USB-HDD + v2兼容性高于USB-HDD+，有可能支持USB-ZIP的电脑，在dos下启动后U盘盘符仍然显示为C盘。支持隐藏启动分区，可以防病毒、防误删和误格式化等。\n\n        USB-ZIP + v2：比USB-ZIP +多了一个深度隐藏功能。\n\n        至于什么深度隐藏功能还是太高深，我们做启动盘选择USB-HDD或USB-HDD+就行了，一般我都会选择USB-HDD+。\n', 'windows');
INSERT INTO `question` VALUES ('50', 'MFC变量类型', 'HANDLE of Windows =>HWND\nHANDLE of Instance =>HINSTANCE\nHANDLE of Icon =>HICON\n结构体\nPOINT  SIZE  RECT\n简单类型变量\nBOOL （TRUE  FALSE）//WIN32模式下不支持c++语法\nUINT u=20; //usigned int \nWPARAM和UINT一样，只是主要用于消息的传入\nLPARAM和long一个意思\nDWORD   unsigned long\nLONG    long\nWORD    unsigned short\nSHORT   short\nINT     int \n\nint i=10;\nPINT p=&i;所有变量加P指的是指针\nPSTR str=\"asdf\";\nLPSTR ss=\"asdf\";加P和加LP意思一样 char *\nLCSTR  cs=\"asdf\"; const char *\n', 'qt');
INSERT INTO `question` VALUES ('51', 'Windows快捷键', 'alt + 鼠标左键拖动 .exe文件，松开左键后创建快捷方式', 'windows');
