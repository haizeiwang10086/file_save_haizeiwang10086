#ifndef CVSHOW_H
#define CVSHOW_H
#include "opencvshowwindow_global.h"
#include <opencv2\opencv.hpp>
//using namespace cv;



namespace Ui {
    OPENCVSHOWWINDOWSHARED_EXPORT void image_show(char* name, cv::Mat& image);
    OPENCVSHOWWINDOWSHARED_EXPORT void named_window(char* name);
    OPENCVSHOWWINDOWSHARED_EXPORT void wait_key();
}




#endif // CVSHOW_H
