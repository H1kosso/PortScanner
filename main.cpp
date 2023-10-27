#include "Headers.h"





int main() {

    LocalMachine localMachine;
    std::cout << localMachine.getLocalIPAddress() << std::endl;

    SubnetScanner subnetScanner("192.168.0", 80, 1, 2);
    subnetScanner.scanSubnet();
    std::vector<boost::asio::ip::address> addresses = subnetScanner.getAddresses();
    for (auto &address : addresses) {
        std::cout << address.to_string() << std::endl;
    }
    std::cout << addresses.size() << std::endl;
    return 0;
}
