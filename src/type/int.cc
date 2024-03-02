#include "int.h"

using namespace ccjson;

Int::Int() : value_(0) {}
Int::Int(JSON_INT value) : value_(value) {}
Int::Int(const Int& source) {
    value_ = source.value_;
}
Int::Int(Int&& source) {
    value_ = std::move(source.value_);
}

Int& Int::operator=(const Int& other) {
    value_ = other.value_;
    return *this;
}

Int& Int::operator=(Int&& other) {
    value_ = std::move(other.value_);
    return *this;
}

std::string Int::to_string(int indent, int base_indent) const {
    return std::to_string(value_);
}
