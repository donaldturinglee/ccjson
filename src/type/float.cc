#include "float.h"

using namespace ccjson;

Float::Float() : value_(0.0f) {}
Float::Float(JSON_FLOAT value) : value_(value) {}
Float::Float(const Float& source) {
    value_ = source.value_;
}
Float::Float(Float&& source) {
    value_ = std::move(source.value_);
}

Float& Float::operator=(const Float& source){
    value_ = source.value_;
    return *this;
}

Float& Float::operator=(Float&& source) {
    value_ = std::move(source.value_);
    return *this;
}

std::string Float::to_string(int indent) const {
    return std::to_string(value_);
}

Json& Float::operator=(const Json& source) {
    try {
        const Float& source_float = dynamic_cast<const Float&>(source);
        value_ = source_float.value_;
    } catch(const std::bad_cast& e) {
        throw std::runtime_error("Cannot assign a non-float value to a float");
    }
    return *this;
}

Json& Float::operator=(Json&& source) {
    try {
        Float& source_float = dynamic_cast<Float&>(source);
        value_ = std::move(source_float.value_);
    } catch(const std::bad_cast& e) {
        throw std::runtime_error("Cannot assign a non-float value to a float");
    }
    return *this;
}
