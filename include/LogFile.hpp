#pragma once
#include <fstream>
#include <string>

class LogFile
{
    std::ofstream file;

public:
    explicit LogFile(const std::string &filename);
    ~LogFile();
    void write(const std::string &msg);
};
