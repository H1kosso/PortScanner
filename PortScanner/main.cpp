#include <QGuiApplication>
#include <QHostInfo>
#include <QNetworkAccessManager>
#include <QNetworkInterface>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QProcess>
#include <QQmlApplicationEngine>
#include "IPOperations.h"
#include "LocalMachine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/PortScanner/Main.qml"_qs);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    LocalMachine localMachine;
    qDebug() << localMachine.ip;

    checkIpAvailability("192.168.0.1");

    engine.load(url);
    return app.exec();
}
