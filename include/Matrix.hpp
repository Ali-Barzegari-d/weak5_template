#pragma once
#include <vector>
#include <cstddef>
#include <iostream>
#include <utility>

// Simple Matrix class with template element type T
template <typename T>
class Matrix
{
    std::size_t rows;
    std::size_t cols;
    std::vector<T> data;

public:
    Matrix(std::size_t r, std::size_t c, const T &val = T());

    T &operator()(std::size_t r, std::size_t c);
    const T &operator()(std::size_t r, std::size_t c) const;

    std::size_t rowCount() const;
    std::size_t colCount() const;

    template <typename U>
    auto operator+(const Matrix<U> &other) const
        -> Matrix</* TODO: use decltype(...) here */>;

    void print() const;
};
