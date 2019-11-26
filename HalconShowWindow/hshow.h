#ifndef CVSHOW_H
#define CVSHOW_H
#include "halconshowwindow_global.h"
#include "halconcpp/halconcpp.h"
//using namespace cv;



namespace Ui {
    OPENCVSHOWWINDOWSHARED_EXPORT void image_show(char* name, HalconCpp::HObject& image);
    OPENCVSHOWWINDOWSHARED_EXPORT void tuple_show(char* name, HalconCpp::HTuple& tuple);
    OPENCVSHOWWINDOWSHARED_EXPORT void named_window(char* name);
    OPENCVSHOWWINDOWSHARED_EXPORT void wait_key();
}




#endif // CVSHOW_H
