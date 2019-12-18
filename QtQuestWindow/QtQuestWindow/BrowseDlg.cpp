#include "BrowseDlg.h"

BrowseDlg::BrowseDlg(QWidget *parent)
{
    boe.setupUi(this);
    resize(800, 500);
}

void BrowseDlg::resizeEvent(QResizeEvent * event)
{
    QSize size = this->size(); 

    boe.text_content->move(size.width() / 10 - 10, size.height() / 10 - 10);
    boe.text_content->resize(size.width() * 9 / 10 - 50, size.height() * 9 / 10 - 40);
    boe.okButton->move(size.width() - 200, size.height() - 40);
    boe.cancelButton->move(size.width() - 120, size.height() - 40);
    
    
}