#include "Document.hpp"
#include "Library.hpp"
#include <iostream>
#include <cassert>

int main() {
    // Test 1: Create Document with copy
    Document d1("Doc1", std::string("Hello world"));
    assert(d1.getView() == "Hello world");

    // Test 2: Create Document with view
    std::string external = "External Text";
    Document d2("Doc2", external);
    assert(d2.getView() == "External Text");

    // Test 3: Create Document with ownership (unique_ptr)
    auto ptr = std::make_unique<std::string>("Owned Text");
    Document d3("Doc3", std::move(ptr));
    assert(d3.getView() == "Owned Text");

    // Create library
    Library lib;
    lib.addDocument(std::make_shared<Document>(d1));
    lib.addDocument(std::make_shared<Document>(d2));
    lib.addDocument(std::make_shared<Document>(d3));

    // Test 4: Search
    auto found = lib.findByName("Doc2");
    if (found) {
        std::cout << "Found: " << (*found)->getView() << "\n";
        assert((*found)->getView() == "External Text");
    }

    // Test 5: Print all
    lib.printAll();

    // Test 6: Update owned content
    d1.updateContent("Updated Hello");
    assert(d1.getView() == "Updated Hello");

    // Test 7: Try update view-only document
    d2.updateContent("Should fail"); // just prints error

    std::cout << "All tests passed!\n";
    return 0;
}
