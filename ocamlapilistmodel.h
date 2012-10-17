#ifndef OCAMLAPILISTMODEL_H
#define OCAMLAPILISTMODEL_H

#include <QAbstractItemModel>
#include <QStringList>
#include <QDebug>


class OCamlAPIListModel : public QAbstractListModel
{
    Q_OBJECT
    QStringList _dataList;
public:
    OCamlAPIListModel();
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif // OCAMLAPILISTMODEL_H
