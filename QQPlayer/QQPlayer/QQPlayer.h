#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QQPlayer.h"
#include <QLabel>
#include <QPushButton>
#include <QDockWidget>

class QQPlayer : public QMainWindow
{
    Q_OBJECT

public:
    QQPlayer(QWidget *parent = Q_NULLPTR);

private:
    Ui::QQPlayerClass ui;
    QPushButton *tool;
    QMenu *menu;
};
