#include "DllNameWindow.h"
#include "qmessagebox.h"
#include "qsqlerror.h"
#include "qclipboard.h"
#include "qfile.h"
#include <map>


DllNameWindow::DllNameWindow()
{
    qtnWnd.setupUi(this);
    resize(QSize(800, 500));
    
}

