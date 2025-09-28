#pragma once
#include <string>
#include <string_view>
#include <memory>
#include <iostream>

class Document {
    std::string name;
    std::unique_ptr<std::string> content; // owned content
    std::string_view view;                // view content

public:
    // Constructors
    Document(const std::string& n, const std::string& text);            // copy
    Document(const std::string& n, const std::string& external, bool viewOnly); // view
    Document(const std::string& n, std::unique_ptr<std::string> ptr);   // ownership

    const std::string& getName() const;
    std::string_view getView() const;
    void updateContent(const std::string& newContent);
};
