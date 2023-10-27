#ifndef PORTSCANNER_SUBNETSCANNER_H
#define PORTSCANNER_SUBNETSCANNER_H

#include "../Headers.h"

class SubnetScanner {
public:
    SubnetScanner(std::string subnet, unsigned int port, unsigned int startAddress, unsigned int endAddress);
    std::vector<boost::asio::ip::address> getAddresses() { return m_addresses; };
    void scanSubnet();
private:
    std::vector<boost::asio::ip::address> m_addresses;
    std::string m_subnet;
    unsigned int m_port;
    unsigned int m_startAddress;
    unsigned int m_endAddress;
    void scanAddress(const std::string &address, int port);
};


#endif //PORTSCANNER_SUBNETSCANNER_H
