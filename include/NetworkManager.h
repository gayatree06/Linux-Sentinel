#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <string>

class NetworkManager
{
public:
    bool startServer(int port);
    std::string connectToServer(const std::string& serverAddress, int port);
};

#endif
