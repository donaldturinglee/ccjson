#include "array.h"

using namespace ccjson;

Array::Array() {}
Array::Array(JSON_ARRAY&& value) : value_(std::move(value)) {}
Array::Array(Array&& source) {
    value_ = std::move(source.value_);
}

Array& Array::operator=(Array&& source) {
    value_ = std::move(source.value_);
    return *this;
}

std::string Array::to_string(int indent, int base_indent) const {
    std::string result = "[";
    for(auto it = value_.begin(); it != value_.end(); ++it) {
        if(it != value_.begin()) {
            result += ",";
        }
        if(indent > 0) {
            result += "\n";
            result += std::string(indent, ' ');
        }
        result += it->to_string(indent + base_indent, base_indent);
    }
    if(indent > 0) {
        result += "\n";
        result += std::string(indent - base_indent, ' ');
    }
    result += "]";
    return result;
}
