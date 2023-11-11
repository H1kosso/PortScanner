#ifndef IPOPERATIONS_H
#define IPOPERATIONS_H

#include <QString>
#include <QTcpSocket>

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
#endif // IPOPERATIONS_H
