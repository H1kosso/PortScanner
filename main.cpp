#include "Headers.h"





int main() {

    LocalMachine localMachine;
    std::cout << localMachine.getLocalIPAddress() << std::endl;

    SubnetScanner subnetScanner("192.168.0", 80, 1, 150);
    // Start scanning in a separate thread
    std::thread scanningThread([&]() {
        subnetScanner.scanSubnet();
    });

    // Do other work or wait for scanning to finish
    // ...`

    scanningThread.join();  // Wait for the scanning to complete

    std::vector<boost::asio::ip::address> addresses = subnetScanner.getAddresses();
    for (auto &address : addresses) {
        std::cout << address.to_string() << std::endl;
    }
    std::cout << addresses.size() << " devices found." << std::endl;

    return 0;
}

//int main() {
//
//    LocalMachine localMachine;
//    std::cout << localMachine.getLocalIPAddress() << std::endl;
//
//    SubnetScanner subnetScanner("192.168.0", 80, 1, 20);
//    subnetScanner.scanSubnet();
//    std::vector<boost::asio::ip::address> addresses = subnetScanner.getAddresses();
//    for (auto &address : addresses) {
//        std::cout << address.to_string() << std::endl;
//    }
//    std::cout << addresses.size() << std::endl;
//    return 0;
//}