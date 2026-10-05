#include "SystemMonitor.h"
#include "LinuxSystem.h"
#include "DeviceManager.h"
#include "LogManager.h"

#include <iostream>
#include <string>

void displaySystemHealth(SystemMonitor& systemMonitor,
                         LogManager& logManager)
{
    std::cout << "\n========== SYSTEM HEALTH ==========\n";

    std::cout << "\nCPU Information:\n";
    std::cout << systemMonitor.getCpuInfo();

    std::cout << "\nMemory Information:\n";
    std::cout << systemMonitor.getMemoryInfo();

    std::cout << "\nStorage Information:\n";
    std::cout << systemMonitor.getStorageInfo();

    std::cout << "\nProcess Information:\n";
    std::cout << systemMonitor.getProcessInfo();

    logManager.log("System health information viewed.");
}

void displayDeviceStatus(DeviceManager& deviceManager,
                         LogManager& logManager)
{
    std::cout << "\n========== DEVICE STATUS ==========\n";

    if (deviceManager.openDevice())
    {
        std::cout << "Device Status:\n";
        std::cout << deviceManager.readStatus();

        deviceManager.closeDevice();

        logManager.log("Device status viewed.");
    }
    else
    {
        std::cout << "Linux Sentinel device is currently unavailable.\n";

        logManager.log(
            "Device status requested but driver is unavailable.");
    }
}

void displayNetworkStatus(LogManager& logManager)
{
    std::cout << "\n========== NETWORK STATUS ==========\n";
    std::cout << "TCP/IP networking module is available.\n";
    std::cout << "Default test server port: 8080\n";
    std::cout << "Local test address: 127.0.0.1\n";

    logManager.log("Network status viewed.");
}

void displayLogs()
{
    std::cout << "\n========== LOG INFORMATION ==========\n";
    std::cout << "Log file: linux_sentinel.log\n";
    std::cout << "Use 'cat linux_sentinel.log' in the terminal "
                 "to view complete logs.\n";
}

int main()
{
    std::cout << "=====================================\n";
    std::cout << "        LINUX SENTINEL\n";
    std::cout << " System & Device Health Monitoring\n";
    std::cout << "=====================================\n";

    std::cout << "Linux Sentinel started successfully.\n";

    SystemMonitor systemMonitor;
    DeviceManager deviceManager;
    LogManager logManager;

    logManager.log("Linux Sentinel application started.");

    int choice = 0;

    while (choice != 5)
    {
        std::cout << "\n=====================================\n";
        std::cout << "          MAIN MENU\n";
        std::cout << "=====================================\n";
        std::cout << "1. System Health\n";
        std::cout << "2. Device Status\n";
        std::cout << "3. Network Status\n";
        std::cout << "4. View Logs\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        switch (choice)
        {
            case 1:
                displaySystemHealth(systemMonitor, logManager);
                break;

            case 2:
                displayDeviceStatus(deviceManager, logManager);
                break;

            case 3:
                displayNetworkStatus(logManager);
                break;

            case 4:
                displayLogs();
                break;

            case 5:
                logManager.log("Linux Sentinel application exited.");
                std::cout << "\nExiting Linux Sentinel.\n";
                break;

            default:
                std::cout << "\nInvalid choice. Please select 1-5.\n";
                logManager.log("Invalid menu option selected.");
                break;
        }
    }

    return 0;
}
