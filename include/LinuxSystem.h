#ifndef LINUX_SYSTEM_H
#define LINUX_SYSTEM_H

#include <string>

class LinuxSystem
{
public:
    std::string readSystemFile(const std::string& filePath);
};

#endif
