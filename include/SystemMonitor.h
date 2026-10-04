#ifndef SYSTEM_MONITOR_H
#define SYSTEM_MONITOR_H

#include <string>

class SystemMonitor
{
public:
    std::string getCpuInfo();
    std::string getMemoryInfo();
    std::string getStorageInfo();
    std::string getProcessInfo();
}; 

#endif
