#ifndef CVSHOW_H
#define CVSHOW_H
#include "opencvshowwindow_global.h"
#include <opencv2\opencv.hpp>
//using namespace cv;



namespace Ui {
    OPENCVSHOWWINDOWSHARED_EXPORT int image_show();
    OPENCVSHOWWINDOWSHARED_EXPORT void addImage(cv::Mat& image);
    OPENCVSHOWWINDOWSHARED_EXPORT void named_window(char* name);
    OPENCVSHOWWINDOWSHARED_EXPORT void window_show();
}




#endif // CVSHOW_H
