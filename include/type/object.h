#ifndef OBJECT_H
#define OBJECT_H

#include "json.h"
#include <memory>

namespace ccjson {
    class Object : public Json {
    public:
        Object();
        Object(const JSON_OBJECT& value);
        Object(const Object& source);
        Object(Object&& source);
        Object& operator=(const Object& source);
        Object& operator=(Object&& source);
        virtual ~Object() = default;

        virtual std::string to_string(int indent = -1) const override;

        virtual const Json& operator[](const std::string& key) const override {
            return *value_.at(key);
        }
        virtual const Json& operator[](const char* key) const override {
            return *value_.at(key);
        }
        virtual const Json& operator[](size_t index) const override {
            throw std::runtime_error("Cannot use int as object key");
        }

        virtual Json& operator[](const std::string& key) override {
            return *value_.at(key);
        }
        virtual Json& operator[](const char* key) override {
            return *value_.at(key);
        }
        virtual Json& operator[](size_t index) override {
            throw std::runtime_error("Cannot use int as object key");
        }

        virtual Json& operator=(const Json& source) override;
        virtual Json& operator=(Json&& other) override;

        virtual const JSON_ARRAY& get_array() const override {
            throw std::runtime_error("Cannot convert object to array");
        }
        virtual const JSON_OBJECT& get_object() const override {
            return value_;
        }
        virtual JSON_FLOAT get_float() const override {
            throw std::runtime_error("Cannot convert object to float");
        }
        virtual JSON_INT get_int() const override {
            throw std::runtime_error("Cannot convert object to int");
        }
        virtual JSON_STRING get_string() const override {
            throw std::runtime_error("Cannot convert object to string");
        }
        virtual JSON_BOOL get_bool() const override {
            throw std::runtime_error("Cannot convert object to boolean");
        }

        virtual JSON_ARRAY& get_array() override {
            throw std::runtime_error("Cannot convert object to array");
        }
        virtual JSON_OBJECT& get_object() override {
            return value_;
        }
        virtual JSON_FLOAT& get_float() override {
            throw std::runtime_error("Cannot convert object to float");
        }
        virtual JSON_INT& get_int() override {
            throw std::runtime_error("Cannot convert object to int");
        }
        virtual JSON_STRING& get_string() override {
            throw std::runtime_error("Cannot convert object to string");
        }
        virtual JSON_BOOL& get_bool() override {
            throw std::runtime_error("Cannot convert object to boolean");
        }
    private:
        JSON_OBJECT value_;
    };
} // namespace ccjson

#endif // OBJECT_H
