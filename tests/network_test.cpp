#include "NetworkManager.h"

#include <iostream>

int main()
{
    NetworkManager networkManager;

    if (networkManager.startServer(8080))
    {
        std::cout << "TCP server started successfully.\n";
    }
    else
    {
        std::cout << "Failed to start TCP server.\n";
    }

    return 0;
}
