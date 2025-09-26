#pragma once
#include <string>
#include <cstdio>

// Task: Implement RAII wrapper for FILE*

class FileRAII {
public:
    // Constructor: open file with given name and mode
    FileRAII(const std::string& filename, const std::string& mode);

    // No copy allowed
    FileRAII(const FileRAII&) = delete;
    FileRAII& operator=(const FileRAII&) = delete;

    // Move constructor and move assignment operator
    FileRAII(FileRAII&& other) noexcept;
    FileRAII& operator=(FileRAII&& other) noexcept;

    // Destructor: close file if open
    ~FileRAII();

    // Method to check if file is valid (open)
    bool valid() const;

    // Expose FILE* for minimal usage (optional)
    FILE* get() const;

private:
    FILE* handle_{nullptr}; // File handle (initialized to nullptr)
};
