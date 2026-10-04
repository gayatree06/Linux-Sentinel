#include "SystemMonitor.h"

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
    
    return 0;
}
