#pragma once
#include "Document.hpp"
#include <memory>
#include <vector>
#include <optional>
#include <iostream>

class Library
{
    std::vector<std::shared_ptr<Document>> docs;

public:
    void addDocument(std::shared_ptr<Document> doc);
    std::optional<std::shared_ptr<Document>> findByName(const std::string &name);
    void printAll() const;
};
