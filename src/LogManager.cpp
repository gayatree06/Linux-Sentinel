#include "LogManager.h"

#include <fstream>
#include <ctime>

void LogManager::log(const std::string& message)
{
    std::ofstream logFile("linux_sentinel.log", std::ios::app);

    if (!logFile.is_open())
    {
        return;
    }

    std::time_t currentTime = std::time(nullptr);

    logFile << std::ctime(&currentTime)
            << " - "
            << message
            << '\n';

    logFile.close();
}
