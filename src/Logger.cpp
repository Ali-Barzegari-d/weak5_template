#include "Logger.hpp"
#include <iostream>

Logger::Logger(std::shared_ptr<LogFile> lf)
    : logfile(std::move(lf)), level(LogLevel::INFO) {}

void Logger::setLevel(LogLevel lvl) {
    level = lvl;
}

void Logger::logMessage(LogLevel lvl, std::string_view msg) {
    if (lvl < level) return;

    std::string prefix;
    switch (lvl) {
        case LogLevel::INFO: prefix = "[INFO] "; break;
        case LogLevel::WARNING: prefix = "[WARNING] "; break;
        case LogLevel::ERROR: prefix = "[ERROR] "; break;
    }

    logfile->write(prefix + std::string(msg));
}

void Logger::logMessage(LogLevel lvl, const std::string& msg) {
    logMessage(lvl, std::string_view(msg));
}

void Logger::logInfo(std::string_view msg) {
    logMessage(LogLevel::INFO, msg);
}

void Logger::logWarning(std::string_view msg) {
    logMessage(LogLevel::WARNING, msg);
}

void Logger::logError(std::string_view msg) {
    logMessage(LogLevel::ERROR, msg);
}
