#include "Document.hpp"
#include <iostream>

// TODO: Implement constructor from string (copy)

// TODO: Implement constructor from string& (view)

// TODO: Implement constructor from unique_ptr (ownership)

const std::string& Document::getName() const {
    return name;
}

std::string_view Document::getView() const {
    // TODO: Return owned content if available, otherwise view
    return {};
}

void Document::updateContent(const std::string& newContent) {
    // TODO: Update only if content is owned (unique_ptr not null)
}
