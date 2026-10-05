#include "LinuxSystem.h"

#include <fcntl.h>
#include <unistd.h>

std::string LinuxSystem::readSystemFile(const std::string& filePath)
{
    int fileDescriptor = open(filePath.c_str(), O_RDONLY);

    if (fileDescriptor == -1)
    {
        return "Unable to open system file.\n";
    }

    char buffer[4096];
    ssize_t bytesRead = read(fileDescriptor, buffer, sizeof(buffer) - 1);

    close(fileDescriptor);

    if (bytesRead == -1)
    {
        return "Unable to read system file.\n";
    }

    buffer[bytesRead] = '\0';

    return std::string(buffer);
}
