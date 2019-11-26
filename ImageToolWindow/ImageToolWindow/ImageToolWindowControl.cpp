#include "ImageToolWindowControl.h"
#include "qmessagebox.h"
#include "qsqlerror.h"

ImageToolWindowControl::ImageToolWindowControl(QWidget *parent)
{
    sechWnd.setParent(this);
}
bool ImageToolWindowControl::show()
{
	sechWnd.show();
	return true;
}

void ImageToolWindowControl::resizeEvent(QResizeEvent * event)
{
    sechWnd.resize(this->size());
}



ImageToolWindowVirtualBase* createImageToolWindow(QWidget *parent)
{
	return new ImageToolWindowControl(parent);
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


