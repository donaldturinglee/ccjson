#include "object.h"

using namespace ccjson;

Object::Object() {}
Object::Object(const JSON_OBJECT& value) : value_(value) {}
Object::Object(const Object& source) {
    value_ = source.value_;
}
Object::Object(Object&& source) {
    value_ = std::move(source.value_);
}

Object& Object::operator=(const Object& source) {
    value_ = source.value_;
    return *this;
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
    try {
        const Object& source_object = dynamic_cast<const Object&>(source);
        value_ = source_object.value_;
    } catch(const std::bad_cast& e) {
        throw std::runtime_error("Cannot assign a non-object value to an object");
    }
    return *this;
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
