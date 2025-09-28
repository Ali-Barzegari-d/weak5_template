#include "SafeArray.hpp"

// For exercise purposes, implement them here and rely on explicit instantiation below.

template <typename T>
SafeArray<T>::SafeArray() = default;

template <typename T>
SafeArray<T>::~SafeArray() noexcept = default;

template <typename T>
void SafeArray<T>::push_back(const T& value) {
    // TODO: implement push_back (std::vector already gives strong guarantee)
    data.push_back(value);
}

template <typename T>
T& SafeArray<T>::at_exception(std::size_t idx) {
    // TODO: check bounds, throw if invalid
    return data[0]; // placeholder
}

template <typename T>
const T& SafeArray<T>::at_exception(std::size_t idx) const {
    // TODO: check bounds, throw if invalid
    return data[0]; // placeholder
}

template <typename T>
ErrorCode SafeArray<T>::at_status(std::size_t idx, T& out) const {
    // TODO: check bounds, return SUCCESS or OUT_OF_BOUNDS
    return ErrorCode::SUCCESS; // placeholder
}

template <typename T>
std::size_t SafeArray<T>::size() const noexcept {
    return data.size();
}

// Explicit instantiation for int (used in tests)
template class SafeArray<int>;
