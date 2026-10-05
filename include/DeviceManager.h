#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include <string>

class DeviceManager
{
public:
    ~DeviceManager();

    bool openDevice();
    std::string readStatus();
    bool sendCommand(const std::string& command);
    void closeDevice();

private:
    int deviceFileDescriptor = -1;
};

#endif
