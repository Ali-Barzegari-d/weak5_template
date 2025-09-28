#include "Matrix.hpp"

// For this exercise, implement here and explicitly instantiate common types.

template <typename T>
Matrix<T>::Matrix(std::size_t r, std::size_t c, const T& val)
    : rows(r), cols(c), data(r * c, val) {
    // TODO: initialize matrix with value
}

template <typename T>
T& Matrix<T>::operator()(std::size_t r, std::size_t c) {
    // TODO: return reference to element
    return data[0]; // placeholder
}

template <typename T>
const T& Matrix<T>::operator()(std::size_t r, std::size_t c) const {
    // TODO: return const reference to element
    return data[0]; // placeholder
}

template <typename T>
std::size_t Matrix<T>::rowCount() const { return rows; }

template <typename T>
std::size_t Matrix<T>::colCount() const { return cols; }

template <typename T>
template <typename U>
auto Matrix<T>::operator+(const Matrix<U>& other) const
    -> Matrix</* TODO: deduce type with decltype */>
{
    // TODO: implement element-wise addition
    // hint: use decltype(std::declval<T>() + std::declval<U>())
    return *this; // placeholder
}

template <typename T>
void Matrix<T>::print() const {
    // TODO: print all elements row by row
}

// Explicit instantiations (students can ignore these)
template class Matrix<int>;
template class Matrix<double>;
