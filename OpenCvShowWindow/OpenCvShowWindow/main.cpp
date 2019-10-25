#include "OpenCvShowWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenCvShowWindow w;
    w.show();
    return a.exec();
}
