#include "LogFile.hpp"
#include <iostream>
#include <stdexcept>

LogFile::LogFile(const std::string& filename) {
    file.open(filename, std::ios::out | std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open log file: " + filename);
    }
}

LogFile::~LogFile() {
    if (file.is_open()) {
        file.close();
    }
}

void LogFile::write(const std::string& msg) {
    if (file.is_open()) {
        file << msg << std::endl;
    }
}
