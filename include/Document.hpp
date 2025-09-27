#pragma once
#include <string>
#include <string_view>
#include <memory>

class Document {
    std::string name;
    std::unique_ptr<std::string> content;
    std::string_view view;

public:
    // TODO: Implement constructors
    // 1. From string (copy content)
    // 2. From external string& as view
    // 3. From unique_ptr for exclusive ownership

    const std::string& getName() const;

    // Return either owned string content or view
    std::string_view getView() const;

    // TODO: Update content (only if we have ownership)
    void updateContent(const std::string& newContent);
};
