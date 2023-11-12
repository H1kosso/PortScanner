#include "IPOperations.h"

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

QString extractSubnet(const QString &ipAddress)
{
    QStringList octets = ipAddress.split('.');

    if (octets.size() != 4) {
        qWarning() << "Invalid IP address format";
        return QString();
    }

    QString subnet = octets[0] + '.' + octets[1] + '.' + octets[2];
    return subnet;
}
