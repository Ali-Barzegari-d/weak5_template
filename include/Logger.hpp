#pragma once
#include "LogFile.hpp"
#include <memory>
#include <string>
#include <string_view>

enum class LogLevel { INFO, WARNING, ERROR };

class Logger {
    std::shared_ptr<LogFile> logfile;
    LogLevel level;

public:
    Logger(std::shared_ptr<LogFile> lf);

    void setLevel(LogLevel lvl);
    void logMessage(LogLevel lvl, std::string_view msg);
    void logMessage(LogLevel lvl, const std::string& msg);

    void logInfo(std::string_view msg);
    void logWarning(std::string_view msg);
    void logError(std::string_view msg);
};
