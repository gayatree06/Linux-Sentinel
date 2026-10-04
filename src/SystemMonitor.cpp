#include "SystemMonitor.h"

#include <fstream>
#include <sstream>

std::string SystemMonitor::getCpuInfo()
{
    std::ifstream cpuFile("/proc/cpuinfo");

    if (!cpuFile.is_open())
    {
        return "Unable to read CPU information.";
    }

    std::string line;
    std::ostringstream cpuInfo;

    while (std::getline(cpuFile, line))
    {
        if (line.find("model name") == 0)
        {
            cpuInfo << line << '\n';
            break;
        }
    }

    cpuFile.close();

    if (cpuInfo.str().empty())
    {
        return "CPU information not available.";
    }

    return cpuInfo.str();
}

std::string SystemMonitor::getMemoryInfo()
{
    std::ifstream memoryFile("/proc/meminfo");

    if (!memoryFile.is_open())
    {
        return "Unable to read memory information.";
    }

    std::string line;
    std::ostringstream memoryInfo;

    while (std::getline(memoryFile, line))
    {
        if (line.find("MemTotal:") == 0 ||
            line.find("MemAvailable:") == 0)
        {
            memoryInfo << line << '\n';
        }
    }

    memoryFile.close();

    if (memoryInfo.str().empty())
    {
        return "Memory information not available.";
    }

    return memoryInfo.str();
}
