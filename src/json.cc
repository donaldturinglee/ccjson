#include "json.h"
#include "array.h"
#include "object.h"
#include "bool.h"
#include "float.h"
#include "int.h"
#include "string.h"
#include "null.h"

using namespace ccjson;

Json::Error::Error(const std::string& message) : message_() {}

const char* Json::Error::what() const noexcept {
    return message_.c_str();
}

JsonPtr::JsonPtr() : value_(std::make_unique<Null>()) {}
JsonPtr::JsonPtr(JsonPtr&& source) : value_(std::move(source.value_)) {}
JsonPtr::JsonPtr(std::unique_ptr<Json>&& value) : value_(std::move(value)) {}

JsonPtr::JsonPtr(Array&& value) : value_(std::make_unique<Array>(std::move(value))) {}
JsonPtr::JsonPtr(Object&& value) : value_(std::make_unique<Object>(std::move(value))) {}
JsonPtr::JsonPtr(Bool&& value) : value_(std::make_unique<Bool>(std::move(value))) {}
JsonPtr::JsonPtr(Float&& value) : value_(std::make_unique<Float>(std::move(value))) {}
JsonPtr::JsonPtr(Int&& value) : value_(std::make_unique<Int>(std::move(value))) {}
JsonPtr::JsonPtr(String&& value) : value_(std::make_unique<String>(std::move(value))) {}

JsonPtr::JsonPtr(JSON_ARRAY&& value) : value_(std::make_unique<Array>(std::move(value))) {}
JsonPtr::JsonPtr(JSON_OBJECT&& value) : value_(std::make_unique<Object>(std::move(value))) {}
JsonPtr::JsonPtr(JSON_BOOL value) : value_(std::make_unique<Bool>(value)) {}
JsonPtr::JsonPtr(JSON_FLOAT value) : value_(std::make_unique<Float>(value)) {}
JsonPtr::JsonPtr(JSON_INT value) : value_(std::make_unique<Int>(value)) {}
JsonPtr::JsonPtr(JSON_STRING value) : value_(std::make_unique<String>(value)) {}
JsonPtr::JsonPtr(const char* value) : value_(value == nullptr ? static_cast<std::unique_ptr<Json>>(std::make_unique<Null>()) : std::make_unique<String>(value)) {}

JsonPtr& JsonPtr::operator=(JsonPtr&& source) {
    value_ = std::move(source.value_);
    return *this;
}

JsonPtr& JsonPtr::operator=(std::unique_ptr<Json>&& value) {
    value_ = std::move(value);
    return *this;
}

JsonPtr& JsonPtr::operator=(Array&& value) {
    value_ = std::make_unique<Array>(std::move(value));
    return *this;
}

JsonPtr& JsonPtr::operator=(Object&& value) {
    value_ = std::make_unique<Object>(std::move(value));
    return *this;
}

JsonPtr& JsonPtr::operator=(Bool&& value) {
    value_ = std::make_unique<Bool>(std::move(value));
    return *this;
}

JsonPtr& JsonPtr::operator=(Float&& value) {
    value_ = std::make_unique<Float>(std::move(value));
    return *this;
}

JsonPtr& JsonPtr::operator=(Int&& value) {
    value_ = std::make_unique<Int>(std::move(value));
    return *this;
}

JsonPtr& JsonPtr::operator=(String&& value) {
    value_ = std::make_unique<String>(std::move(value));
    return *this;
}

JsonPtr& JsonPtr::operator=(JSON_ARRAY&& value) {
    value_ = std::make_unique<Array>(std::move(value));
    return *this;
}

JsonPtr& JsonPtr::operator=(JSON_OBJECT&& value) {
    value_ = std::make_unique<Object>(std::move(value));
    return *this;
}

JsonPtr& JsonPtr::operator=(JSON_BOOL value) {
    value_ = std::make_unique<Bool>(value);
    return *this;
}

JsonPtr& JsonPtr::operator=(JSON_FLOAT value) {
    value_ = std::make_unique<Float>(value);
    return *this;
}

JsonPtr& JsonPtr::operator=(JSON_INT value) {
    value_ = std::make_unique<Int>(value);
    return *this;
}

JsonPtr& JsonPtr::operator=(JSON_STRING value) {
    value_ = std::make_unique<String>(value);
    return *this;
}

JsonPtr& JsonPtr::operator=(const char* value) {
    if(value == nullptr) {
        value_ = std::make_unique<Null>();
    } else {
        value_ = std::make_unique<String>(value);
    }
    return *this;
}


std::ostream& operator<<(std::ostream& os, const ccjson::Json& json) {
    return os << json.to_string();
}

std::ostream& operator<<(std::ostream& os, const ccjson::JsonPtr& json) {
    return os << json.to_string();
}
