#ifndef PORTSCANNER_LOCALMACHINE_H
#define PORTSCANNER_LOCALMACHINE_H

#include "../Headers.h"

class LocalMachine {
public:
    LocalMachine();

    std::string getLocalIPAddress() { return m_ip_address.to_string(); };
private:
    boost::asio::ip::address m_ip_address;
private:
    static std::string findLocalMachineIPAddress();
};


#endif //PORTSCANNER_LOCALMACHINE_H
