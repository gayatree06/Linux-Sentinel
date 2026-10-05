#include "NetworkManager.h"

#include <arpa/inet.h>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

bool NetworkManager::startServer(int port)
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == -1)
    {
        return false;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    if (bind(serverSocket,
             reinterpret_cast<sockaddr*>(&serverAddress),
             sizeof(serverAddress)) == -1)
    {
        close(serverSocket);
        return false;
    }

    if (listen(serverSocket, 1) == -1)
    {
        close(serverSocket);
        return false;
    }

    int clientSocket = accept(serverSocket, nullptr, nullptr);

    if (clientSocket == -1)
    {
        close(serverSocket);
        return false;
    }

    const char* response = "DEVICE_OK";

ssize_t bytesSent =
    send(clientSocket,
         response,
         std::strlen(response),
         0);

if (bytesSent == -1)
{
    close(clientSocket);
    close(serverSocket);
    return false;
}

close(clientSocket);
    close(serverSocket);

    return true;
}

std::string NetworkManager::connectToServer(
    const std::string& serverAddress,
    int port)
{
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSocket == -1)
    {
        return "SOCKET_ERROR";
    }

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_port = htons(port);

    if (inet_pton(AF_INET,
                  serverAddress.c_str(),
                  &address.sin_addr) <= 0)
    {
        close(clientSocket);
        return "INVALID_ADDRESS";
    }

    if (connect(clientSocket,
                reinterpret_cast<sockaddr*>(&address),
                sizeof(address)) != 0)
    {
        close(clientSocket);
        return "CONNECTION_FAILED";
    }

    char buffer[1024]{};

    ssize_t bytesRead = recv(clientSocket,
                             buffer,
                             sizeof(buffer) - 1,
                             0);

    close(clientSocket);

    if (bytesRead <= 0)
    {
        return "NO_RESPONSE";
    }

    buffer[bytesRead] = '\0';

    return std::string(buffer);
}
