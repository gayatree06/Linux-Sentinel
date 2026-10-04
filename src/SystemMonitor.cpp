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
