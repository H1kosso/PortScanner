#include "LocalMachine.h"

LocalMachine::LocalMachine() {
    ip_address = boost::asio::ip::address::from_string(findLocalMachineIPAddress());
}

std::string LocalMachine::findLocalMachineIPAddress() {
    try {
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::resolver resolver(io_service);
        boost::asio::ip::tcp::resolver::query query(boost::asio::ip::host_name(), "");
        boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(query);

        while (it != boost::asio::ip::tcp::resolver::iterator()) {
            boost::asio::ip::tcp::endpoint endpoint = *it++;
            if (endpoint.address().is_v4()) {
                return endpoint.address().to_string();
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return "";
}


