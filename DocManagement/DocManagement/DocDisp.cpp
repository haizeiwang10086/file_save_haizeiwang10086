#include "DocDisp.h"


DocDisp::DocDisp(QWidget *parent)
{
    DDC.setupUi(this);
}

void DocDisp::resizeEvent(QResizeEvent *event)
{
    QSize size = this->size();
    DDC.textEdit->resize(size.width()-20,size.height()-20);
    DDC.textEdit->move(10, 10);
}