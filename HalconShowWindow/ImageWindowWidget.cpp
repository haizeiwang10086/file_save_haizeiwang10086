#include "ImageWindowWidget.h"

ImageWindowWidget::ImageWindowWidget(QWidget *parent) :QWidget(parent)
{
    img_wnd = new ImageWidget(this);
    tableWidget = new QTableWidget(this);
    tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background:rgb(51, 153, 255);color: black; \
                                                            font-weight: bold;padding-left: 4px;border: 1px solid #6c6c6c;}");
    
    tableWidget->hide();
    img_wnd->show();
}

void ImageWindowWidget::resizeEvent(QResizeEvent * event)
{
    img_wnd->resize(size());
    tableWidget->resize(size());
    
}

void ImageWindowWidget::setShowHTuple(HTuple tuple)
{
    m_ShowTuple = tuple.Clone();
    tableWidget->clear();
    //tableWidget->setWindowTitle();
   
    tableWidget->setColumnCount(1);
    QStringList header;
    header << QStringLiteral("变量");
    tableWidget->setHorizontalHeaderLabels(header);

    HTuple hv_Length;
    TupleLength(tuple, &hv_Length);
    int length=2000;
    if (hv_Length < length + 1)
    {
        length = hv_Length;
        tableWidget->setRowCount(length);
    }
    else
    {
        tableWidget->setRowCount(length + 1);
    }
    tableWidget->setColumnWidth(0, tableWidget->width());
    for (int i = 0; i < length; i++)
    {
        HTuple hv_strNum, hv_T = tuple[i];
        TupleString(tuple[i], ".7f", &hv_strNum);
        tableWidget->setItem(i, 0, new QTableWidgetItem(hv_strNum.S().Text()));
    }
    if (hv_Length > 2000)
    {
        QPushButton *newVariant = new QPushButton(QStringLiteral("查看更多"));
        tableWidget->setCellWidget(tableWidget->rowCount() - 1, 0, newVariant);
        connect(newVariant, &QPushButton::clicked, this, &ImageWindowWidget::showMore);
    }
    
}

void ImageWindowWidget::showMore()
{
    tableWidget->removeCellWidget(tableWidget->rowCount()-1,0);
    int rows = tableWidget->rowCount();
    
    tableWidget->setRowCount(rows + 2000);
    
    for (int i = rows-1; i < rows + 1999; i++)
    {
        HTuple hv_strNum;
        TupleString(m_ShowTuple[i], ".7f", &hv_strNum);
        tableWidget->setItem(i, 0, new QTableWidgetItem(hv_strNum.S().Text()));
    }
    
    QPushButton *newVariant = new QPushButton(QStringLiteral("查看更多"));
    tableWidget->setCellWidget(tableWidget->rowCount() - 1, 0, newVariant);
    connect(newVariant, &QPushButton::clicked, this, &ImageWindowWidget::showMore);
}