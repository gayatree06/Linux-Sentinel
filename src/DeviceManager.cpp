#include "DeviceManager.h"

#include <fcntl.h>
#include <unistd.h>

DeviceManager::~DeviceManager()
{
    closeDevice();
}

bool DeviceManager::openDevice()
{
    deviceFileDescriptor = open("/dev/linux_sentinel", O_RDWR);

    return deviceFileDescriptor != -1;
}

std::string DeviceManager::readStatus()
{
    if (deviceFileDescriptor == -1)
    {
        return "DEVICE_NOT_AVAILABLE";
    }

    char buffer[128]{};

    ssize_t bytesRead =
        read(deviceFileDescriptor, buffer, sizeof(buffer) - 1);

    if (bytesRead <= 0)
    {
        return "READ_FAILED";
    }

    buffer[bytesRead] = '\0';

    return std::string(buffer);
}

bool DeviceManager::sendCommand(const std::string& command)
{
    if (deviceFileDescriptor == -1)
    {
        return false;
    }

    ssize_t bytesWritten =
        write(deviceFileDescriptor,
              command.c_str(),
              command.length());

    return bytesWritten ==
           static_cast<ssize_t>(command.length());
}

void DeviceManager::closeDevice()
{
    if (deviceFileDescriptor != -1)
    {
        close(deviceFileDescriptor);
        deviceFileDescriptor = -1;
    }
}
