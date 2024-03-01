#include "array.h"

using namespace ccjson;

Array::Array() {}
Array::Array(const JSON_ARRAY& value) : value_(value) {}
Array::Array(const Array& source) {
    value_ = source.value_;
}
Array::Array(Array&& source) {
    value_ = std::move(source.value_);
}

Array& Array::operator=(const Array& source) {
    value_ = source.value_;
    return *this;
}

Array& Array::operator=(Array&& source) {
    value_ = std::move(source.value_);
    return *this;
}

std::string Array::to_string(int indent) const {
    std::string result{"["};
    for(auto& value : value_) {
        result += value->to_string(indent);
        result += ",";
    }
    result += "]";
    return result;
}

Json& Array::operator=(const Json& source) {
    try {
        const Array& source_array = dynamic_cast<const Array&>(source);
        value_ = source_array.value_;
    } catch(const std::bad_cast& e) {
        throw std::runtime_error("Cannot assign a non-array value to an array");
    }
    return *this;
}

Json& Array::operator=(Json&& source) {
    try {
        Array& source_array = dynamic_cast<Array&>(source);
        value_ = std::move(source_array.value_);
    } catch(const std::bad_cast& e) {
        throw std::runtime_error("Cannot assign a non-array value to an array");
    }
    return *this;
}
