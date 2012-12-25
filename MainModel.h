#ifndef BLAMODEL_H
#define BLAMODEL_H

#include <QAbstractItemModel>
#include <QAbstractListModel>
#include <QDebug>
#include "minimodel.h"

const int HOMMRole = Qt::UserRole + 100;

class DataObject;
class MainModel : public QAbstractListModel
{
    Q_OBJECT
    QList<MiniModel*> innerData;
    static const int FirstNameRole;

    //static const int SortRole;

public:
    explicit MainModel(QObject *parent = 0);
    Q_INVOKABLE int dataLen() {
        return innerData.count();
    }
    Q_INVOKABLE QList<QString> roles() {
        QList<QString> ans;
        foreach(QByteArray b, roleNames().values() ) {
            ans << QString(b);
        }
        return ans;
    }
    int rowCount ( const QModelIndex & parent  ) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

signals:

public slots:

private:
    Q_DISABLE_COPY(MainModel)
};
Q_DECLARE_METATYPE(QList<MiniModel*>)
Q_DECLARE_METATYPE(MiniModel*)
#endif // BLAMODEL_H
