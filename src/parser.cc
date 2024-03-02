#include "parser.h"

using namespace ccjson;

Parser::Error::Error(size_t line, size_t column, const std::string& message) : message_("parse error at line " + std::to_string(line) + ", column " + std::to_string(column) + ": " + message) {}

const char* Parser::Error::what() const noexcept {
    return message_.c_str();
}

Parser::Parser(const std::string& str) : line_(1), column_(1), index_(0) {
    str_ = str;
}

Parser::Parser(std::ifstream& ifs) : line_(1), column_(1), index_(0) {
    std::string line;
    while(std::getline(ifs, line)) {
        str_ += line;
        str_ += '\n';
    }
}

Json Parser::parse() {
    skip();
    if(index_ >= str_.size()) {
        throw Error(line_, column_, "unexpected end of file");
    }
    if(str_[index_] == '"') {
        return parse_string();
    } else if(str_[index_] == '-' || (str_[index_] >= '0' && str_[index_] <= '9')) {
        std::string sub = str_.substr(index_);
        if(sub.substr(0, sub.find(',') - 1).find('.') != std::string::npos) {
            return parse_float();
        } else {
            return parse_int();
        }
    } else if(str_.substr(index_).find("true") == 0 || str_.substr(index_).find("false") == 0) {
        return parse_bool();
    } else if(str_.substr(index_).find("null") == 0) {
        return parse_null();
    } else if(str_[index_] == '[') {
        return parse_array();
    } else if(str_[index_] == '{') {
        return parse_object();
    } else {
        throw Error(line_, column_, "unexpected data type");
    }
}

void Parser::skip() {
    for(; index_ < str_.size() && (str_[index_] == ' ' || str_[index_] == '\t' || str_[index_] == '\n' || str_[index_] == '\r'); ++index_) {
        if(str_[index_] == '\n') {
            ++line_;
            column_ = 1;
        } else {
            ++column_;
        }
    }
}

JSON_STRING Parser::parse_string() {
    std::string result;
    for(index_++; index_ < str_.size() && str_[index_] != '"'; ++index_, ++column_) {
        if(str_[index_] == '\\') {
            throw Error(line_, column_, "escape characters are not supported yet");
        } else if(str_[index_] == '\n') {
            throw Error(line_, column_, "unexpected end of line");
        } else {
            result += str_[index_];
        }
    }
    if(index_ >= str_.size()) {
        throw Error(line_, column_, "unexpected end of file");
    }
    ++index_;
    ++column_;
    return result;
}

JSON_INT Parser::parse_int() {
    std::istringstream iss(str_.substr(index_));
    JSON_INT result;
    if(!(iss >> result)) {
        throw Error(line_, column_, "invalid integer");
    }
    index_ += iss.tellg();
    column_ += iss.tellg();
    return result;
}

JSON_FLOAT Parser::parse_float() {
    std::istringstream iss(str_.substr(index_));
    JSON_FLOAT result;
    if(!(iss >> result)) {
        throw Error(line_, column_, "invalid float");
    }
    index_ += iss.tellg();
    column_ += iss.tellg();
    return result;
}

JSON_BOOL Parser::parse_bool() {
    if(str_.substr(index_, 4) == "true") {
        index_ += 4;
        column_ += 4;
        return true;
    } else if(str_.substr(index_, 5) == "false") {
        index_ += 5;
        column_ += 5;
        return false;
    } else {
        throw Error(line_, column_, "invalid boolean");
    }
}

std::nullptr_t Parser::parse_null() {
    if(str_.substr(index_, 4) == "null") {
        index_ += 4;
        column_ += 4;
        return nullptr;
    } else {
        throw Error(line_, column_, "invalid null");
    }
}

JSON_ARRAY Parser::parse_array() {
    JSON_ARRAY result;
    ++index_;
    ++column_;
    skip();
    if(index_ >= str_.size()) {
        throw Error(line_, column_, "unexpected end of file");
    }
    if(str_[index_] == ']') {
        ++index_;
        ++column_;
        return result;
    }
    while(true) {
        result.push_back(parse());
        skip();
        if(index_ >= str_.size()) {
            throw Error(line_, column_, "unexpected end of file");
        }
        if(str_[index_] == ']') {
            ++index_;
            ++column_;
            break;
        } else if(str_[index_] == ',') {
            ++index_;
            ++column_;
            skip();
            if(index_ >= str_.size()) {
                throw Error(line_, column_, "unexpected end of file");
            }
            if(str_[index_] == ']') {
                throw Error(line_, column_, "expected value after ','");
            }
        } else {
            throw Error(line_, column_, "expected ',' or ']'");
        }
    }
    return result;
}

JSON_OBJECT Parser::parse_object() {
    JSON_OBJECT result;
    ++index_;
    ++column_;
    skip();
    if(index_ >= str_.size()) {
        throw Error(line_, column_, "unexpected end of file");
    }
    if(str_[index_] == '}') {
        ++index_;
        ++column_;
        return result;
    }
    while(true) {
        if(str_[index_] != '"') {
            throw Error(line_, column_, "expected '\"'");
        }
        JSON_STRING key = parse_string();
        skip();
        if(index_ >= str_.size()) {
            throw Error(line_, column_, "unexpected end of file");
        }
        if(str_[index_] != ':') {
            throw Error(line_, column_, "expected ':'");
        }
        ++index_;
        ++column_;
        skip();
        result[key] = parse();
        skip();
        if(index_ >= str_.size()) {
            throw Error(line_, column_, "unexpected end of file");
        }
        if(str_[index_] == '}') {
            ++index_;
            ++column_;
            break;
        } else if(str_[index_] == ',') {
            ++index_;
            ++column_;
            skip();
            if(index_ >= str_.size()) {
                throw Error(line_, column_, "unexpected end of file");
            }
            if(str_[index_] == '}') {
                throw Error(line_, column_, "expected value after ','");
            }
        } else {
            throw Error(line_, column_, "expected ',' or '}'");
        }
    }
    return result;
}
