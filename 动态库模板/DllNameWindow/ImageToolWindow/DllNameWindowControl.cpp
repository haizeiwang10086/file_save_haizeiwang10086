#include "DllNameWindowControl.h"
#include "qmessagebox.h"
#include "qsqlerror.h"

DllNameWindowControl::DllNameWindowControl(QWidget *parent)
{
    sechWnd.setParent(this);
}
bool DllNameWindowControl::show()
{
	sechWnd.show();
	return true;
}

void DllNameWindowControl::resizeEvent(QResizeEvent * event)
{
    sechWnd.resize(this->size());
}



DllNameWindowVirtualBase* createDllNameWindow(QWidget *parent)
{
	return new DllNameWindowControl(parent);
}
bool freeDllNameWindow(DllNameWindowVirtualBase* sechWnd)
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


