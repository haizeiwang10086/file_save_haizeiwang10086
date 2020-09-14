#include "Alg_DllName_WindowControl.h"
#include "qmessagebox.h"
#include "qsqlerror.h"

Alg_DllName_WindowControl::Alg_DllName_WindowControl(QWidget *parent)
{
    sechWnd.setParent(this);
}
bool Alg_DllName_WindowControl::show()
{
	sechWnd.show();
	return true;
}

void Alg_DllName_WindowControl::resizeEvent(QResizeEvent * event)
{
    sechWnd.resize(this->size());
}



Alg_DllName_WindowVirtualBase* createAlg_DllName_Window(QWidget *parent)
{
	return new Alg_DllName_WindowControl(parent);
}
bool freeAlg_DllName_Window(Alg_DllName_WindowVirtualBase* sechWnd)
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


