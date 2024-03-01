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

std::string Object::to_string(int indent) const {
    std::string result = "{";
    for(auto& value : value_) {
        result += value.first + ": " + value.second->to_string(indent) + ", ";
    }
    result += "}";
    return result;
}

Json& Object::operator=(const Json& source) {
    throw std::runtime_error("Cannot copy an object");
}

Json& Object::operator=(Json&& source) {
    try {
        Object& source_object = dynamic_cast<Object&>(source);
        value_ = std::move(source_object.value_);
    } catch(const std::bad_cast& e) {
        throw std::runtime_error("Cannot assign a non-object value to an object");
    }
    return *this;
}
