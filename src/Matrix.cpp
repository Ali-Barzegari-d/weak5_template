#include "Matrix.hpp"

// NOTE: Template definitions usually go in header.
// Here we simulate separate compilation with explicit template instantiation at the bottom.

template <typename T>
Matrix<T>::Matrix(std::size_t r, std::size_t c, const T& val)
    : rows(r), cols(c), data(r * c, val) {}

template <typename T>
T& Matrix<T>::operator()(std::size_t r, std::size_t c) {
    return data[r * cols + c];
}

template <typename T>
const T& Matrix<T>::operator()(std::size_t r, std::size_t c) const {
    return data[r * cols + c];
}

template <typename T>
std::size_t Matrix<T>::rowCount() const { return rows; }

template <typename T>
std::size_t Matrix<T>::colCount() const { return cols; }

template <typename T>
template <typename U>
auto Matrix<T>::operator+(const Matrix<U>& other) const
    -> Matrix<decltype(std::declval<T>() + std::declval<U>())>
{
    using R = decltype(std::declval<T>() + std::declval<U>());
    Matrix<R> result(rows, cols);
    for (std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < cols; j++) {
            result(i, j) = (*this)(i, j) + other(i, j);
        }
    }
    return result;
}

template <typename T>
void Matrix<T>::print() const {
    for (std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < cols; j++) {
            std::cout << (*this)(i, j) << " ";
        }
        std::cout << "\n";
    }
}

// Explicit instantiations for common types
template class Matrix<int>;
template class Matrix<double>;
template Matrix<int> Matrix<int>::operator+<int>(const Matrix<int>&) const;
template Matrix<double> Matrix<double>::operator+<double>(const Matrix<double>&) const;
template Matrix<double> Matrix<int>::operator+<double>(const Matrix<double>&) const;
