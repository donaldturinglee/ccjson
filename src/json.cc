#include "json.h"
#include "array.h"
#include "object.h"
#include "bool.h"
#include "float.h"
#include "int.h"
#include "string.h"
#include "null.h"
#include "parser.h"

using namespace ccjson;

JsonBase::Error::Error(const std::string& message) : message_() {}

const char* JsonBase::Error::what() const noexcept {
    return message_.c_str();
}

Json::Json() : value_(std::make_unique<Null>()) {}
Json::Json(Json&& source) : value_(std::move(source.value_)) {}
Json::Json(std::unique_ptr<JsonBase>&& value) : value_(std::move(value)) {}

Json::Json(Array&& value) : value_(std::make_unique<Array>(std::move(value))) {}
Json::Json(Object&& value) : value_(std::make_unique<Object>(std::move(value))) {}
Json::Json(Bool&& value) : value_(std::make_unique<Bool>(std::move(value))) {}
Json::Json(Float&& value) : value_(std::make_unique<Float>(std::move(value))) {}
Json::Json(Int&& value) : value_(std::make_unique<Int>(std::move(value))) {}
Json::Json(String&& value) : value_(std::make_unique<String>(std::move(value))) {}

Json::Json(JSON_ARRAY&& value) : value_(std::make_unique<Array>(std::move(value))) {}
Json::Json(JSON_OBJECT&& value) : value_(std::make_unique<Object>(std::move(value))) {}
Json::Json(JSON_BOOL value) : value_(std::make_unique<Bool>(value)) {}
Json::Json(JSON_FLOAT value) : value_(std::make_unique<Float>(value)) {}
Json::Json(JSON_INT value) : value_(std::make_unique<Int>(value)) {}
Json::Json(JSON_STRING value) : value_(std::make_unique<String>(value)) {}
Json::Json(const char* value) : value_(value == nullptr ? static_cast<std::unique_ptr<JsonBase>>(std::make_unique<Null>()) : std::make_unique<String>(value)) {}

Json& Json::operator=(Json&& source) {
    value_ = std::move(source.value_);
    return *this;
}

Json& Json::operator=(std::unique_ptr<JsonBase>&& value) {
    value_ = std::move(value);
    return *this;
}

Json& Json::operator=(Array&& value) {
    value_ = std::make_unique<Array>(std::move(value));
    return *this;
}

Json& Json::operator=(Object&& value) {
    value_ = std::make_unique<Object>(std::move(value));
    return *this;
}

Json& Json::operator=(Bool&& value) {
    value_ = std::make_unique<Bool>(std::move(value));
    return *this;
}

Json& Json::operator=(Float&& value) {
    value_ = std::make_unique<Float>(std::move(value));
    return *this;
}

Json& Json::operator=(Int&& value) {
    value_ = std::make_unique<Int>(std::move(value));
    return *this;
}

Json& Json::operator=(String&& value) {
    value_ = std::make_unique<String>(std::move(value));
    return *this;
}

Json& Json::operator=(JSON_ARRAY&& value) {
    value_ = std::make_unique<Array>(std::move(value));
    return *this;
}

Json& Json::operator=(JSON_OBJECT&& value) {
    value_ = std::make_unique<Object>(std::move(value));
    return *this;
}

Json& Json::operator=(JSON_BOOL value) {
    value_ = std::make_unique<Bool>(value);
    return *this;
}

Json& Json::operator=(JSON_FLOAT value) {
    value_ = std::make_unique<Float>(value);
    return *this;
}

Json& Json::operator=(JSON_INT value) {
    value_ = std::make_unique<Int>(value);
    return *this;
}

Json& Json::operator=(JSON_STRING value) {
    value_ = std::make_unique<String>(value);
    return *this;
}

Json& Json::operator=(const char* value) {
    if(value == nullptr) {
        value_ = std::make_unique<Null>();
    } else {
        value_ = std::make_unique<String>(value);
    }
    return *this;
}

std::string Json::to_string(int indent, int base_indent) const {
    if(indent > 0 && base_indent == 0) {
        base_indent = indent;
    }
    return value_->to_string(indent, base_indent);
}

Json::operator Array&() {
    return dynamic_cast<Array&>(*this->value_);
}

Json::operator Object&() {
    return dynamic_cast<Object&>(*this->value_);
}

Json::operator Bool&() {
    return dynamic_cast<Bool&>(*this->value_);
}

Json::operator Float&() {
    return dynamic_cast<Float&>(*this->value_);
}

Json::operator Int&() {
    return dynamic_cast<Int&>(*this->value_);
}

Json::operator String&() {
    return dynamic_cast<String&>(*this->value_);
}

Json::operator Null&() {
    return dynamic_cast<Null&>(*this->value_);
}


Json Json::parse(const std::string& str) {
    Parser parser(str);
    return parser.parse();
}

Json Json::parse(std::ifstream& is) {
    Parser parser(is);
    return parser.parse();
}

std::ostream& operator<<(std::ostream& os, const ccjson::JsonBase& json) {
    return os << json.to_string();
}

std::ostream& operator<<(std::ostream& os, const ccjson::Json& json) {
    return os << json.to_string();
}
