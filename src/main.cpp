#include "SystemMonitor.h"
#include "LinuxSystem.h"
#include <iostream>

int main()
{
    std::cout << "=====================================\n";
    std::cout << "        LINUX SENTINEL\n";
    std::cout << " System & Device Health Monitoring\n";
    std::cout << "=====================================\n";

    std::cout << "Linux Sentinel prototype started.\n\n";

    SystemMonitor systemMonitor;

    std::cout << "CPU Information:\n";
    std::cout << systemMonitor.getCpuInfo();
    std::cout << "\nMemory Information:\n";
    std::cout << systemMonitor.getMemoryInfo();
    std::cout << "\nStorage Information:\n";
    std::cout << systemMonitor.getStorageInfo();
    std::cout << "\nProcess Information:\n";
    std::cout << systemMonitor.getProcessInfo();
    
    LinuxSystem linuxSystem;

    std::cout << "\nLinux System Information:\n";
    std::cout << linuxSystem.readSystemFile("/proc/uptime");

    return 0;
}
