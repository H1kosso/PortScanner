////
//// Created by Marcin on 27.10.2023.
////
//
#include "SubnetScanner.h"
//
#include <utility>


SubnetScanner::SubnetScanner(std::string subnet, unsigned int port, unsigned int startAddress, unsigned int endAddress)
        : m_subnet(std::move(std::move(subnet))), m_port(port), m_startAddress(startAddress),
          m_endAddress(endAddress) {}

void SubnetScanner::scanSubnet() {
    boost::asio::io_context io_context;
    for (auto i = m_startAddress; i <= m_endAddress; ++i) {
        std::string currentAddress = std::string(m_subnet) + "." + std::to_string(i);
        scanAddress(currentAddress, m_port);
    }
}


void SubnetScanner::scanAddress(const std::string &address, int port) {
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::endpoint endpoint(
            boost::asio::ip::address::from_string(address), port);
    boost::asio::ip::tcp::socket socket(io_context);

    try {
        socket.connect(endpoint);
        m_addresses.push_back(endpoint.address());
        std::cout << "Znaleziono urzadzenie na adresie: " << endpoint.address().to_string() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Adres jest niedostepny: " << endpoint.address().to_string() << " - " << e.what() << std::endl;
    }
}

