#include <QGuiApplication>
#include <QHostInfo>
#include <QNetworkAccessManager>
#include <QNetworkInterface>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QProcess>
#include <QQmlApplicationEngine>
#include "LocalMachine.h"

void checkIpAvailability(const QString &ip, int port = 80)
{
    QTcpSocket socket;

    socket.connectToHost(ip, port);

    if (socket.waitForConnected(3000)) // Czas oczekiwania na połączenie w milisekundach
    {
        qDebug() << "IP" << ip << "is reachable";
    } else {
        qDebug() << "IP" << ip << "is not reachable";
    }
}

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
