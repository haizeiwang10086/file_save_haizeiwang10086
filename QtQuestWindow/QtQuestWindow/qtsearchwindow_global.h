#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(QTSEARCHWINDOW_LIB)
#  define QTSEARCHWINDOW_EXPORT Q_DECL_EXPORT
# else
#  define QTSEARCHWINDOW_EXPORT Q_DECL_IMPORT
# endif
#else
# define QTSEARCHWINDOW_EXPORT
#endif
