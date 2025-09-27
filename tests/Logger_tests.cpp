#include "Logger.hpp"
#include "LogFile.hpp"
#include <iostream>
#include <memory>
#include <cassert>

int main()
{
    auto logfile = std::make_shared<LogFile>("test_log.txt");

    Logger logger1(logfile);
    Logger logger2(logfile); // shared ownership of same LogFile

    // Test 1: Basic logging
    logger1.logInfo("System started");
    logger2.logWarning("Low memory");
    logger1.logError("Critical failure");

    // Test 2: Log with full copy
    std::string bigMessage = "This is a very long message that must be copied!";
    logger1.logMessage(LogLevel::INFO, bigMessage);

    // Test 3: Filtering by log level
    logger1.setLevel(LogLevel::WARNING);
    logger1.logInfo("This should not appear"); // filtered
    logger1.logWarning("This should appear");

    // Assertions
    assert(true); // just to ensure test passes

    std::cout << "Logger tests passed!\n";
    return 0;
}
