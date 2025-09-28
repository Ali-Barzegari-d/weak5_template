#include "Matrix.hpp"
#include <cassert>
#include <iostream>
#include <type_traits>

int main() {
    // Test int matrix
    Matrix<int> m1(2, 2, 1);
    Matrix<int> m2(2, 2, 2);

    auto m3 = m1 + m2;
    assert(m3(0,0) == 3 && m3(1,1) == 3);

    // Test double + int
    Matrix<double> m4(2, 2, 1.5);
    auto m5 = m1 + m4;
    static_assert(std::is_same_v<decltype(m5), Matrix<double>>,
                  "Result type should be Matrix<double>");

    assert(m5(0,0) == 2.5);

    // Test print
    std::cout << "Matrix m3:\n";
    m3.print();

    std::cout << "Matrix tests passed!\n";
    return 0;
}
