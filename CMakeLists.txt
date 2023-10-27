cmake_minimum_required(VERSION 3.26)
project(PortScanner)

set(CMAKE_CXX_STANDARD 20)
add_executable(PortScanner main.cpp
        LocalMachine/LocalMachine.cpp
        LocalMachine/LocalMachine.h
        Headers.h
)

# WinSock (ws2_32)
if (WIN32)
    find_library(WS2_32_LIBRARY ws2_32)
    if (WS2_32_LIBRARY)
        target_link_libraries(PortScanner PRIVATE ${WS2_32_LIBRARY}  -lwsock32)

    else ()
        message(FATAL_ERROR "WinSock not found.")
    endif ()
endif ()


# Boost
find_package(Boost REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(PortScanner PRIVATE ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR "Boost not found.")
endif()



# Asio
find_package(Asio REQUIRED)
if (Asio_FOUND)
    target_link_libraries(PortScanner PRIVATE asio)
else ()
    message(FATAL_ERROR "Asio not found.")
endif ()

