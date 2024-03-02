#include "object.h"

using namespace ccjson;

Object::Object() {}
Object::Object(JSON_OBJECT&& value) : value_(std::move(value)) {}
Object::Object(Object&& source) {
    value_ = std::move(source.value_);
}

Object& Object::operator=(Object&& source) {
    value_ = std::move(source.value_);
    return *this;
}

std::string Object::to_string(int indent, int base_indent) const {
    std::string result = "{";
    for(auto it = value_.begin(); it != value_.end(); ++it) {
        if(it != value_.begin()) {
            result += ",";
        }
        if(indent > 0) {
            result += "\n";
            result += std::string(indent, ' ');
        }
        result += "\"" + it->first + "\":" + (indent > 0 ? " " : "");
        result += it->second.to_string(indent + base_indent, base_indent);
    }
    if(indent > 0) {
        result += "\n";
        result += std::string(indent - base_indent, ' ');
    }
    result += "}";
    return result;
}
