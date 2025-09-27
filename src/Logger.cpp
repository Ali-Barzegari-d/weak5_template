#include "Logger.hpp"
#include <iostream>

// TODO: Implement constructor

void Logger::setLevel(LogLevel lvl) {
    level = lvl;
}

void Logger::logMessage(LogLevel lvl, std::string_view msg) {
    // TODO: Implement logging using string_view
}

void Logger::logMessage(LogLevel lvl, const std::string& msg) {
    // TODO: Call string_view version
}

void Logger::logInfo(std::string_view msg) {
    // TODO: Call logMessage with INFO
}

void Logger::logWarning(std::string_view msg) {
    // TODO: Call logMessage with WARNING
}

void Logger::logError(std::string_view msg) {
    // TODO: Call logMessage with ERROR
}
