#include "ocamlitem.h"

OCamlItem::OCamlItem(QString name, QObject *parent) :
     QObject(parent)
{
    _name = name;
}

void printItem(QString prefix, OCamlItem* item) {
    QString newprefix = prefix + "+" + item->name();
    qDebug() << newprefix;

    foreach (QObject* o, item->sons()) {
        OCamlItem *i = dynamic_cast<OCamlItem*>(o);
        printItem(newprefix, i);
    }
}
