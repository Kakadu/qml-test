#include "ocamlapilistmodel.h"

OCamlAPIListModel::OCamlAPIListModel()
{
    _dataList.append("Item 1");
    _dataList.append("Item 2");
    _dataList.append("Item 3");
    _dataList.append("Item 4");
}

int OCamlAPIListModel::rowCount(const QModelIndex &parent) const {
    return 1;
}

QVariant OCamlAPIListModel::data(const QModelIndex &index, int role) const {
    qDebug() << "here";
    return
            QVariant::fromValue(_dataList);
}
