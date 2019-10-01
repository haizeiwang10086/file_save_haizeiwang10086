#pragma once
#include "qtsearchwindow_global.h"
#include "ui_SearchWindow.h"
#include <QWidget>
class  SearchWindowVirtualBase : public QWidget
{
public:
    Ui::SearchWindow sechWnd;

};

extern "C" QTSEARCHWINDOW_EXPORT SearchWindowVirtualBase* createSearchWindow();
extern "C" QTSEARCHWINDOW_EXPORT bool freeSearchWindow(SearchWindowVirtualBase* sechWnd);