#include "Document.hpp"

// Constructor: copy content
Document::Document(const std::string& n, const std::string& text)
    : name(n), content(std::make_unique<std::string>(text)), view(*content) {}

// Constructor: view-only
Document::Document(const std::string& n, const std::string& external, bool)
    : name(n), content(nullptr), view(external) {}

// Constructor: unique_ptr ownership
Document::Document(const std::string& n, std::unique_ptr<std::string> ptr)
    : name(n), content(std::move(ptr)), view(*content) {}

const std::string& Document::getName() const {
    return name;
}

std::string_view Document::getView() const {
    if (content) return *content;
    return view;
}

void Document::updateContent(const std::string& newContent) {
    if (content) {
        *content = newContent;
        view = *content;
    } else {
        std::cerr << "Cannot update content: Document is view-only\n";
    }
}
