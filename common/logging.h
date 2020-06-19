#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

//TODO: Improve logging. E.g. This solution is not threadsafe
namespace Snake {
namespace Logging {

static const std::string LOG_FILE_NAME = "snake_log.txt";
static std::ofstream logFile(LOG_FILE_NAME);

enum LogType {INFO, WARNING, ERROR};

static std::map<LogType, std::string> enumMap {
    {LogType::INFO,     "INFO"},
    {LogType::WARNING,  "WARNING"},
    {LogType::ERROR,    "ERROR"},
};

std::string GetTimeStamp() {
    std::stringstream ss;

    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    ss << now->tm_hour;
    ss << ":";
    ss << now->tm_min;
    ss << ":";
    ss << now->tm_sec;

    return ss.str();
}

void WriteLogFile(LogType type, std::string message) {
    logFile << "(" << enumMap[type] << ") "
            << "[" << GetTimeStamp() << "] "
            << message << std::endl;
}

void Log(std::string logMessage) {
    WriteLogFile(LogType::INFO, logMessage);
}

void Warning(std::string warningMessage) {
    WriteLogFile(LogType::WARNING, warningMessage);
}

void Error(std::string errorMessage) {
    WriteLogFile(LogType::ERROR, errorMessage);
}

} // ns Logging
} // ns Snake
