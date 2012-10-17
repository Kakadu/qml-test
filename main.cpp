/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qmlapplicationviewer.h"
#include <QApplication>
#include <qdeclarativecontext.h>
#include <ocamlapilistmodel.h>
#include "ocamlitem.h"

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);
    QmlApplicationViewer viewer;

    QList<QObject*> lst;
    for (int i = 1; i<=5; ++i) {
        OCamlItem *l = new OCamlItem(QString("%1").arg(i) );
        for (int j = 1; j<=3; ++j) {
            l->addSon( new OCamlItem(QString("%1,%2").arg(i).arg(j)) );
        }
        lst.append(l);
    }
    foreach(QObject* o, lst) {
        OCamlItem *i = dynamic_cast<OCamlItem*>(o);
        printItem(i->name(), i);
    }

    QDeclarativeContext *ctxt = viewer.rootContext();
    //ctxt->setContextProperty("ocamlAPIViewModel", QVariant::fromValue(dataList));
    ctxt->setContextProperty("ocamlAPIViewModel",
                             QVariant::fromValue(lst) );

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationLockLandscape);
    viewer.setMainQmlFile(QLatin1String("qml/main/view.qml"));
    viewer.showExpanded();

    return app.exec();
}

