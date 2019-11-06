#ifndef CVSHOW_H
#define CVSHOW_H
#include "halconcpp/halconcpp.h"
//using namespace cv;



namespace Ui {
    void image_show(char* name, HalconCpp::HObject& image);
    void named_window(char* name);
    void wait_key();
}




#endif // CVSHOW_H
