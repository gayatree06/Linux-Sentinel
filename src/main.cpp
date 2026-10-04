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

    return 0;
}
