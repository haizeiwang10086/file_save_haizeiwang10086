#pragma once
#include "Alg_DeepLearning_WindowVirtualBase.h"
#include "qstandarditemmodel.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "ui_Alg_DeepLearning_Window.h"
#include "qtimagetoolwindow_global.h"

class QTSEARCHWINDOW_EXPORT Alg_DeepLearning_Window :public QWidget
{
public:
    Alg_DeepLearning_Window();

public:
	Ui::Alg_DeepLearning_Window qtnWnd;
	
};


