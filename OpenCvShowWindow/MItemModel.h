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

MItemModel::MItemModel()
{
}

QVariant MItemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignLeft | Qt::AlignVCenter);
    }
    else if (role == Qt::DisplayRole)
    {
        return QStandardItemModel::data(index, role);
    }
    else if (role == Qt::BackgroundColorRole)
    {
        if (index.row() % 2 == 0)
            return QColor(198, 198, 198);
        else if (index.row() % 2 == 1)
            return QColor(255, 255, 255);
        else
            return QVariant();
    }

    return QVariant();

    return QVariant();
}
