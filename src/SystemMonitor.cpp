#include "SystemMonitor.h"

#include <fstream>
#include <sstream>
#include <filesystem>
#include <cctype>
#include <sys/statvfs.h>

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

std::string SystemMonitor::getStorageInfo()
{
    struct statvfs fileSystemInfo;

    if (statvfs("/", &fileSystemInfo) != 0)
    {
        return "Unable to read storage information.";
    }

    const unsigned long long blockSize = fileSystemInfo.f_frsize;

    const unsigned long long totalSpace =
        fileSystemInfo.f_blocks * blockSize;

    const unsigned long long availableSpace =
        fileSystemInfo.f_bavail * blockSize;

    const unsigned long long usedSpace =
        totalSpace - (fileSystemInfo.f_bfree * blockSize);

    const unsigned long long totalGB =
        totalSpace / (1024ULL * 1024ULL * 1024ULL);

    const unsigned long long usedGB =
        usedSpace / (1024ULL * 1024ULL * 1024ULL);

    const unsigned long long availableGB =
        availableSpace / (1024ULL * 1024ULL * 1024ULL);

    std::ostringstream storageInfo;

    storageInfo << "Total Storage: " << totalGB << " GB\n";
    storageInfo << "Used Storage: " << usedGB << " GB\n";
    storageInfo << "Available Storage: " << availableGB << " GB\n";

    return storageInfo.str();
}


std::string SystemMonitor::getProcessInfo()
{
    int processCount = 0;

    for (const auto& entry : std::filesystem::directory_iterator("/proc"))
    {
        std::string name = entry.path().filename().string();

        if (!name.empty())
        {
            bool isProcessDirectory = true;

            for (char character : name)
            {
                if (!std::isdigit(static_cast<unsigned char>(character)))
                {
                    isProcessDirectory = false;
                    break;
                }
            }

            if (isProcessDirectory)
            {
                processCount++;
            }
        }
    }

    std::ostringstream processInfo;
    processInfo << "Running Processes: " << processCount << '\n';

    return processInfo.str();
}
