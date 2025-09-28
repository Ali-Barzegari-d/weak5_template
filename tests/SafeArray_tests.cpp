#include "SafeArray.hpp"
#include <cassert>
#include <iostream>

int main() {
    SafeArray<int> arr;
    arr.push_back(10);
    arr.push_back(20);

    // --- exception access ---
    assert(arr.at_exception(0) == 10);
    try {
        arr.at_exception(5);
        assert(false && "Should throw out_of_range");
    } catch (const std::out_of_range&) {
        // expected
    }

    // --- status code access ---
    int val = 0;
    auto res1 = arr.at_status(1, val);
    assert(res1 == ErrorCode::SUCCESS && val == 20);

    auto res2 = arr.at_status(9, val);
    assert(res2 == ErrorCode::OUT_OF_BOUNDS);

    std::cout << "All SafeArray tests passed!\n";
    return 0;
}
