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

        virtual Json& operator=(const Json& source) = 0;
        virtual Json& operator=(Json&& source) = 0;
        virtual ~Json() = default;

        virtual std::string to_string(int indent = -1) const = 0;
        
        // array
        virtual const JSON_TYPE& operator[](size_t index) const = 0;
        virtual JSON_TYPE& operator[](size_t) = 0;
        virtual void push(JSON_TYPE&& value) = 0;
        virtual void insert(size_t index, JSON_TYPE&& value) = 0;
        virtual void erase(size_t index) = 0;
        virtual const JSON_TYPE& at(size_t index) const = 0;
        virtual JSON_TYPE& at(size_t index) = 0;
        virtual const JSON_TYPE& front() const = 0;
        virtual JSON_TYPE& front() = 0;
        virtual const JSON_TYPE& back() const = 0;
        virtual JSON_TYPE& back() = 0;

        // object
        virtual const JSON_TYPE& operator[](const std::string& key) const = 0;
        virtual JSON_TYPE& operator[](const std::string& key) = 0;
        virtual const JSON_TYPE& operator[](const char* key) const = 0;
        virtual JSON_TYPE& operator[](const char* key) = 0;

        virtual void insert(const std::string& key, JSON_TYPE&& value) = 0;
        virtual bool contains(const std::string& key) const = 0;
        virtual void erase(const std::string& key) = 0;
        virtual const JSON_TYPE& at(const std::string& key) const = 0;
        virtual JSON_TYPE& at(const std::string& key) = 0;

        // both array and object
        virtual void clear() = 0;
        virtual size_t size() const = 0;
        virtual bool empty() const = 0;

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

std::ostream& operator<<(std::ostream& os, const ccjson::Json& json);

#endif // JSON_H
