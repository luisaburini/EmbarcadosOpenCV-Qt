#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <facedetect.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    FaceDetect detectFace;
    engine.rootContext()->setContextProperty("detectFace", &detectFace);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
