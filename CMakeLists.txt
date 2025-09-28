cmake_minimum_required(VERSION 3.12)
project(csi2372_assignments LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# === Task A: Document & Library ===
add_library(document_lib
    src/Document.cpp
    src/Library.cpp
)
target_include_directories(document_lib PUBLIC include)

add_executable(document_tests tests/Document_Library_tests.cpp)
target_link_libraries(document_tests PRIVATE document_lib)
add_test(NAME document_tests COMMAND $<TARGET_FILE:document_tests>)

# === Task B: Logger (LogFile & Logger) ===
add_library(logger_lib
    src/LogFile.cpp
    src/Logger.cpp
)
target_include_directories(logger_lib PUBLIC include)

add_executable(logger_tests tests/Logger_tests.cpp)
target_link_libraries(logger_tests PRIVATE logger_lib)
add_test(NAME logger_tests COMMAND $<TARGET_FILE:logger_tests>)

# === Task C: Matrix ===
add_library(matrix_lib
    src/Matrix.cpp
)
target_include_directories(matrix_lib PUBLIC include)

add_executable(matrix_tests tests/Matrix_tests.cpp)
target_link_libraries(matrix_tests PRIVATE matrix_lib)
add_test(NAME matrix_tests COMMAND $<TARGET_FILE:matrix_tests>)

# === Task D: SafeArray ===
add_library(SafeArray_lib
    src/SafeArray.cpp
)
target_include_directories(SafeArray_lib PUBLIC include)

add_executable(SafeArray_tests tests/SafeArray_tests.cpp)
target_link_libraries(SafeArray_tests PRIVATE SafeArray_lib)
add_test(NAME SafeArray_tests COMMAND $<TARGET_FILE:SafeArray_tests>)

# === Enable CTest ===
include(CTest)
