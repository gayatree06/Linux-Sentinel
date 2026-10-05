#include "NetworkManager.h"

#include <iostream>

int main()
{
    NetworkManager networkManager;

    std::string response =
        networkManager.connectToServer("127.0.0.1", 8080);

    if (response == "CONNECTION_FAILED" ||
        response == "SOCKET_ERROR" ||
        response == "INVALID_ADDRESS" ||
        response == "NO_RESPONSE")
    {
        std::cout << "TCP client connection failed: "
                  << response << '\n';
    }
    else
    {
        std::cout << "TCP client connected successfully.\n";
        std::cout << "Server Response: " << response << '\n';
    }

    return 0;
}
