#include "halconcpp/halconcpp.h"
#include "cvshow.h"
using namespace HalconCpp;
using namespace Ui;




int main(void)
{
    HObject img;
    ReadImage(&img, "E:/workspace/images/label_2/PrintQI_1750_2_1_2_1_2_11_0_01738_AA00000000_20180419112226802.bmp");
    named_window("test");
    image_show("img", img);
    wait_key();

}