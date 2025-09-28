#pragma once
#include <vector>
#include <cstddef>
#include <iostream>

// Simple Matrix class with template element type T
template <typename T>
class Matrix {
    std::size_t rows;
    std::size_t cols;
    std::vector<T> data;

public:
    // TODO: Constructor with rows, cols and default value
    Matrix(std::size_t r, std::size_t c, const T& val = T());

    // TODO: Access element (with bounds check skipped)
    T& operator()(std::size_t r, std::size_t c);
    const T& operator()(std::size_t r, std::size_t c) const;

    std::size_t rowCount() const;
    std::size_t colCount() const;

    // TODO: Matrix addition
    template <typename U>
    auto operator+(const Matrix<U>& other) const
        -> Matrix<decltype(std::declval<T>() + std::declval<U>())>;

    // TODO: print matrix
    void print() const;
};
