#include "bool.h"

using namespace ccjson;

Bool::Bool() : value_(false) {}
Bool::Bool(JSON_BOOL value) : value_(value) {}
Bool::Bool(const Bool& source) {
    value_ = source.value_;
}
Bool::Bool(Bool&& source) {
    value_ = std::move(source.value_);
}

Bool& Bool::operator=(const Bool& source) {
    value_ = source.value_;
    return *this;
}

Bool& Bool::operator=(Bool&& source) {
    value_ = std::move(source.value_);
    return *this;
}

std::string Bool::to_string(int indent, int base_indent) const {
    return value_ ? "true" : "false";
}
