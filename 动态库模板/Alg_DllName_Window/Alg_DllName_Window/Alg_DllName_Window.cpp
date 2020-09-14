#include "Alg_DllName_Window.h"
#include "qmessagebox.h"
#include "qsqlerror.h"
#include "qclipboard.h"
#include "qfile.h"
#include <map>


Alg_DllName_Window::Alg_DllName_Window()
{
    qtnWnd.setupUi(this);
    resize(QSize(800, 500));
    
}

