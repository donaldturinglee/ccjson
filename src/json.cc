#include "json.h"

using namespace ccjson;

Json::Error::Error(const std::string& message) : message_() {}

const char* Json::Error::what() const noexcept {
    return message_.c_str();
}

JsonPtr::JsonPtr() : value_(nullptr) {}
JsonPtr::JsonPtr(JsonPtr&& source) : value_(std::move(source.value_)) {}
JsonPtr::JsonPtr(std::unique_ptr<Json>&& value) : value_(std::move(value)) {}
JsonPtr& JsonPtr::operator=(JsonPtr&& source) {
    value_ = std::move(source.value_);
    return *this;
}

JsonPtr& JsonPtr::operator=(std::unique_ptr<Json>&& value) {
    value_ = std::move(value);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ccjson::Json& json) {
    return os << json.to_string();
}

std::ostream& operator<<(std::ostream& os, const ccjson::JsonPtr& json) {
    return os << json.to_string();
}
