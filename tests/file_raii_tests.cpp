#include <cassert>
#include <iostream>
#include "file_raii.hpp"

int main() {
    // Test 1: Create a FileRAII object, write to the file, and check validity
    {
        FileRAII f("test_output.txt", "w"); // Open file for writing
        assert(f.valid()); // Check if file is open

        FILE* raw = f.get(); // Get the raw file pointer
        assert(raw != nullptr); // Ensure file pointer is valid

        // Write something to the file
        const char* msg = "Hello RAII\n";
        std::fputs(msg, raw); // Write message to file
    } // At the end of the scope, f goes out of scope -> file should be closed automatically

    // Test 2: Reopen the file to check the content
    {
        FILE* check = std::fopen("test_output.txt", "r"); // Open file for reading
        assert(check != nullptr); // Check if the file was opened successfully

        char buffer[64];
        char* ok = std::fgets(buffer, sizeof(buffer), check); // Read the file content
        assert(ok != nullptr); // Check if read was successful
        assert(std::string(buffer) == "Hello RAII\n"); // Verify the content

        std::fclose(check); // Close the file
    }

    // Test 3: Use move constructor to transfer ownership of the file
    {
        FileRAII f1("test_output.txt", "r"); // Open file for reading
        FileRAII f2 = std::move(f1); // Move f1 into f2

        assert(!f1.valid()); // f1 should be invalid after move
        assert(f2.valid()); // f2 should be valid after move
    }

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
