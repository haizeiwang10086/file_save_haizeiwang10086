#include "Alg_DeepLearning_WindowControl.h"
#include "qmessagebox.h"
#include "qsqlerror.h"

Alg_DeepLearning_WindowControl::Alg_DeepLearning_WindowControl(QWidget *parent)
{
    sechWnd.setParent(this);
}
bool Alg_DeepLearning_WindowControl::show()
{
	sechWnd.show();
	return true;
}

void Alg_DeepLearning_WindowControl::resizeEvent(QResizeEvent * event)
{
    sechWnd.resize(this->size());
}



Alg_DeepLearning_WindowVirtualBase* createAlg_DeepLearning_Window(QWidget *parent)
{
	return new Alg_DeepLearning_WindowControl(parent);
}
bool freeAlg_DeepLearning_Window(Alg_DeepLearning_WindowVirtualBase* sechWnd)
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


