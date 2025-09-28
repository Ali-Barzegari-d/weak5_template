#include "Library.hpp"

void Library::addDocument(std::shared_ptr<Document> doc) {
    docs.push_back(std::move(doc));
}

std::optional<std::shared_ptr<Document>> Library::findByName(const std::string& name) {
    for (auto& doc : docs) {
        if (doc->getName() == name) {
            return doc;
        }
    }
    return std::nullopt;
}

void Library::printAll() const {
    for (const auto& doc : docs) {
        std::cout << doc->getName() << ": " << doc->getView() << "\n";
    }
}
