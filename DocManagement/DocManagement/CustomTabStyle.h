#pragma once

#include <QProxyStyle>
#include <QPainter>
#include <QStyleOption>


class CustomTabStyle : public QProxyStyle
{
public:
    QSize sizeFromContents(ContentsType type, const QStyleOption *option,
        const QSize &size, const QWidget *widget) const;

    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
 
};

