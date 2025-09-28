#pragma once
#include <cstddef>
#include <stdexcept>
#include <vector>

// Error codes for status-based access
enum class ErrorCode { SUCCESS, OUT_OF_BOUNDS };

template <typename T>
class SafeArray {
    std::vector<T> data;

public:
    // default constructor
    SafeArray();

    // noexcept destructor
    ~SafeArray() noexcept;

    // push_back with strong exception guarantee
    void push_back(const T& value);

    // --- Exception-based access ---
    T& at_exception(std::size_t idx);
    const T& at_exception(std::size_t idx) const;

    // --- Status-code-based access ---
    ErrorCode at_status(std::size_t idx, T& out) const;

    // size() marked noexcept
    std::size_t size() const noexcept;
};
