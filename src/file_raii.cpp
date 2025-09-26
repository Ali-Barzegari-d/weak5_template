#include "file_raii.hpp"
#include <stdexcept> // for runtime_error

// Constructor: open the file
FileRAII::FileRAII(const std::string& filename, const std::string& mode) {
    // TODO: open file (student needs to use std::fopen here)
    handle_ = std::fopen(filename.c_str(), mode.c_str());  // Opening the file
    if (handle_ == nullptr) {
        throw std::runtime_error("Failed to open file");
    }
}

// Move constructor: transfer ownership of file handle
FileRAII::FileRAII(FileRAII&& other) noexcept
    : handle_(other.handle_) {
    other.handle_ = nullptr; // Nullify the other handle
}

// Move assignment operator
FileRAII& FileRAII::operator=(FileRAII&& other) noexcept {
    if (this != &other) {
        if (handle_) {
            std::fclose(handle_);
        }
        handle_ = other.handle_;
        other.handle_ = nullptr;
    }
    return *this;
}

// Destructor: close the file if it's open
FileRAII::~FileRAII() {
    if (handle_) {
        std::fclose(handle_); // Closing the file in the destructor
    }
}

// Method to check if the file handle is valid (open)
bool FileRAII::valid() const {
    // TODO: Check if the file handle is valid (return true if file is open)
    return handle_ != nullptr; // Return true if the file is open
}

// Get the raw file pointer
FILE* FileRAII::get() const {
    return handle_; // Return the raw file pointer
}
