#include "string.h"

using namespace ccjson;

String::String() {}
String::String(const JSON_STRING& value) : value_(value) {}
String::String(const String& source) {
    value_ = source.value_;
}
String::String(String&& source) {
    value_ = std::move(source.value_);
}
String& String::operator=(const String& source) {
    value_ = source.value_;
    return *this;
}
String& String::operator=(String&& source) {
    value_ = std::move(source.value_);
    return *this;
}

std::string String::to_string(int indent) const {
    return "\"" + value_ + "\"";
}

Json& String::operator=(const Json& source) {
    try {
        const String& source_string = dynamic_cast<const String&>(source);
        value_ = source_string.value_;
    } catch(const std::bad_cast& e) {
        throw std::runtime_error("Cannot assign a non-string value to a string");
    }
    return *this;
}

Json& String::operator=(Json&& source) {
    try {
        String& source_string = dynamic_cast<String&>(source);
        value_ = std::move(source_string.value_);
    } catch(const std::bad_cast& e) {
        throw std::runtime_error("Cannot assign a non-string value to a string");
    }
    return *this;
}
