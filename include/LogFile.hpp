#pragma once
#include <fstream>
#include <string>

class LogFile {
    std::ofstream file;

public:
    // Constructor opens file with RAII
    explicit LogFile(const std::string& filename);

    // Destructor closes file automatically
    ~LogFile();

    // Write a line to file
    void write(const std::string& msg);
};
