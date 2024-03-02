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
