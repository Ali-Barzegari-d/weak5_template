#pragma once
#include "Document.hpp"
#include <memory>
#include <vector>
#include <optional>

class Library {
    std::vector<std::shared_ptr<Document>> docs;

public:
    void addDocument(std::shared_ptr<Document> doc);

    // TODO: Implement search by name
    std::optional<std::shared_ptr<Document>> findByName(const std::string& name);

    // TODO: Print all documents (using view)
    void printAll() const;
};
