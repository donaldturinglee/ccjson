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

std::string Float::to_string(int indent, int base_indent) const {
    return std::to_string(value_);
}
