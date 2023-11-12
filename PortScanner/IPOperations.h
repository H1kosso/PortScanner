#ifndef IPOPERATIONS_H
#define IPOPERATIONS_H

#include <QString>
#include <QTcpSocket>

void checkIpAvailability(const QString &ip, int port);
QString extractSubnet(const QString &ipAddress);
#endif // IPOPERATIONS_H
