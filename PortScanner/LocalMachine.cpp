#include "LocalMachine.h"

LocalMachine::LocalMachine()
{
    interfaces = QNetworkInterface::allInterfaces();
    setMainInterface(interfaces[0]);
}

void LocalMachine::printAllInterfaces() const
{
    foreach (const auto interface, interfaces) {
        qDebug() << "Name:" << interface.name();
        qDebug() << "Display Name:" << interface.humanReadableName();
        qDebug() << "Hardware Address:" << interface.hardwareAddress();
    }
}
void LocalMachine::printMainInterface() const
{
    qDebug() << "Name:" << mainInterface.name();
    qDebug() << "Display Name:" << mainInterface.humanReadableName();
    qDebug() << "Hardware Address:" << mainInterface.hardwareAddress();
}
void LocalMachine::setMainInterface(QNetworkInterface interface)
{
    mainInterface = interface;

    QList<QNetworkAddressEntry> addressEntries = mainInterface.addressEntries();
    foreach (const auto &entry, addressEntries) {
        if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol) {
            ip = entry.ip().toString();
            break;
        }
    }
}
