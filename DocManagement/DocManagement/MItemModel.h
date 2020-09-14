#pragma once


#include "qstandarditemmodel.h"
#include "qvariant.h"

class MItemModel :public QStandardItemModel
{
public:
    MItemModel();
    QVariant data(const QModelIndex &index, int role) const;
    //QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};