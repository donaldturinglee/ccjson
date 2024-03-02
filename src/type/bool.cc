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

std::string Bool::to_string(int indent) const {
    return value_ ? "true" : "false";
}

Json& Bool::operator=(const Json& source) {
    try {
        const Bool& source_bool = dynamic_cast<const Bool&>(source);
        value_ = source_bool.value_;
    } catch(const std::bad_cast& e) {
        throw std::runtime_error("Cannot assign a non-bool value to a boolean");
    }
    return *this;
}

Json& Bool::operator=(Json&& source) {
    try {
        Bool& source_bool = dynamic_cast<Bool&>(source);
        value_ = std::move(source_bool.value_);
    } catch(const std::bad_cast& e) {
        throw std::runtime_error("Cannot assign a non-bool value to a boolean");
    }
    return *this;
}
