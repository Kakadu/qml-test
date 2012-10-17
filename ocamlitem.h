#ifndef OCAMLITEM_H
#define OCAMLITEM_H

#include <QObject>
#include <QDebug>

class OCamlItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name NOTIFY nameChanged);
    QString _name;
    Q_PROPERTY(QList<QObject*> sons READ sons NOTIFY sonsChanged);
    QList<QObject*> _sons;
public:
    explicit OCamlItem(QString name, QObject *parent = 0);


    QString name() { return _name; }
    QList<QObject*> sons() { return _sons; }
    void addSon(OCamlItem* item) { _sons.push_back(item); }
signals:
    void nameChanged();
    void sonsChanged();
public slots:

};
extern void printItem(QString prefix, OCamlItem* item);
#endif // OCAMLITEM_H
