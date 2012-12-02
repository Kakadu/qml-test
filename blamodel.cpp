#include "blamodel.h"

BlaModel::BlaModel(QObject *parent) :
    QAbstractListModel(parent)
{
    innerData << new QObject()  << new QObject()  << new QObject() ;
}

int BlaModel::rowCount ( const QModelIndex & ) const {
    //qDebug() << "rowCount = " << innerData.count();
    return innerData.count();
}

QVariant BlaModel::data ( const QModelIndex & index, int role ) const {
    Q_UNUSED(role);
    qDebug() << "data where index = " << index.row();
    int r = index.row();
    if ((r<0) || (r>=innerData.count()))
        return QVariant::Invalid;
    return QVariant::fromValue( innerData.at(r) );
}
