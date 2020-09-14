#pragma once
#include "Alg_DeepLearning_WindowVirtualBase.h"
#include "Alg_DeepLearning_Window.h"
#include "qtimagetoolwindow_global.h"

class Alg_DeepLearning_WindowControl :public Alg_DeepLearning_WindowVirtualBase
{
public:
    Alg_DeepLearning_WindowControl(QWidget *parent=Q_NULLPTR);
	virtual  bool show();
    void resizeEvent(QResizeEvent * event);

private:
	Alg_DeepLearning_Window sechWnd;

};

extern "C" QTSEARCHWINDOW_EXPORT Alg_DeepLearning_WindowVirtualBase* createAlg_DeepLearning_Window(QWidget *parent);
extern "C" QTSEARCHWINDOW_EXPORT bool freeAlg_DeepLearning_Window(Alg_DeepLearning_WindowVirtualBase* sechWnd);


