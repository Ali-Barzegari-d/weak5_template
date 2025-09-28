#pragma once
#include <cstddef>
#include <stdexcept>
#include <vector>

// Error codes for status-based access
enum class ErrorCode
{
    SUCCESS,
    OUT_OF_BOUNDS
};

template <typename T>
class SafeArray
{
    std::vector<T> data;

public:
    SafeArray();

    ~SafeArray() noexcept;

    void push_back(const T &value);

    // --- Exception-based access ---

    T &at_exception(std::size_t idx);
    const T &at_exception(std::size_t idx) const;

    // --- Status-code-based access ---

    // otherwise return OUT_OF_BOUNDS
    ErrorCode at_status(std::size_t idx, T &out) const;

    std::size_t size() const noexcept;
};
