#include "SafeArray.hpp"

// Here we implement them in cpp for exercise purposes.

template <typename T>
SafeArray<T>::SafeArray() = default;

template <typename T>
SafeArray<T>::~SafeArray() noexcept = default;

template <typename T>
void SafeArray<T>::push_back(const T& value) {
    // std::vector already provides strong exception guarantee
    data.push_back(value);
}

template <typename T>
T& SafeArray<T>::at_exception(std::size_t idx) {
    if (idx >= data.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[idx];
}

template <typename T>
const T& SafeArray<T>::at_exception(std::size_t idx) const {
    if (idx >= data.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[idx];
}

template <typename T>
ErrorCode SafeArray<T>::at_status(std::size_t idx, T& out) const {
    if (idx >= data.size()) {
        return ErrorCode::OUT_OF_BOUNDS;
    }
    out = data[idx];
    return ErrorCode::SUCCESS;
}

template <typename T>
std::size_t SafeArray<T>::size() const noexcept {
    return data.size();
}

// Explicit instantiation for int (used in tests)
template class SafeArray<int>;
