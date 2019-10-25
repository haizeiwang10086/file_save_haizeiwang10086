#include "BrowseDlg.h"

BrowseDlg::BrowseDlg(QWidget *parent)
{
    boe.setupUi(this);
    resize(800, 500);
}

void BrowseDlg::resizeEvent(QResizeEvent * event)
{
    QSize size = this->size(); 
    boe.label->move(size.width() / 10, size.height() / 10);
    boe.label_2->move(size.width() / 10, size.height() / 10 + 30);
    boe.label_3->move(size.width() / 10, size.height() - 70);
    boe.text_title->move(size.width() / 10 + 40, size.height() / 10);
    boe.text_title->resize(size.width() * 9 / 10 - 100, 25);
    boe.text_content->move(size.width() / 10 + 40, size.height() / 10 + 30);
    boe.text_content->resize(size.width() * 9 / 10 - 100, size.height() * 9 / 10 - 120);
    boe.label_remarks->move(size.width() / 10 + 40, size.height() - 70);
    boe.label_remarks->resize(size.width() * 9 / 10 - 100, 20);
    boe.okButton->move(size.width() - 200, size.height() - 40);
    boe.cancelButton->move(size.width() - 120, size.height() - 40);
    
    
}