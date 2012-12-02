#ifndef BLAMODEL_H
#define BLAMODEL_H

#include <QAbstractItemModel>
#include <QAbstractListModel>
#include <QDebug>

class BlaModel : public QAbstractListModel
{
    Q_OBJECT
    QList<QObject*> innerData;
public:
    explicit BlaModel(QObject *parent = 0);
    Q_INVOKABLE int dataLen() {
        return innerData.count();
    }

    int rowCount ( const QModelIndex & parent  ) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
signals:

public slots:

};

#endif // BLAMODEL_H
