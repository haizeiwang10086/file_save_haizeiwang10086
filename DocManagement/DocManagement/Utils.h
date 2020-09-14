#pragma once
#include <opencv2/opencv.hpp>
#include "qimage.h"

void Mat2QImage(cv::Mat &mat, QImage& rgb);
void QImage2Mat(QImage& rgb, cv::Mat &mat);
QString baseName(QString filePath);
