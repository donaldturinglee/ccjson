#include "json.h"

using namespace ccjson;

Json::Error::Error(const std::string& message) : message_() {}

const char* Json::Error::what() const noexcept {
    return message_.c_str();
}

std::ostream& operator<<(std::ostream& os, const ccjson::Json& json) {
    return os << json.to_string();
}
