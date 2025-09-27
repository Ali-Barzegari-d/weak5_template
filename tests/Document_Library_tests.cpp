#include "Document.hpp"
#include "Library.hpp"
#include <iostream>
#include <cassert>

int main() {
    // Test 1: Create Document with copy
    Document d1(/* TODO: constructor from string */);

    // Test 2: Create Document with view
    std::string external = "External Text";
    Document d2(/* TODO: constructor from external string& */);

    // Test 3: Create Document with ownership (unique_ptr)
    auto ptr = std::make_unique<std::string>("Owned Text");
    Document d3(/* TODO: constructor from unique_ptr */);

    // Create library
    Library lib;
    lib.addDocument(std::make_shared<Document>(d1));
    lib.addDocument(std::make_shared<Document>(d2));
    lib.addDocument(std::make_shared<Document>(d3));

    // Test 4: Search
    auto found = lib.findByName("Doc2");
    if (found) {
        std::cout << "Found: " << (*found)->getView() << "\n";
    }

    // Test 5: Print all
    lib.printAll();

    // Basic asserts
    assert(d1.getName().size() > 0);
    assert(d2.getName().size() > 0);

    std::cout << "All tests passed!\n";
    return 0;
}
