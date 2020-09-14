#include "Alg_DeepLearning_Window.h"
#include "qmessagebox.h"
#include "qsqlerror.h"
#include "qclipboard.h"
#include "qfile.h"
#include <map>


Alg_DeepLearning_Window::Alg_DeepLearning_Window()
{
    qtnWnd.setupUi(this);
    resize(QSize(800, 500));
    
}

