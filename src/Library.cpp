#include "Library.hpp"
#include <iostream>

void Library::addDocument(std::shared_ptr<Document> doc) {
    docs.push_back(std::move(doc));
}

std::optional<std::shared_ptr<Document>> Library::findByName(const std::string& name) {
    // TODO: Search by name and return document
    return std::nullopt;
}

void Library::printAll() const {
    // TODO: Iterate over all documents and print their view
}
