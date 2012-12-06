#include <QApplication>
#include "qmlapplicationviewer.h"
#include "MainModel.h"
#include <QDeclarativeContext>

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);

    MainModel d;
    viewer.rootContext()->setContextProperty("mainModel", &d);

    viewer.setMainQmlFile(QLatin1String("qml/testModel/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
