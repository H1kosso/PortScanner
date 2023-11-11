#ifndef LOCALMACHINE_H
#define LOCALMACHINE_H

#include <QNetworkAddressEntry>
#include <QNetworkInterface>
#include <QString>
class LocalMachine
{
public:
    QNetworkInterface mainInterface;
    QList<QNetworkInterface> interfaces;
    QString ip;

    LocalMachine();
    void printAllInterfaces() const;
    void printMainInterface() const;
    void setMainInterface(QNetworkInterface interface);

private:
};

#endif // LOCALMACHINE_H
