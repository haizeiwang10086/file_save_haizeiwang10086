#include "DocManagement.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DocManagement w;
    w.show();
    return a.exec();
}
