#include "ocamlitem.h"

OCamlItem::OCamlItem(QString name, QObject *parent) :
     QObject(parent)
{
    _name = name;
}
