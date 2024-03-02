#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "json.h"

namespace ccjson {
    
    class Parser {
    public:
        class Error : public std::exception {
        public:
            Error(size_t line, size_t column, const std::string& message);
            virtual const char* what() const noexcept override;
        protected:
            std::string message_;
        };
        
        Parser(const std::string& str);
        Parser(std::ifstream& ifs);
        ~Parser() = default;

        JsonPtr parse();

    private:
        std::string str_;
        size_t line_;
        size_t column_;
        size_t index_;

        void skip();
        JSON_STRING parse_string();
        JSON_INT parse_int();
        JSON_FLOAT parse_float();
        JSON_BOOL parse_bool();
        std::nullptr_t parse_null();
        JSON_ARRAY parse_array();
        JSON_OBJECT parse_object();
    };

} // namespace ccjson

#endif // PARSER_H
