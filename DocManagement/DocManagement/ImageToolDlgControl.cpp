#include "ImageToolDlgControl.h"
#include "qmessagebox.h"
#include "qsqlerror.h"

ImageToolDlgControl::ImageToolDlgControl(QWidget *parent)
{
    sechWnd.setParent(this);
}
bool ImageToolDlgControl::show()
{
    sechWnd.show();
    return true;
}

void ImageToolDlgControl::resizeEvent(QResizeEvent * event)
{
    sechWnd.resize(this->size());
}



ImageToolWindowVirtualBase* createImageToolWindow(QWidget *parent)
{
    return new ImageToolDlgControl(parent);
}
bool freeImageToolWindow(ImageToolWindowVirtualBase* sechWnd)
{
    if (sechWnd != NULL)
    {
        delete sechWnd;
        return true;
    }
    else
    {
        return false;
    }

}


