#ifndef JSON_H
#define JSON_H

#include "type.h"

namespace ccjson {
    class Json {
    public:
        class Error : public std::exception {
        public:
            Error(const std::string& message);
            virtual const char* what() const noexcept override;
        protected:
            std::string message_;
        };

        virtual ~Json() = default;
        virtual std::string to_string(int indent = -1) const = 0;
        virtual const Json& operator[](const std::string& key) const = 0;
        virtual const Json& operator[](const char* key) const = 0;
        virtual const Json& operator[](size_t index) const = 0;

        virtual Json& operator[](const std::string& key) = 0;
        virtual Json& operator[](const char* key) = 0;
        virtual Json& operator[](size_t index) = 0;

        virtual Json& operator=(const Json& source) = 0;
        virtual Json& operator=(Json&& source) = 0;

        virtual const JSON_ARRAY& get_array() const = 0;
        virtual const JSON_OBJECT& get_object() const = 0;
        virtual JSON_FLOAT get_float() const = 0;
        virtual JSON_INT get_int() const = 0;
        virtual JSON_STRING get_string() const = 0;
        virtual JSON_BOOL get_bool() const = 0;

        virtual JSON_ARRAY& get_array() = 0;
        virtual JSON_OBJECT& get_object() = 0;
        virtual JSON_FLOAT& get_float() = 0;
        virtual JSON_INT& get_int() = 0;
        virtual JSON_STRING& get_string() = 0;
        virtual JSON_BOOL& get_bool() = 0;
    };
} // namespace ccjson

#endif // JSON_H
